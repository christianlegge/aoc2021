.PHONY: all clean

CXXFLAGS := -std=c++17

BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj

BIN_NAME := aoc2021
SRC_FILES := main.cpp $(wildcard problems/*.cpp)
OBJ_FILES := $(subst problems/,problems/,$(patsubst %.cpp,%.o,$(SRC_FILES)))
OBJ_FILES := $(patsubst %,$(OBJ_DIR)/%,$(OBJ_FILES))
BIN_FILE := $(BIN_DIR)/$(BIN_NAME)

all: $(BIN_FILE)

$(BIN_FILE): $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	g++ $^ -o $@ -Iproblems -I.

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	g++ -c $^ -o $@ -Iproblems -I.

$(OBJ_DIR)/problems/%.o: problems/%.cpp
	mkdir -p $(OBJ_DIR)/problems
	g++ -c $^ -o $@ -Iproblems -I.

clean:
	rm -rf $(BUILD_DIR)/*