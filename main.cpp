#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include <regex>

const int SIZE = 3;
const int NUM_PLAYERS = 2;
const int MAX_BALL = 18;
const int WINNING_SCORE = 4;
const int MOVES_PER_TURN = 3;
const int MOVES_FIRST_TURN = 2;
const int REMOVES_PER_TURN = 1;

int main() {
    Game game(SIZE, 
              NUM_PLAYERS, 
              MAX_BALL, 
              WINNING_SCORE, 
              MOVES_PER_TURN, 
              MOVES_FIRST_TURN, 
              REMOVES_PER_TURN);

    std::regex input_rgx("(ADD/REMOVE) ([0-9) ([0-9])");

    while (!game.finished()) {
        std::cout << "---------------------------------------------------------------------------\n"; 
        game.displayBoard();
        std::cout << "---------------------------------------------------------------------------\n\n"; 
        std::cout << "Player 1: " << game.getScore(1) << "\nPlayer 2: " << game.getScore(2) << "\n\n";
        std::cout << "It is player " << game.whoseTurn() << "'s turn.\n";
        std::cout << "  - " << game.movesRemaining() << " moves remaining.\n";
        std::cout << "  - " << game.canRemove() << " removes remaining.\n";
        std::cout << "  - " << game.ballsLeft() << " balls left\n";
        
        std::string move = "";
        int x = -1;
        int y = -1;

        std::cout << "---------------------------------------------------------------------------\n\n"; 
        do {
            std::cout << "Make a move: ADD/REMOVE X Y: ";
        
            std::string input;
            std::getline(std::cin, input);
            std::smatch matches;
            
            std::cout << input << std::endl;

            if (std::regex_search(input, matches, input_rgx)) {
                move = matches.str(1);
                std::cout << move << "," << matches.str(2) << "," << matches.str(3) << std::endl;
            }
        } while(!game.makeMove(move, x, y));
        
        std::cout << "---------------------------------------------------------------------------\n\n"; 

        break;
    }

}
