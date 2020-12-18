#include "Parser.h"

void Parser::get_next_lines(std::string buffer, std::string line_array[])
{
	int n = 0;
	int pos = 0;
	while (!buffer.empty()) {
		pos = (buffer.find("\n") != -1) ? buffer.find("\n") : buffer.size();
		std::string line = buffer.substr(0, pos);
		line_array[n] = line;
		buffer.erase(0, pos + 1);
		n++;
	}
}

std::string Parser::find_comand(std::string line)
{
	int pos = (line.find(" ") != -1) ? line.find(" ") : line.size();
	std::string comand = line.substr(0, pos);
	//line.erase(0, pos + 1);

	return comand;
}
