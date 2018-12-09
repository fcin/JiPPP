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

			int leftTop =		board.GetNeighbour(indexX, indexY, -1, -1);
			int top =			board.GetNeighbour(indexX, indexY,  0, -1);
			int rightTop =		board.GetNeighbour(indexX, indexY,  1, -1);
			int leftBottom =	board.GetNeighbour(indexX, indexY, -1, 1);
			int bottom =		board.GetNeighbour(indexX, indexY,  0, 1);
			int rightBottom =	board.GetNeighbour(indexX, indexY,  1, 1);
			int left =			board.GetNeighbour(indexX, indexY, -1, 0);
			int right =			board.GetNeighbour(indexX, indexY,  1, 0);

			int sum = cells[leftTop] + cells[top] + cells[rightTop] +
				cells[leftBottom] + cells[bottom] + cells[rightBottom] +
				cells[left] + cells[right];

			if (sum == 2 || sum == 3)
				continue;

			toReplace.push_back(index);
		}
	}

	for (size_t index = 0; index < toReplace.size(); index++)
		cells[toReplace[index]] = 0;
}