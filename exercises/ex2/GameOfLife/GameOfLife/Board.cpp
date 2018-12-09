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

// Returns index
unsigned int Board::GetNeighbour(unsigned int x, unsigned int y, int offsetX, int offsetY) const
{
	int resultX = -1;
	int ux = (int)x;
	int uy = (int)y;
	if ((ux + offsetX) < 0)
		resultX = 16 + offsetX;
	else if ((ux + offsetX) > 15)
		resultX = offsetX - 1;
	else
		resultX = ux + offsetX;

	int resultY = -1;
	if ((uy + offsetY) < 0)
		resultY = 16 + offsetY;
	else if ((uy + offsetY) > 15)
		resultY = offsetY - 1;
	else
		resultY = uy + offsetY;

	return resultY * 16 + resultX;
}


