#pragma once
#include "Game.h"
#include "Bot.h"
#include <iostream>

class State {
public:
    State () {
        std::cout << "HERE" << std::endl;
    }

private:
    Bot bot1 = Bot("bot 1");
    Bot bot2 = Bot("bot 2");
};