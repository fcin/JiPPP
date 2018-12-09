#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameOfLife/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLifeTests
{		
	TEST_CLASS(BoardTests)
	{
	public:
		
		TEST_METHOD(MiddleOfTheBoardWithCornerNeighbours)
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

		TEST_METHOD(MiddleOfTheBoardWithHorizontalNeighbours)
		{
			Board board;
			int x = 6;
			int y = 6;
			int offsetY = 0;
			board.GetCells()[6 * 16 + 6] = 1;
			board.GetCells()[6 * 16 + 5] = 2;
			board.GetCells()[6 * 16 + 7] = 2;

			int offsetX = -1;

			int index = board.GetNeighbour(x, y, offsetX, offsetY);
			Assert::AreEqual(6 * 16 + 5, index);

			offsetX = 1;
			index = board.GetNeighbour(x, y, offsetX, offsetY);
			Assert::AreEqual(6 * 16 + 7, index);
		}

		TEST_METHOD(TopLeftCorner)
		{
			Board board;
			int x = 0;
			int y = 0;
			int offsetX = -1;
			int offsetY = -1;

			int index = board.GetNeighbour(x, y, offsetX, offsetY);
			int lastIndex = (16 * 16) - 1;
			Assert::AreEqual(lastIndex, index);
		}

		TEST_METHOD(TopRightCorner)
		{
			Board board;
			int x = 15;
			int y = 0;
			int offsetX = 1;
			int offsetY = -1;

			int index = board.GetNeighbour(x, y, offsetX, offsetY);
			int lastIndex = (15 * 16);
			Assert::AreEqual(lastIndex, index);
		}

		TEST_METHOD(BottomLeftCorner)
		{
			Board board;
			int x = 0;
			int y = 15;
			int offsetX = -1;
			int offsetY = 1;

			int index = board.GetNeighbour(x, y, offsetX, offsetY);
			int lastIndex = (0 * 16 + 16) - 1;
			Assert::AreEqual(lastIndex, index);
		}

		TEST_METHOD(BottomRightCorner)
		{
			Board board;
			int x = 15;
			int y = 15;
			int offsetX = 1;
			int offsetY = 1;

			int index = board.GetNeighbour(x, y, offsetX, offsetY);
			int lastIndex = 0;
			Assert::AreEqual(lastIndex, index);
		}
	};
}