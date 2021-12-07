#include <filesystem>
#include <iostream>

#include "problems.h"

int main(int argc, char *argv[]) {
	Problem *p = new ProblemSeven();
	p->setInput("inputs/seven.txt");

	std::cout << "Part one answer: " << p->getOutputFirst() << std::endl;
	p->resetInputFile();
	std::cout << "Part two answer: " << p->getOutputSecond() << std::endl; 

	return 0;
}
