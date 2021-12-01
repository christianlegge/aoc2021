#include <iostream>

#include "problems.h"

int main(int argc, char *argv[]) {
	ProblemOne p = ProblemOne();
	p.setInput("inputs/one.txt");

	std::cout << p.getOutput() << std::endl; 

	return 0;
}
