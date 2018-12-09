#pragma once
#include "Effect.h"
#include "Board.h"

class Effect0 : public Effect
{
public:
	Effect0();
	virtual void apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId) override;
};
