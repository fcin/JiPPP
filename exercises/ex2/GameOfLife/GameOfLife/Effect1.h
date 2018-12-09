#ifndef EFFECT1_H
#define EFFECT1_H
#include "Effect.h"

class Effect1 : public Effect
{
public:
	Effect1();
	virtual void apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId) override;
};

#endif