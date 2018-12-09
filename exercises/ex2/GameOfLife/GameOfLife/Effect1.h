#pragma once
#include "Effect.h"

class Effect1 : public Effect
{
public:
	Effect1();
	virtual void apply(Board& board, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy) override;
};