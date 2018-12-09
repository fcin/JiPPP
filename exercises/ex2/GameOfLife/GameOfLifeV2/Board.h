#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board
{
private:
	int** m_Cells;

public:
	Board();
	const int At(unsigned int row, unsigned col) const;
	void Set(unsigned int row, unsigned int col, int value);
	int GetNeighbourCount(unsigned int row, unsigned col);
};

#endif
