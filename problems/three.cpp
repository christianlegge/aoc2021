#include <cstring>
#include <iostream>
#include <vector>
#include <utility>

#include "../problem.h"

class ProblemThree : public Problem {
public:
	std::string getOutputFirst() {
		std::string line;
		int gamma=0, epsilon=0;
		std::vector<std::pair<int, int>> bits_total;
		std::getline(infile, line);
		int len = line.length();
		for (int i = len - 1; i >= 0; i--) {
			bits_total.push_back({0, 0});
			if (line.at(i) == '0') bits_total.back().first++;
			else bits_total.back().second++;
		}
		while (!infile.eof()) {
			std::getline(infile, line);
			if (line.length() != len) continue;
			for (int i = len - 1, j = 0; i >= 0; i--, j++) {
				if (line.at(i) == '0')
					bits_total.at(j).first++;
				else
					bits_total.at(j).second++;
			}
		}
		int mult = 1;
		for (int i = 0; i < bits_total.size(); i++) {
			if (bits_total.at(i).first > bits_total.at(i).second) {
				gamma += mult;
			}
			else {
				epsilon += mult;
			}
			mult <<= 1;
		}
		return std::to_string(gamma * epsilon);
	}

	std::string getOutputSecond() {
		std::string line;
		int horPos = 0, verPos = 0, aim = 0;
		std::vector<std::string> allVals;
		while (!infile.eof())
		{
			std::getline(infile, line);
			if (line.length() == 0) {
				continue;
			}
			allVals.push_back(line);
		}
		int oxygen = getOxygen(allVals);
		int CO2 = getCO2(allVals);
		return std::to_string(oxygen * CO2);
	}

private:
	int getOxygen(std::vector<std::string> vals, int bit = 0) {
		auto commonality = getBitCommonality(vals);
		std::vector<std::string> newVals;
		for (int i = 0; i < vals.size(); i++) {
			if ((vals.at(i).at(bit) == '0' && commonality.at(bit).first > commonality.at(bit).second) || 
				(vals.at(i).at(bit) == '1' && commonality.at(bit).first <= commonality.at(bit).second)) {
					newVals.push_back(vals.at(i));
				}
		}
		if (newVals.size() ==  1) {
			return std::stoi(newVals.front(), nullptr, 2);
		}
		else {
			return getOxygen(newVals, bit + 1);
		}
	}

	int getCO2(std::vector<std::string> vals, int bit = 0) {
		auto commonality = getBitCommonality(vals);
		std::vector<std::string> newVals;
		for (int i = 0; i < vals.size(); i++)
		{
			if ((vals.at(i).at(bit) == '1' && commonality.at(bit).first > commonality.at(bit).second) ||
				(vals.at(i).at(bit) == '0' && commonality.at(bit).first <= commonality.at(bit).second))
			{
				newVals.push_back(vals.at(i));
			}
		}
		if (newVals.size() == 1)
		{
			return std::stoi(newVals.front(), nullptr, 2);
		}
		else
		{
			return getCO2(newVals, bit + 1);
		}
	}

	std::vector<std::pair<int, int>> getBitCommonality(std::vector<std::string> vals) {
		std::vector<std::pair<int, int>> commonality;
		int len = vals.front().length();
		for (int i = 0; i < len; i++)
		{
			commonality.push_back({0, 0});
			if (vals.front().at(i) == '0')
				commonality.back().first++;
			else
				commonality.back().second++;
		}
		for (int val = 1; val < vals.size(); val++) {
			for (int i = 0; i < len; i++)
			{
				if (vals.at(val).at(i) == '0')
					commonality.at(i).first++;
				else
					commonality.at(i).second++;
			}
		}
		return commonality;
	}
};
