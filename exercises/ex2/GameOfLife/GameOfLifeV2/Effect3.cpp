#include "Effect3.h"

void Effect3::apply(Board * boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex)
{
	std::vector<KeyValuePair> items;

	for (size_t rowIndex = row; rowIndex <= drow; rowIndex++)
	{
		for (size_t colIndex = col; colIndex <= dcol; colIndex++)
		{
			if (boards[boardIndex].At(rowIndex, colIndex) == 0)
				continue;

			unsigned int neighbours = boards[boardIndex].GetNeighbourCount(rowIndex, colIndex);
			if (neighbours == 2 || neighbours == 3)
				continue;

			items.push_back(KeyValuePair(rowIndex, colIndex));
		}
	}

	for(size_t index = 0; index < items.size(); index++)
		boards[boardIndex].Set(items[index].Key, items[index].Value, 0);
}
