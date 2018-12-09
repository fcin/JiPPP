#pragma once
#include "Board.h"
#include "Effect.h"
#include <vector>

class Effect5 : public Effect
{
private:
	Board * m_BoardState1 = nullptr;
	Board * m_BoardState2 = nullptr;

public:
	Effect5();
	virtual void apply(const Board** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId) override;
};