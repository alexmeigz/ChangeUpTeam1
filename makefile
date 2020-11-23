MAIN_SRC_DIR := src/game
MAIN_SRC_FILES := $(wildcard $(MAIN_SRC_DIR)/*.cpp)

AI_SRC_DIR := src/ai
AI_SRC_FILES := $(wildcard $(AI_SRC_DIR)/*.cpp)

game:
	g++ -std=c++11 -o game src/main/game.cpp $(MAIN_SRC_FILES)

aigame:
	g++ -std=c++11 -o aigame src/main/aigame.cpp $(MAIN_SRC_FILES) $(AI_SRC_FILES)