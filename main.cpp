#include <filesystem>
#include <iostream>

#include "problems.h"

int main(int argc, char *argv[]) {
	ProblemOne p = ProblemOne();
	p.setInput("inputs/one.txt");

	std::cout << p.getOutputSecond() << std::endl; 

	return 0;
}
