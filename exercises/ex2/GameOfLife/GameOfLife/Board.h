#pragma once
#include <string>

class Board
{
private:
	int* m_Cells;
public:
	Board();
	int* GetCells() const;
};
