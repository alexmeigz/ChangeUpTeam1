#include "GoalPost.h"
#include <iostream>

int main() {
    GoalPost gp(3);

    gp.push(1);
    gp.push(2);
    gp.push(3);
    gp.pop();
    gp.push(4);

    for (int i = 0; i < 3; ++i) {
        std::cout << gp.getPost()[i] << ",";
    }
}