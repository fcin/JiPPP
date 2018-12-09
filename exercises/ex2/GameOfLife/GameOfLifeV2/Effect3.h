#ifndef	EFFECT3_H
#define EFFECT3_H

#include "Effect.h"
#include "KeyValuePair.h"
#include <vector>

class Effect3 : public Effect
{
public:
	void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex) override;
};

#endif
