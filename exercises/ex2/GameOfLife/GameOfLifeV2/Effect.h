#ifndef EFFECT_H
#define EFFECT_H
#include "Board.h"

class Effect
{
public:
	virtual void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex) = 0;
};

#endif
