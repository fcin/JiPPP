#include "Effect3.h"

Effect3::Effect3() { }

void Effect3::apply(Board & board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy)
{
	std::vector<int> toReplace;
	int* cells = board.GetCells();

	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			int value = cells[index];
			if (value != 1)
				continue;

			int top = indexY == 0 ? cells[(16 - 1) * 16 + indexX + 0] : cells[(indexY - 1) * 16 + indexX + 0];
			int bottom = indexY == 15 ? cells[(0 - 0) * 16 + indexX + 0] : cells[(indexY + 1) * 16 + indexX + 0];
			int left = indexX == 0 ? cells[indexY * 16 + 15] : cells[indexY * 16 + (indexX - 1)];
			int right = indexX == 15 ? cells[indexY * 16 + 0] : cells[indexY * 16 + (indexX + 1)];

			board.GetNeighbour(5, 5, 5, 5);
		}
	}
}