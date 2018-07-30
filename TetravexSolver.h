#pragma once
#include <vector>
#include "Board.h"
#include "Card.h"

class TetravexSolver
{
public:
	TetravexSolver();
	~TetravexSolver();

	void initialize(int size);
	bool findSolution();
	void printResult();
	// void readFile();

private:
	bool checkValidity(int row, int col);
	bool findSolution(Board& board, unsigned int cardIndex);
	Board m_board;
	std::vector<Card> m_cards;

};



