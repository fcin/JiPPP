#pragma once
#include "Board.h"
class Effect
{
public:
	virtual void apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId) = 0;
};
