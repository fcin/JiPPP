#pragma once
#include "Board.h"
#include "Effect.h"
#include <vector>

class Effect3 : public Effect
{
public:
	Effect3();
	virtual void apply(Board& board, const unsigned int x, unsigned int y, unsigned int dx, unsigned int dy) override;
};