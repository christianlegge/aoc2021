#include "problem.h"

class ProblemOne : public Problem {
public:
	std::string getOutput() {
		char line[10];
		int increases = 0;
		infile.getline(line, 10);
		int lastInput = atoi(line);
		while (!infile.eof()) {
			infile.getline(line, 10);
			if (atoi(line) > lastInput) increases++;
			lastInput = atoi(line);
		}
		infile.close();
		return std::to_string(increases);
	}
};
