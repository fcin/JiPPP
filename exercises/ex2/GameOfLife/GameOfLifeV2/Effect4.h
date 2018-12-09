#ifndef EFFECT4_H
#define EFFECT4_H

#include <vector>
#include "Effect.h"
#include "KeyValuePair.h"

class Effect4 : public Effect
{
public:
	void apply(Board* boards, unsigned int row, unsigned int col, unsigned int drow, unsigned int dcol, unsigned int boardIndex) override;

};

#endif
