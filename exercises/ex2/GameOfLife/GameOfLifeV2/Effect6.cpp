#include "Effect6.h"

void Effect6::apply(Board * boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex)
{
	if (!hasEffect6Board)
	{
		hasEffect6Board = true;
		return;
	}
	else
	{
		hasEffect6Board = false;
	}

	std::vector<KeyValuePair> items;
	unsigned int otherBoardIndex = boardIndex == 0 ? 1 : 0;

	for (size_t rowIndex = row; rowIndex <= drow; rowIndex++)
	{
		for (size_t colIndex = col; colIndex <= dcol; colIndex++)
		{
			if (boards[otherBoardIndex].At(rowIndex, colIndex) == 1)
				items.push_back(KeyValuePair(rowIndex, colIndex, 1));
			else
				items.push_back(KeyValuePair(rowIndex, colIndex, 0));
		}
	}

	for (size_t index = 0; index < items.size(); index++)
		boards[boardIndex].Set(items[index].Key, items[index].Value, items[index].Data);
}
