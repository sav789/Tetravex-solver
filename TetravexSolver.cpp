#include "TetravexSolver.h"
#include "Board.h"

TetravexSolver::TetravexSolver()
{
}

TetravexSolver::~TetravexSolver()
{
}

void TetravexSolver::initialize(int size)
{
	m_board.initialize(size);
	/*// testing:
	m_cards.emplace_back(-4, 1, -3, 2, 0);
	m_cards.emplace_back(-2, 4, 3, -2, 1);
	m_cards.emplace_back(-3, 1, -2, 4, 2);
	m_cards.emplace_back(3, 2, -1, -4, 3);
	m_cards.emplace_back(2, -1, 4, -3, 4);
	m_cards.emplace_back(-4, 1, 3, -2, 5);
	m_cards.emplace_back(-3, -2, 2, 1, 6);
	m_cards.emplace_back(-1, -4, 2, 3, 7);
	m_cards.emplace_back(-2, 1, 2, -1, 8);*/
}

bool TetravexSolver::checkValidity(int row, int col)
{
	if (m_board.getCard(row, col) == nullptr)
		return false;

	bool north{ true }, east{ true }, south{ true }, west{ true };

	if (row == 0)
	{
		north = false;
		if (col == 0)
			west = false;
		else if (col == m_board.getSize() - 1)
			east = false;
	}
	else if (col == m_board.getSize() - 1)
	{
		east = false;
		if (row == 0)
			north = false;
		else if (row == m_board.getSize() - 1)
			south = false;
	}
	else if (row == m_board.getSize() - 1)
	{
		south = false;
		if(col == m_board.getSize() - 1)
			east = false;
		else if(col == 0)
			west = false;
	}
	else if (col == 0)
	{
		west = false;
		if(row == 0)
			north = false;
		else if(row == m_board.getSize() - 1)
			south = false;
	}
	if (north)
	{
		if (!m_board.isEmpty(row - 1, col))
		{
			if (m_board.getCard(row, col)->get(Card::North) +
				m_board.getCard(row - 1, col)->get(Card::South) != 0)
			{
				return false;
			}
		}
	}
	if (east)
	{
		if (!m_board.isEmpty(row, col + 1))
		{
			if (m_board.getCard(row, col)->get(Card::East) +
				m_board.getCard(row, col + 1)->get(Card::West) != 0)
			{
				return false;
			}
		}
	}
	if (south)
	{
		if (!m_board.isEmpty(row + 1, col))
		{
			if (m_board.getCard(row, col)->get(Card::South) +
				m_board.getCard(row + 1, col)->get(Card::North) != 0)
			{
				return false;
			}
		}
	}
	if (west)
	{
		if (!m_board.isEmpty(row, col - 1))
		{
			if (m_board.getCard(row, col)->get(Card::West) +
				m_board.getCard(row, col - 1)->get(Card::East) != 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool TetravexSolver::findSolution(Board& board, unsigned int cardIndex)
{
	// ending condition: if the board is full it means all cards were placed succesfully
	// according to rules and thus the solution is found
	if (board.isFull())
		return true;

	// place card with index cardIndex in all possible ways to the remaining empty squares
	for (int rotationIndex = Card::Deg0; rotationIndex <= Card::Deg270; ++rotationIndex)
	{
		Card::RotationAngle rotation = static_cast<Card::RotationAngle>(rotationIndex);

		m_cards[cardIndex].rotate(rotation);
		int oldRow{ -1 }, oldCol{ -1 }; // negative value means: no old value
		const int boardSize = board.getSize();
		for (int row=0; row < boardSize; ++row)
		{
			for (int col=0; col < boardSize; ++col)
			{
				if (board.isEmpty(row, col))
				{
					// We are moving the card, so if the card was placed before on the board then 
					// first remove it and then place the card into the new square
					board.placeCard(&(m_cards[cardIndex]), row, col);
					oldRow = row;
					oldCol = col;

					// check whether this position is so far going towards the solution
					if (checkValidity(row, col))
					{
						if (findSolution(m_board, cardIndex + 1))
							return true;
					}
					// it failed so remove the card from the board
					board.emptySquare(oldRow, oldCol);
				}
			}
		}
	}

	return false;
}

bool TetravexSolver::findSolution()
{
	return findSolution(m_board, 0);
}

void TetravexSolver::printResult()
{
	::printResult(m_board);
}
