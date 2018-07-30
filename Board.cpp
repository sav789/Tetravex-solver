#include "Board.h"
#include "Card.h"


void printResult(const Board& board)
{
	const int size = board.getSize();
	for (int row = 0; row < size; ++row)
	{
		for (int col = 0; col < size; ++col)
		{
			if (board.isEmpty(row, col))
				std::cout << "****************";
			else
			{
				std::cout << board.getCard(row, col)->getID() << " ";
				std::cout << board.getCard(row, col)->get(Card::North) << " ";
				std::cout << board.getCard(row, col)->get(Card::East) << " ";
				std::cout << board.getCard(row, col)->get(Card::South) << " ";
				std::cout << board.getCard(row, col)->get(Card::West);
			}
			std::cout << "\n";
		}
	}
}

void printBoard(const Board& board)
{
	const int size = board.getSize();
	for (int row = 0; row < size; ++row)
	{
		for (int col = 0; col < size; ++col)
		{
			if(board.isEmpty(row, col))
				std::cout << "****************";
			else
			{
				std::cout << board.getCard(row, col)->getID() << " ";
				std::cout << board.getCard(row, col)->get(Card::North) << " ";
				std::cout << board.getCard(row, col)->get(Card::East) << " ";
				std::cout << board.getCard(row, col)->get(Card::South) << " ";
				std::cout << board.getCard(row, col)->get(Card::West);
				
			}
			std::cout << "         ";
		}
		std::cout << "\n";
	}
}

Board::Board()
{
}


Board::~Board()
{
}

void Board::initialize(int size)
{
	m_squares.resize(size);
	for (auto& square : m_squares)
	{
		square.resize(size);
		square.assign(size, nullptr);
	}
}

bool Board::isFull() const
{
	for (auto& row : m_squares)
	{
		for (auto& square : row)
		{
			if (square == nullptr)
				return false;
		}
	}

	return true;
}
