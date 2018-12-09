#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser
{
public:
	static std::vector<unsigned int> Parse(std::string& input);
	static bool AreInCorrectRange(std::vector<unsigned int>& values);
};

#endif
