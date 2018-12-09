#include "Effect5.h"

void Effect5::apply(Board * boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex)
{
	if (!hasBoard)
	{
		hasBoard = true;
		return;
	}
	else
	{
		hasBoard = false;
	}

	std::vector<KeyValuePair> items;

	for (size_t rowIndex = row; rowIndex <= drow; rowIndex++)
	{
		for (size_t colIndex = col; colIndex <= dcol; colIndex++)
		{
			if (boards[0].At(rowIndex, colIndex) == boards[1].At(rowIndex, colIndex))
				items.push_back(KeyValuePair(rowIndex, colIndex, 0));
			else
				items.push_back(KeyValuePair(rowIndex, colIndex, 1));
		}
	}

	for (size_t index = 0; index < items.size(); index++)
		boards[boardIndex].Set(items[index].Key, items[index].Value, items[index].Data);
}
