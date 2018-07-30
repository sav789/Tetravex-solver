#pragma once
#include <array>


class Card
{
public:
	enum RotationAngle { Deg0=0, Deg90, Deg180, Deg270 }; // do not change these, as indexes needs to be in this order
	enum Side { North=0, East, South, West, NullSide }; // do not change these, as indexes needs to be in this order

	Card(int north, int east, int south, int west, int ID);
	~Card();

	int get(Side side) const {
		return m_data[m_rotation][side];
	}
	void rotate(RotationAngle angle) { 
		m_rotation = angle; 
	}
	int getID() const { return m_ID; }

private:
	RotationAngle m_rotation{ Deg0 };
	int m_ID;
	// usage: m_data[Deg90][South] returns cards south value after rotating the card 90 degrees 
	// clockwise
	std::array<std::array<int, 4>, 4> m_data; 
};

