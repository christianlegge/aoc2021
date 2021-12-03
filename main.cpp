#include <filesystem>
#include <iostream>

#include "problems.h"

int main(int argc, char *argv[]) {
	ProblemTwo p = ProblemTwo();
	p.setInput("inputs/two.txt");

	std::cout << "Part one answer: " << p.getOutputFirst() << std::endl; 
	std::cout << "Part two answer: " << p.getOutputSecond() << std::endl; 

	return 0;
}
