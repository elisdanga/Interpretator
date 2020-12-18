#include "FileSystem.h"

bool FileSystem::read(std::string file_name, std::string& output)
{
	this->stream.open(file_name, std::ios::in | std::ios::out | std::ios::app);
	if (this->stream.is_open()) {
		std::string line;
		while (this->stream.good()) {
			getline(this->stream, line);
			output.append(line);
			output.append("\n");
		}
		this->stream.close();
	}
	else {
		return false;
	}

	return true;
}
