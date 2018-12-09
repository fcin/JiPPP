#ifndef EFFECT0_H
#define EFFECT0_H

#include "Effect.h"

class Effect0 : public Effect
{
public:
	void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex) override;
};

#endif
