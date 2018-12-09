#include "Board.h"

Board::Board()
{
	m_Cells = new int*[16];
	for (size_t index = 0; index < 16; index++)
		m_Cells[index] = new int[16];
}

const int Board::At(unsigned int x, unsigned y) const
{
	return m_Cells[x][y];
}

void Board::Set(unsigned int x, unsigned y, int value)
{
	m_Cells[x][y] = value;
}
