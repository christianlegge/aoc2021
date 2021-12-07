#include <cstring>
#include <iostream>
#include <unordered_map>

#include "../problem.h"

class ProblemSeven : public Problem {
public:
	std::string getOutputFirst() {
		std::string line;
		std::unordered_map<int, int> crabs;
		int maxPos = 0;
		for (int crab; infile >> crab;)
		{
			if (infile.peek() == ',')
				infile.ignore();

			crabs[crab]++;
			if (crab > maxPos) maxPos = crab;
		}

		int minFuel = INT32_MAX;
		for (int i = 0; i < maxPos; i++) {
			int totalFuel = 0;
			for (auto &crab : crabs) {
				totalFuel += abs(i - crab.first) * crab.second;
			}
			if (totalFuel < minFuel) minFuel = totalFuel;
		}
		return std::to_string(minFuel);
	}

	std::string getOutputSecond()
	{
		std::string line;
		std::unordered_map<int, int> crabs;
		int maxPos = 0;
		for (int crab; infile >> crab;)
		{
			if (infile.peek() == ',')
				infile.ignore();

			crabs[crab]++;
			if (crab > maxPos)
				maxPos = crab;
		}

		int minFuel = INT32_MAX;
		for (int i = 0; i < maxPos; i++)
		{
			int totalFuel = 0;
			for (auto &crab : crabs)
			{
				totalFuel += abs(i - crab.first) * (abs(i - crab.first) + 1) * crab.second / 2;
			}
			if (totalFuel < minFuel)
				minFuel = totalFuel;
		}
		return std::to_string(minFuel);
	}
};
