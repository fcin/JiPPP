#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Effect.h"
#include "Effect0.h"
#include "Effect1.h"
#include "Effect2.h"
#include "Effect3.h"
#include "Effect4.h"
#include "Effect5.h"
#include "Effect6.h"
#include "Parser.h"

int main()
{
	Board boards[2];
	std::vector<unsigned int> values;
	int lastBoard = -1;

	do
	{
		std::string input;
		std::getline(std::cin, input);
		values = Parser::Parse(input);

		if (values.size() < 6)
			break;

		if (!Parser::AreInCorrectRange(values))
			continue;

		lastBoard = values[5];

		Effect* effect;
		switch (values[4])
		{
		case 0: effect = new Effect0(); break;
		case 1: effect = new Effect1(); break;
		case 2: effect = new Effect2(); break;
		case 3: effect = new Effect3(); break;
		case 4: effect = new Effect4(); break;
		case 5: effect = new Effect5(); break;
		case 6: effect = new Effect6(); break;
		}

		effect->apply(boards, values[0], values[1], values[2], values[3], values[5]);

		delete effect;
	} while (values.size() >= 6);

	if (lastBoard == -1)
		return 0;

	for (size_t row = 0; row < 16; row++)
	{
		for (size_t col = 0; col < 16; col++)
		{
			std::cout << boards[lastBoard].At(row, col);
		}

		std::cout << std::endl;
	}

	std::cin.get();
}