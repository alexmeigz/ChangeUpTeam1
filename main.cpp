#include "Game.h"

const int DIM = 3;
const int MAX_BALLS = 16;
const int WINNING_SCORE = 4;
const int MOVES_PER_TURN = 3;
const int MOVES_FIRST_TURN = 2;
const int REMOVES_PER_TURN = 1;

int main() {
    Game game(DIM, MAX_BALLS, WINNING_SCORE, MOVES_PER_TURN, MOVES_FIRST_TURN, REMOVES_PER_TURN);

    while(!game.finished()) {

        /*

        Display 
            - whose turn
            - number moves remaining
            - balls left
            - Player1Score
            - Player2Score
            - can remove a ball?

        Input: 
            - add x y
            - remove x y
            - display state

        Then call the game methods 

        */

        break;
    }
}