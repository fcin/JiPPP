#include "Effect0.h"

Effect0::Effect0()
{
}

void Effect0::apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId)
{
	const Board* board = boards[boardId];

	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			board->GetCells()[index] = 0;
		}
	}
}