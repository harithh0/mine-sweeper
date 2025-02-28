#ifndef GAME_H
#define GAME_H

#include <iostream>
class Game {
private:
  static const int LENGTH = 11;
  struct Tile {
    bool mine = false;
    bool revealed = false; // TODO: Make sure reveal == False
    bool exploded = false;
    int mine_count = 0;
  };
  Tile field[LENGTH][LENGTH];

public:
  Game();
  void generateMines();
  void generateNums();
  void printField();
  void explode(const int chain, int i, int j);
};

#endif // GAME.H
