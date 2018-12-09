#ifndef EFFECT2_H
#define EFFECT2_H

#include "Effect.h"

class Effect2 : public Effect
{
public:
	void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex);

};

#endif
