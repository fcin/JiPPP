#ifndef BOARD_H
#define BOARD_H
#include <string>

class Board
{
private:
	int* m_Cells;
public:
	Board();
	~Board();
	Board(const Board* other);
	int* GetCells() const;
	unsigned int GetNeighbour(unsigned int x, unsigned int y, int offsetX, int offsetY) const;
};

#endif