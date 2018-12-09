#include "Effect1.h"

void Effect1::apply(Board * boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex)
{
	for (size_t rowIndex = row; rowIndex <= drow; rowIndex++)
	{
		for (size_t colIndex = col; colIndex <= dcol; colIndex++)
		{
			boards[boardIndex].Set(rowIndex, colIndex, 1);
		}
	}
}
