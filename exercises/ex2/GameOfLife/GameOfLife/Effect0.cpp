#include "Effect0.h"

Effect0::Effect0()
{
}

void Effect0::apply(Board& board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy)
{
	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			board.GetCells()[index] = 0;
		}
	}
}