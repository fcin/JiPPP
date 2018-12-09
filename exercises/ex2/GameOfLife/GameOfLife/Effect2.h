#ifndef EFFECT2_H
#define EFFECT2_H

#include "Board.h"
#include "Effect.h"

class Effect2 : public Effect
{
public:
	Effect2();
	virtual void apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId) override;
};

#endif