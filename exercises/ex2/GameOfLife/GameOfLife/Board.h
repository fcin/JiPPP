#pragma once
#include <string>

class Board
{
private:
	int* m_Cells;
public:
	Board();
	int* GetCells() const;
	unsigned int GetNeighbour(unsigned int x, unsigned int y, int offsetX, int offsetY) const;
};
