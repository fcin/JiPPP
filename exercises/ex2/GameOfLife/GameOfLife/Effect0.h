#pragma once
#include "Effect.h"
#include "Board.h"

class Effect0 : public Effect
{
public:
	Effect0();
	virtual void apply(Board& board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy) override;
};
