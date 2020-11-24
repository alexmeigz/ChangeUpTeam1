#include "../include/game/Game.h"
#include <string>

int main () {
    std::cout << "TESTING\n";

    Game g;
    g.makeMove("ADD", 1, 1);
    g.makeMove("ADD", 0, 0);
    g.makeMove("ADD", 0, 2);
    g.makeMove("ADD", 1, 2);
    g.makeMove("ADD", 2, 2);

    Game g2 = g;
    g2.displayBoard();

    Game g3;
    g3 = g;
    g2.displayBoard();


/*
    Player p(8);
    p.setScore(10);
    p.playerAddBall();
    Player p1 = p;
    cout << p1.playerGetId() << p1.getScore() << " " << p1.ballsLeft() << endl;
    */
}