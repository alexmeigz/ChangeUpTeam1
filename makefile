MAIN_SRC_DIR := src/game
MAIN_SRC_FILES := $(wildcard $(MAIN_SRC_DIR)/*.cpp)

AI_SRC_DIR := src/ai
AI_SRC_FILES := $(wildcard $(AI_SRC_DIR)/*.cpp)

game:
	g++ -std=c++11 -o game src/main/pvpGame.cpp $(MAIN_SRC_FILES)

aigame:
	g++ -std=c++11 -o aigame src/main/computerGame.cpp $(MAIN_SRC_FILES) src/ai/AIGame.cpp

train:
	g++ -std=c++11 -o train src/main/train.cpp $(MAIN_SRC_FILES) $(AI_SRC_FILES)

test:
	g++ -std=c++11 -o test1 tests/testAssignmentOperators.cpp $(MAIN_SRC_FILES)
	test1.exe
	