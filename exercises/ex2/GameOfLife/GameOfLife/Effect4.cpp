#include "Effect4.h"

Effect4::Effect4()
{
}

void Effect4::apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId)
{
	const Board* board = boards[boardId];
	std::vector<int> toReplace;
	int* cells = board->GetCells();

	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			int value = cells[index];
			if (value != 0)
				continue;

			int leftTop = board->GetNeighbour(indexX, indexY, -1, -1);
			int top = board->GetNeighbour(indexX, indexY, 0, -1);
			int rightTop = board->GetNeighbour(indexX, indexY, 1, -1);
			int leftBottom = board->GetNeighbour(indexX, indexY, -1, 1);
			int bottom = board->GetNeighbour(indexX, indexY, 0, 1);
			int rightBottom = board->GetNeighbour(indexX, indexY, 1, 1);
			int left = board->GetNeighbour(indexX, indexY, -1, 0);
			int right = board->GetNeighbour(indexX, indexY, 1, 0);

			int sum = cells[leftTop] + cells[top] + cells[rightTop] +
				cells[leftBottom] + cells[bottom] + cells[rightBottom] +
				cells[left] + cells[right];

			if (sum == 3)
				continue;

			toReplace.push_back(index);
		}
	}

	for (size_t index = 0; index < toReplace.size(); index++)
		cells[toReplace[index]] = 1;
}