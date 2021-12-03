#include <fstream>
#include <string>

class Problem
{
public:
	void setInput(std::string input) {
		this->input = input;
		infile.open(input);
		if (infile.fail()) {
			throw "Failed to open input file.";
		}
	}

	virtual std::string getOutputFirst() = 0;
	virtual std::string getOutputSecond() = 0;
protected:
	std::ifstream infile;
	std::string input;
};
