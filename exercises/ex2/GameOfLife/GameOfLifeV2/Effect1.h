#ifndef EFFECT1_H
#define EFFECT1_H

#include <iostream>
#include "Effect.h"

class Effect1 : public Effect
{
public:
	void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex) override;
};

#endif
