#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Board.h"
#include "Effect.h"
#include "Effect0.h"
#include "Effect1.h"
#include "Effect2.h"

std::vector<std::string> SplitBySpace(std::string value);

int main()
{
	Board* boards = new Board[2]{ Board(), Board() };
	Effect0* ef0 = new Effect0();
	Effect1* ef1 = new Effect1();
	Effect2* ef2 = new Effect2();
	Effect* effects[7] = { ef0, ef1, ef2 };

	while (true)
	{
		std::string input;
		std::getline(std::cin, input);
		//std::string input = "6 6 10 10 1 1";
		std::vector<std::string> values = SplitBySpace(input);

		if (values.size() != 6)
			continue;

		try
		{
			int x = std::stoi(values[0].c_str());
			int y = std::stoi(values[1].c_str());
			int dx = std::stoi(values[2].c_str());
			int dy = std::stoi(values[3].c_str());
			int effect = std::stoi(values[4].c_str());
			int boardId = std::stoi(values[5].c_str());

			if ((x < 0 || x > 15) || (y < 0 || y > 15) ||
				(dx < x || dx > 15) || (dy < y || dy > 15) ||
				(effect < 0 || effect > 6) ||
				(boardId < 0 || boardId > 2))
			{
				continue;
			}

			// for 5 and 6, check here and define GetRegion for board.
			// Only then apply effect to the correct board.
			effects[effect]->apply(boards[boardId], (unsigned int)x, (unsigned int)y, (unsigned int)dx, (unsigned int)dy);

			int* cells = boards[boardId].GetCells();
			for (size_t indexY = 0; indexY < 16; indexY++)
			{
				for (size_t indexX = 0; indexX < 16; indexX++)
				{
					size_t index = indexY * 16 + indexX;
					std::cout << cells[index];
				}
				std::cout << std::endl;
			}
		}
		catch (const std::exception&)
		{
			continue;
		}
	}

	std::getchar();
	return 0;
}

std::vector<std::string> SplitBySpace(std::string value)
{
	std::istringstream iss(value);
	std::vector<std::string> output;

	do
	{
		std::string subs;
		iss >> subs;
		output.push_back(subs);
	} while (iss);

	output.pop_back();

	return output;
}