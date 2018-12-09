#include "Effect6.h"

Effect6::Effect6() { }

Effect6::~Effect6()
{
	if (m_BoardState1)
		delete m_BoardState1;
	if (m_BoardState2)
		delete m_BoardState2;
}

void Effect6::apply(const Board ** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId)
{
	if (boardId == 0 && m_BoardState1 == nullptr)
		m_BoardState1 = new Board(boards[0]);
	if (boardId == 1 && m_BoardState2 == nullptr)
		m_BoardState1 = new Board(boards[1]);

	if (m_BoardState1 == nullptr || m_BoardState2 == nullptr)
		return;

	int* cellsA = boards[0]->GetCells();
	std::vector<int> toReplace;

	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			if (cellsA[index] == 1)
				toReplace.push_back(1);
			else
				toReplace.push_back(0);
		}
	}

	int* cellsB = boards[1]->GetCells();
	int curr = 0;

	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			
			cellsB[index] = toReplace[curr];
			curr++;
		}
	}

	if (boardId == 0)
		delete m_BoardState1;
	else
		delete m_BoardState2;
}
