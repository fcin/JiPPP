#include "Effect1.h"

Effect1::Effect1()
{
}

void Effect1::apply(Board & board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy)
{
	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			board.GetCells()[index] = 1;
		}
	}
}
