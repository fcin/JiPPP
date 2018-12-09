#include "Board.h"

Board::Board()
{
	m_Cells = new int*[16];
	for (size_t index = 0; index < 16; index++)
		m_Cells[index] = new int[16];

	for (size_t index = 0; index < 16; index++)
	{
		for (size_t index2 = 0; index2 < 16; index2++)
		{
			m_Cells[index][index2] = 0;
		}
	}
}

const int Board::At(unsigned int row, unsigned col) const
{
	return m_Cells[row][col];
}

void Board::Set(unsigned int row, unsigned int col, int value)
{
	m_Cells[row][col] = value;
}

int Board::GetNeighbourCount(unsigned int row, unsigned col)
{
	int count = 0;
	int size = 16;
	int sRow = (int)row;
	int sCol = (int)col;
	for (int i = sRow - 1; i <= sRow + 1; i++) {
		for (int j = sCol - 1; j <= sCol + 1; j++) {
			if (i == sRow && j == sCol) {
				continue;
			}
			count += m_Cells[(i + size) % size][(j + size) % size];
		}
	}

	return count;
}
