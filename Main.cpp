//
// Created by harith on 2/28/25.
//

#include <iostream>
#include "Game.h"

int main() {
    Game game;
    game.generateMines();
    game.generateNums();
    game.printField();
    game.explode(3, 3, 3);
    std::cout << std::endl;
    game.printField();
}
