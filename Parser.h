#pragma once
#include<string>
#include<map>

class Parser
{
private:
	std::string input;
	std::map<std::string, char> vars;

public:
	Parser(std::string input);
	void get_next_lines(std::string buffer, std::string line_array[]);
	std::string find_comand(std::string line);
};

