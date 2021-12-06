#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <unordered_map>

#include "../problem.h"

class Lanternfish {
public:
	Lanternfish(int timer) : timer(timer) {}
	Lanternfish() : timer(8) {}

	bool tick() {
		timer--;
		if (timer == -1) {
			timer = 6;
			return true;
		}
		return false;
	}
private:
	int timer;
};

class ProblemSix : public Problem {
public:
	std::string getOutputFirst() {
		std::string line;
		std::getline(infile, line);
		std::istringstream is(line);
		std::vector<Lanternfish> fishes;
		for (int age; is >> age;)
		{
			if (is.peek() == ',') is.ignore();
			fishes.push_back(Lanternfish(age));
			
		}

		std::vector<Lanternfish> toAdd;

		for (int i = 0; i < 80; i++) {
			for (auto &fish : fishes) {
				if (fish.tick()) toAdd.push_back(Lanternfish());
			}
			for (auto &fish : toAdd) fishes.push_back(fish);
			toAdd.clear();
			std::cout << "Fish after " << i << " days: " << fishes.size() << std::endl;
		}

		return std::to_string(fishes.size());
	}

	std::string getOutputSecond() {
		std::string line;

		long long int fishes[9];
		long long int newFishes[9];

		std::getline(infile, line);
		std::istringstream is(line);

		memset(fishes, 0, sizeof(long long int) * 9);
		memset(newFishes, 0, sizeof(long long int) * 9);
		for (int age; is >> age;)
		{
			if (is.peek() == ',')
				is.ignore();
			
			fishes[age]++;
			
		}

		for (int i = 0; i < 256; i++)
		{
			for (int age = 0; age <= 7; age++) {
				newFishes[age] = fishes[age+1];
			}

			newFishes[6] += fishes[0];
			newFishes[8] = fishes[0];

			memcpy(fishes, newFishes, sizeof(long long int) * 9);
			memset(newFishes, 0, sizeof(long long int) * 9);

			std::cout << "Day " << i << std::endl;
			printArray(fishes, 9);
		}

		long long int total = 0;
		for (int i = 0; i <= 8; i++) {
			total += fishes[i];
		}

		std::cout << "Total is " << total;

		return std::to_string(total);

		return "not implemented";
	}

private:
	void printArray(long long int *arr, int len)
	{
		std::cout << arr[0];
		for (int i = 1; i < len; i++) {
			std::cout << ", " << arr[i];
		}
		std::cout << std::endl;
	}
};
