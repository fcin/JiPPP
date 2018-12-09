#include "Effect5.h"

Effect5::Effect5() { }

void Effect5::apply(const Board ** boards, unsigned int x, unsigned int y, unsigned int dx, unsigned int dy, int boardId)
{
	if (boardId == 0 && m_BoardState1 == nullptr)
	{
		m_BoardState1 = new Board(boards[0]);
	}

	if (boardId == 1 && m_BoardState2 == nullptr)
	{
		m_BoardState2 = new Board(boards[1]);
	}

	if (m_BoardState1 == nullptr || m_BoardState2 == nullptr)
		return;


	std::vector<int> newState;
	int* cellsA = m_BoardState1->GetCells();
	int* cellsB = m_BoardState2->GetCells();

	for (size_t indexY = y; indexY <= dy; indexY++)
	{
		for (size_t indexX = x; indexX <= dx; indexX++)
		{
			size_t index = indexY * 16 + indexX;
			
			if (cellsA[index] == cellsB[index])
				newState.push_back(0);
			else
				newState.push_back(1);
		}
	}

	int* selectedBoardCells = boards[boardId]->GetCells();

	for (size_t index = 0; index < newState.size(); index++)
	{
		selectedBoardCells[index] = newState[index];
	}

	if (boardId == 0)
	{
		delete m_BoardState1;
		m_BoardState1 = nullptr;
	}
	else
	{
		delete m_BoardState2;
		m_BoardState2 = nullptr;
	}
}
