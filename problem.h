#include <fstream>
#include <string>

class Problem {
public:
	void setInput(std::string input) {
		this->input = input;
		infile.open(input);
	}

	virtual std::string getOutput() = 0;
protected:
	std::ifstream infile;
	std::string input;
};