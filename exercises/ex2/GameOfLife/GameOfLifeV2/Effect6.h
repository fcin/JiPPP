#ifndef EFFECT6_H
#define EFFECT6_H

#include <vector>
#include "Effect.h"
#include "KeyValuePair.h"

static bool hasEffect6Board = false;

class Effect6 : public Effect
{
public:
	void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex) override;

};

#endif
