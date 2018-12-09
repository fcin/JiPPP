#include "Effect2.h"

void Effect2::apply(Board * boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex)
{
	for (size_t rowIndex = row; rowIndex <= drow; rowIndex++)
	{
		for (size_t colIndex = col; colIndex <= dcol; colIndex++)
		{
			if(boards[boardIndex].At(rowIndex, colIndex) == 1)
				boards[boardIndex].Set(rowIndex, colIndex, 0);
			else
				boards[boardIndex].Set(rowIndex, colIndex, 1);
		}
	}
}
