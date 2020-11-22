#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "GoalPost.h"
#include <utility>

template <class T>
using Vector2D = std::vector<std::vector<T> >;

class GameBoard {
	public:
		GameBoard(int size);
		GameBoard(const GameBoard &og): SIZE(og.SIZE){
			board = og.board;
			numBalls = og.numBalls;
		}
		int removeBall(int x, int y);
		bool addBall(int player, int x, int y);

		Vector2D<int> getLayerX(int x) const;
		Vector2D<int> getLayerY(int y) const;
		Vector2D<int> getLayerZ(int z) const;
		Vector2D<int> getLayer(char c, int i) const;
		void displayBoard() const;

		bool isFull() const;
		vector<int> flatten() const;

		vector<pair<int, int>> getAvailableRemoves() const;
		vector<pair<int, int>> getAvailableAdds() const;

		GameBoard operator=(const GameBoard &gb);
	private:
		std::vector<int> fillPost(const std::vector<int> &post) const;

		Vector2D<GoalPost> board;
		const int SIZE;

		int numBalls;
};
