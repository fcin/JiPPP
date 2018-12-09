#include "Effect1.h"

Effect1::Effect1()
{
}

void Effect1::apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId)
{
	const Board* board = boards[boardId];

	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			board->GetCells()[index] = 1;
		}
	}
}
