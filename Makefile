CXXFLAGS := -std=c++17

BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj

BIN_NAME := aoc2021
SRC_FILES := main.cpp $(wildcard problems/*.cpp)
OBJ_FILES := $(subst problems/,,$(patsubst %.cpp,%.o,$(SRC_FILES)))

default: $(OBJ_FILES) $(BIN_DIR)
	g++ -o $(BIN_DIR)/$(BIN_NAME) $(patsubst %, $(OBJ_DIR)/%, $(OBJ_FILES))

$(BIN_DIR): $(BUILD_DIR)
	mkdir -p $(BIN_DIR)

$(OBJ_FILES): $(SRC_FILES) $(OBJ_DIR)
	g++ -c $(SRC_FILES) -Iproblems -I. $(CXXFLAGS)
	mv $(OBJ_FILES) $(OBJ_DIR)


$(OBJ_DIR): $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*