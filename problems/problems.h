#include <unordered_map>
#include <vector>

#include "one.cpp"
#include "two.cpp"
#include "three.cpp"
#include "four.cpp"
#include "five.cpp"
#include "six.cpp"
#include "seven.cpp"

std::unordered_map<int, std::string> numberWords = {
	{0, "zero"},
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"},
	{10, "ten"},
	{11, "eleven"},
	{12, "twelve"},
	{13, "thirteen"},
	{14, "fourteen"},
	{15, "fifteen"},
	{16, "sixteen"},
	{17, "seventeen"},
	{18, "eighteen"},
	{19, "nineteen"},
	{20, "twenty"},
	{21, "twentyone"},
	{22, "twentytwo"},
	{23, "twentythree"},
	{24, "twentyfour"},
	{25, "twentyfive"},
	{26, "twentysix"},
	{27, "twentyseven"},
	{28, "twentyeight"},
	{29, "twentynine"},
	{30, "thirty"},
	{31, "thirtyone"},
};

class ProblemFactory {
public:
	void setInputsDir(std::string dir) {
		this->inputsDir = dir;
	}

	Problem *getProblem(int probNum) {
		return nullptr;
	}

	template <class T>
	Problem *createProblem() {
		return nullptr;
	}
private:
	std::string inputsDir;
};