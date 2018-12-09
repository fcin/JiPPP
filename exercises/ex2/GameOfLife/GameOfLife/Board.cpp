#include "Board.h"

Board::Board()
{
	m_Cells = new int[16 * 16];
	for (size_t index = 0; index < 16 * 16; index++)
		m_Cells[index] = 0;
}

int * Board::GetCells() const
{
	return m_Cells;
}

unsigned int Board::GetNeighbour(unsigned int x, unsigned int y, int offsetX, int offsetY) const
{
	int resultX = -1;
	if ((x + offsetX) < 0)
		resultX = 16 + offsetX;
	else if ((x + offsetX) > 15)
		resultX = offsetX - 1;
	else
		resultX = x + offsetX;

	int resultY = -1;
	if ((y + offsetY) < 0)
		resultY = 16 + offsetY;
	else if ((y + offsetY) > 15)
		resultY = offsetY - 1;
	else
		resultY = y + offsetY;

	return m_Cells[resultY * 16 + resultX];
}


