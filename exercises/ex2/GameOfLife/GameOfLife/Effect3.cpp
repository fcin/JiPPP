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

			
		}
	}
}

unsigned int Effect3::GetNeighbour(const int* cells, unsigned int x, unsigned int y, int offsetX, int offsetY)
{
	int resultX = -1;
	if ((x + offsetX) < 0)
		resultX = 16 + offsetX;
	else if ((x + offsetX) > 15)
		resultX = offsetX - 1;
	else
		resultX = x + offsetX;

	int resultY = -1;
	if ((y + offsetY) < 0)
		resultY = 16 + offsetY;
	else if ((y + offsetY) > 15)
		resultY = offsetY - 1;
	else
		resultY = y + offsetY;

	return cells[resultY * 16 + resultX];
}

