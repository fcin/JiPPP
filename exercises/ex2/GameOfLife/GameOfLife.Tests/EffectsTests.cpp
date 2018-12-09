#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameOfLife/Board.h"
#include "../GameOfLife/Effect.h"
#include "../GameOfLife/Effect0.h"
#include "../GameOfLife/Effect1.h"
#include "../GameOfLife/Effect2.h"
#include "../GameOfLife/Effect3.h"
#include "../GameOfLife/Effect4.h"
#include "../GameOfLife/Effect5.h"
#include "../GameOfLife/Effect6.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameOfLifeTests
{
	TEST_CLASS(EffectsTests)
	{
	public:

		TEST_METHOD(Effect0Test)
		{
			Board* b1 = new Board();
			Board* b2 = new Board();
			const Board** boards = const_cast<const Board**>(new Board*[2]{ b1, b2 });
			Effect* ef = new Effect0();
			for (size_t index = 0; index < 16 * 16; index++)
				boards[0]->GetCells()[index] = 1;

			ef->apply(boards, 0, 0, 15, 15, 0);

			for(size_t index = 0; index < 16 * 16; index++)
				Assert::AreEqual(boards[0]->GetCells()[index], 0);
			
			delete ef;
		}

		TEST_METHOD(Effect1Test)
		{
			Board* b1 = new Board();
			Board* b2 = new Board();
			const Board** boards = const_cast<const Board**>(new Board*[2]{ b1, b2 });
			Effect* ef = new Effect1();
			for (size_t index = 0; index < 16 * 16; index++)
				boards[0]->GetCells()[index] = 0;

			ef->apply(boards, 0, 0, 15, 15, 0);

			for (size_t index = 0; index < 16 * 16; index++)
				Assert::AreEqual(boards[0]->GetCells()[index], 1);

			delete ef;
		}

		TEST_METHOD(Effect2Test)
		{
			Board* b1 = new Board();
			Board* b2 = new Board();
			const Board** boards = const_cast<const Board**>(new Board*[2]{ b1, b2 });
			Effect* ef = new Effect2();
			for (size_t index = 16 * 16 / 2; index < 16 * 16; index++)
				boards[0]->GetCells()[index] = 1;

			ef->apply(boards, 0, 0, 15, 15, 0);

			for (size_t index = 0; index < 16 * 16 / 2; index++)
				Assert::AreEqual(boards[0]->GetCells()[index], 1);
			for (size_t index = 16 * 16 / 2; index < 16 * 16; index++)
				Assert::AreEqual(boards[0]->GetCells()[index], 0);

			delete ef;
		}

		TEST_METHOD(Effect3Test_1)
		{
			/*
			1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			*/

			Board* b1 = new Board();
			Board* b2 = new Board();
			const Board** boards = const_cast<const Board**>(new Board*[2]{ b1, b2 });
			Effect* ef = new Effect3();
			boards[0]->GetCells()[0] = 1;

			ef->apply(boards, 0, 0, 15, 15, 0);

			for (size_t index = 0; index < 16 * 16; index++)
				Assert::AreEqual(boards[0]->GetCells()[index], 0);

			delete ef;
		}

		TEST_METHOD(Effect3Test_2)
		{
			/*
			1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			*/

			Board* b1 = new Board();
			Board* b2 = new Board();
			const Board** boards = const_cast<const Board**>(new Board*[2]{ b1, b2 });
			Effect* ef = new Effect3();
			boards[0]->GetCells()[0] = 1;
			boards[0]->GetCells()[1] = 1;
			boards[0]->GetCells()[2] = 1;

			ef->apply(boards, 0, 0, 15, 15, 0);

			Assert::AreEqual(boards[0]->GetCells()[1], 1);

			for (size_t index = 0; index < 16 * 16; index++)
			{
				if (index == 1)
					continue;
				Assert::AreEqual(boards[0]->GetCells()[index], 0);
			}

			delete ef;
		}

		TEST_METHOD(Effect4Test_1)
		{
			/*
			1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0  ->  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0		 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
			*/

			Board* b1 = new Board();
			Board* b2 = new Board();
			const Board** boards = const_cast<const Board**>(new Board*[2]{ b1, b2 });
			Effect* ef = new Effect4();
			boards[0]->GetCells()[0] = 1;
			boards[0]->GetCells()[1] = 1;
			boards[0]->GetCells()[2] = 1;

			ef->apply(boards, 0, 0, 15, 15, 0);

			Assert::AreEqual(1, boards[0]->GetCells()[1 * 16 + 1]);
			Assert::AreEqual(1, boards[0]->GetCells()[15 * 16 + 1]);

			for (size_t index = 0; index < 16 * 16; index++)
			{
				if (index == (1 * 16 + 1) || index == (15 * 16 + 1))
					continue;
				Assert::AreEqual(0, boards[0]->GetCells()[index]);
			}

			delete ef;
		}
	};
}