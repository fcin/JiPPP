#include "Effect2.h"

Effect2::Effect2()
{
}

void Effect2::apply(Board & board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy)
{
	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			int value = board.GetCells()[index];
			board.GetCells()[index] = value == 0 ? 1 : 0;
		}
	}
}
