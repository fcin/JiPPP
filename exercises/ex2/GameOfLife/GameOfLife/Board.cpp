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
