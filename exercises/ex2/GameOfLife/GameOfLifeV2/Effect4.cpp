#include "Effect4.h"

void Effect4::apply(Board * boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex)
{
	std::vector<KeyValuePair> items;

	for (size_t rowIndex = row; rowIndex <= drow; rowIndex++)
	{
		for (size_t colIndex = col; colIndex <= dcol; colIndex++)
		{
			if (boards[boardIndex].At(rowIndex, colIndex) == 0 && boards[boardIndex].GetNeighbourCount(rowIndex, colIndex) == 3)
			{
				items.push_back(KeyValuePair(rowIndex, colIndex, 1));
			}
			else
			{
				items.push_back(KeyValuePair(rowIndex, colIndex, 0));
			}
		}
	}

	for (size_t index = 0; index < items.size(); index++)
		boards[boardIndex].Set(items[index].Key, items[index].Value, items[index].Data);
}
