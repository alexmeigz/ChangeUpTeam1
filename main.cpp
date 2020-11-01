#include "Game.h"

const int DIM = 3;
const int MAX_BALLS = 16;
const int WINNING_SCORE = 4;
const int MOVES_PER_TURN = 3;
const int MOVES_FIRST_TURN = 2;

int main() {
    Game game(DIM, MAX_BALLS, WINNING_SCORE, MOVES_PER_TURN, MOVES_FIRST_TURN);

    while(!game.finished()) {

        /*
        This should all be done using the game class:

        Display 
            - whose turn
            - number moves remaining
            - balls left
            - Player1Score
            - Player2Score

        Input: 
            - add x y
            - remove x y
            - display state

            Then call the game methods 

        */

        break;
    }
}