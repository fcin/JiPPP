#include "Parser.h"

std::vector<unsigned int> Parser::Parse(std::string& input)
{
	std::vector<unsigned int> values;
	size_t lastSpace = 0;
	for (size_t index = 0; index < input.size(); index++)
	{
		if (input[index] == ' ' || index == input.size() - 1)
		{
			std::string value = input.substr(lastSpace, index == (input.size() - 1) ? input.size() : index - lastSpace);

			if (value.size() > 0)
			{
				int parsed = std::stoi(value);
				values.push_back(parsed);
			}

			lastSpace = index;
		}
	}

	return values;
}

bool Parser::AreInCorrectRange(std::vector<unsigned int>& values)
{
	return values[0] >= 0 && values[0] < 16 && 
		   values[1] >= 0 && values[1] < 16 &&
		   values[2] >= values[0] && values[2] < 16 &&
		   values[3] >= values[1] && values[3] < 16 && 
		   values[4] >= 0 && values[4] <= 6 && 
		   values[5] >= 0 && values[5] <= 1;
}
