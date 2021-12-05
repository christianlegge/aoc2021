#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../problem.h"

class BingoCard {
public:
	BingoCard(std::istream &is) {
		for (int i = 0; i < 25; i++)  {
			is >> numbers[i];
			marked[i] = false;
			cache[numbers[i]] = i;
		}
		already_won = false;
	}

	int markNumber(int number) {
		if (cache.find(number) != cache.end()) {
			marked[cache[number]] = true;
		}
		if (!checkWin()) return -1;
		else if (!already_won) {
			already_won = true;
			return number * getScore();
		}
		else return 0;
	}



private:
	bool checkWin()
	{
		bool win;
		for (int i = 0; i < 12; i++)
		{
			win = true;
			for (int j = 0; j < 5; j++)
			{
				if (!marked[lines[i][j]])
				{
					win = false;
				}
			}
			if (win)
				break;
		}
		return win;
	}

	int getScore() {
		int sum = 0;
		for (int i = 0; i < 25; i++) {
			if (!marked[i]) sum += numbers[i];
		}
		return sum;
	}

	int numbers[25];
	bool marked[25];
	std::unordered_map<int, int> cache;
	bool already_won;

	int lines[12][5] = {
		{0, 1, 2, 3, 4},
		{5, 6, 7, 8, 9},
		{10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19},
		{20, 21, 22, 23, 24},
		{0, 5, 10, 15, 20},
		{1, 6, 11, 16, 21},
		{2, 7, 12, 17, 22},
		{3, 8, 13, 18, 23},
		{4, 9, 14, 19, 24},
		{0, 6, 12, 18, 24},
		{4, 8, 12, 16, 20},
	};
};

class ProblemFour : public Problem {
public:
	std::string getOutputFirst() {
		std::string called;

		std::getline(infile, called);
		std::vector<BingoCard> cards;

		while (!infile.eof()) {
			cards.push_back(BingoCard(infile));
		}

		std::istringstream calls(called);
		for (int numCalled; calls >> numCalled;) {
			if (calls.peek() == ',') calls.ignore();
			for (auto &card : cards) {
				int score = card.markNumber(numCalled);
				if (score > 0) {
					return std::to_string(score);
				}
			}
		}
		return "No winning card found.";
	}

	std::string getOutputSecond() {
		std::string called;

		std::getline(infile, called);
		std::vector<BingoCard> cards;

		while (!infile.eof())
		{
			cards.push_back(BingoCard(infile));
		}

		std::istringstream calls(called);
		int lastScore;
		for (int numCalled; calls >> numCalled;)
		{
			if (calls.peek() == ',')
				calls.ignore();
			for (auto &card : cards)
			{
				int score = card.markNumber(numCalled);
				if (score > 0)
				{
					lastScore = score;
				}
			}
		}
		return std::to_string(lastScore);
	}

private:
};
