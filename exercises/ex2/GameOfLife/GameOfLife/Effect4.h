#ifndef EFFECT4_H
#define EFFECT4_H

#include "Board.h"
#include "Effect.h"
#include <vector>

class Effect4 : public Effect
{
public:
	Effect4();
	virtual void apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId) override;
};

#endif