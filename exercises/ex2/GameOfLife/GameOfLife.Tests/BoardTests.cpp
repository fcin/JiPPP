#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameOfLife/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLifeTests
{		
	TEST_CLASS(BoardTests)
	{
	public:
		
		TEST_METHOD(MiddleOfTheBoardNeighbours)
		{
			Board board;
			int x = 6;
			int y = 6;
			int offsetX = -1;
			int offsetY = -1;
			board.GetCells()[6 * 16 + 6] = 1;
			board.GetCells()[5 * 16 + 5] = 2;

			int index = board.GetNeighbour(x, y, offsetX, offsetY);
			Assert::AreEqual(5 * 16 + 5, index);
		}

	};
}