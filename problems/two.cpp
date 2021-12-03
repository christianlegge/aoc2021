#include <cstring>
#include <iostream>

#include "../problem.h"

class ProblemTwo : public Problem {
public:
	std::string getOutputFirst() {
		std::string line;
		int horPos = 0, verPos = 0;
		while (!infile.eof()) {
			std::getline(infile, line);
			int sp = line.find(' ');
			if (sp == std::string::npos) continue;
			std::string num = line.substr(sp);
			if (line.at(0) == 'f') {
				horPos += std::stoi(num);
			}
			else if (line.at(0) == 'd') {
				verPos += std::stoi(num);
			}
			else if (line.at(0) == 'u') {
				verPos -= std::stoi(num);
			}
			std::cout << "verpos " << verPos << " horpos " << horPos << std::endl;
		}
		return std::to_string(horPos * verPos);
	}

	std::string getOutputSecond() {
		std::string line;
		int horPos = 0, verPos = 0, aim = 0;
		while (!infile.eof())
		{
			std::getline(infile, line);
			int sp = line.find(' ');
			if (sp == std::string::npos)
				continue;
			std::string num = line.substr(sp);
			if (line.at(0) == 'f')
			{
				horPos += std::stoi(num);
				verPos += std::stoi(num) * aim;
			}
			else if (line.at(0) == 'd')
			{
				aim += std::stoi(num);
			}
			else if (line.at(0) == 'u')
			{
				aim -= std::stoi(num);
			}
		}
		return std::to_string(horPos * verPos);
	}

};
