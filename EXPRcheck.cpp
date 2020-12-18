#include "EXPRchek.h"
#include<iostream>

bool EXPRchek::line_check(std::string line)
{
	std::string comand = find_comand(line);
	if (!comand.empty()) {
		for (int i = 0; i < comand.length(); i++) {
			if (isupper(comand[i])) {
				std::cout << "Sytax error!"; /////
				return false;
			}
		}
	}

	std::string line_to_del = line;

	if ((comand == "read") || (comand == "print")) {
		while (!line_to_del.empty()) {
			if (find_comand(line_to_del) == "=") {
				std::cout << "Sytax error!"; ////////
				return false;
			}

			line_to_del.erase(0, comand.length + 1);
		}

		if (comand == "print") {
			if (!line.empty()) {
				if (std::stoi(find_comand(find_comand(line)) == '/0') {/////////////////////
					std::cout << "Error" << endl;
				}

			}
			else {
				std::cout << "Error";
					return false;
			}
		}
	}
	else if (find_comand(find_comand(line)) == "=") {
		while (!line.empty()) {
			if ((find_comand(line) == "read") || (find_comand(line) == "print") || (((find_comand(line) == "\*") || (find_comand(line) == "%")) && (find_comand(find_comand(line)) == "0"))) {
				throw std::bad_alloc();     // !!!!!!
				return false;
			}

		}
	}
	else {
		std::cout << "Error Invalid row!" << std::endl;
		return false;
	}


	return true;
}
