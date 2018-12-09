#pragma once
#include "Board.h"

class Effect
{
public:
	virtual void apply(Board& board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy) = 0;
};
