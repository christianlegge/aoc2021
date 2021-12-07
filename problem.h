#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Problem
{
public:
	void setInput(std::string input) {
		this->input = input;
		infile.open(input);
		if (infile.fail()) {
			std::cout << "Failed to open input file." << std::endl;
			throw "Failed to open input file.";
		}
	}

	void resetInputFile() {
		infile.clear();
		infile.seekg(0);
	}

	virtual std::string getOutputFirst() = 0;
	virtual std::string getOutputSecond() = 0;
protected:
	std::ifstream infile;
	std::string input;
};
