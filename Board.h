#pragma once
#include <vector>
#include <iostream>

class Card;

// Board can only be a square
class Board
{
public:
	Board();
	~Board();

	void initialize(int size);
	bool isFull() const;
	bool isEmpty(int row, int col) const {
		return m_squares[row][col] == nullptr;
	}
	int getSize() const { 
		return m_squares.size(); 
	}
	const Card* getCard(int row, int col) const {
		return m_squares[row][col];
	}
	void placeCard(Card* card, int row, int col) {
		m_squares[row][col] = card;
	}
	void emptySquare(int row, int col) {
		m_squares[row][col] = nullptr;
	}

private:
	std::vector<std::vector<const Card*>> m_squares; // nullptr value means that the square is empty
};

void printResult(const Board& board);
void printBoard(const Board& board);



