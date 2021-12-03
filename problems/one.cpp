#include <cstring>
#include <iostream>

#include "problem.h"

class RingBuffer {
	public:
	RingBuffer(size_t size) {
		this->size = size;
		vals = new int[size];
		pos = 0;
	}
	RingBuffer(const RingBuffer &other) {
		this->size = other.size;
		vals = new int[this->size];
		std::memcpy(this->vals, other.vals, sizeof(int) * this->size);
	}
	RingBuffer(RingBuffer &&other) {
		this->size = other.size;
		this->vals = other.vals;
	}
	~RingBuffer() {
		delete vals;
	}

	void insert(int val) {
		pos++;
		if (pos == size) pos = 0;
		vals[pos] = val;
	}

	int get(int idx) {
		return vals[(this->pos+idx) % this->size];
	}

private:
	size_t size;
	int *vals;
	int pos;
};

class ProblemOne : public Problem {
public:
	std::string getOutputFirst() {
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

	std::string getOutputSecond() {
		char line[10];
		int increases = 0;
		RingBuffer cache(4);
		for (int i = 0; i < 3; i++) {
			if (infile.eof()) return "0";
			infile.getline(line, 10);
			cache.insert(atoi(line));
		}
		while (!infile.eof()) {
			infile.getline(line, 10);
			cache.insert(atoi(line));
			if (cache.get(0) > cache.get(-3)) increases++; 
		}

		return std::to_string(increases);
	}

};
