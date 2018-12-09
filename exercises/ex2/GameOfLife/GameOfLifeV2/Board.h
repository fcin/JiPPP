#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
	int** m_Cells;

public:
	Board();
	const int At(unsigned int x, unsigned y) const;
	void Set(unsigned int x, unsigned y, int value);
};

#endif
