#ifndef EFFECT5_H
#define EFFECT5_H

#include <vector>
#include "Effect.h"
#include "KeyValuePair.h"

static bool hasBoard = false;

class Effect5 : public Effect
{
public:
	void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex) override;

};

#endif
