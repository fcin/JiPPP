#pragma once
#include "Board.h"
#include "Effect.h"

class Effect2 : public Effect
{
public:
	Effect2();
	virtual void apply(Board& board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy) override;
};