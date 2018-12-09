#ifndef EFFECT6_H
#define EFFECT6_H

#include "Effect.h"
#include "Board.h"
#include <vector>

class Effect6 : public Effect
{
private:
	Board * m_BoardState1 = nullptr;
	Board * m_BoardState2 = nullptr;

public:
	Effect6();
	~Effect6();
	virtual void apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId) override;
};

#endif