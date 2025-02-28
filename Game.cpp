#include <iostream>
#include "Game.h"

Game::Game() { srand(time(0)); }

void Game::generateMines() {
  int randNum = 0;
  for (int i = 1; i < LENGTH - 1; i++) {
    for (int j = 1; j < LENGTH - 1; j++) {
      randNum = rand() % 5 + 1; // random number bewteen 1 and 5 (20% chance to
                                // hit any given number)
      if (randNum == 1) {
        field[i][j].mine = true;
      }
    }
  }
}

void Game::generateNums() {
  int mineCount = 0;
  for (int i = 1; i < LENGTH - 1; i++) {
    for (int j = 1; j < LENGTH - 1; j++) {
      if (!field[i][j].mine) {
        // Check the EIGHT surrounding tiles, increase count if it is a mine
        for (int check = 0; check < 9; check++) {
          if (field[(i - 1) + (check / 3)][(j - 1) + (check % 3)].mine)
            mineCount++;
        }

        field[i][j].mine_count = mineCount;
        mineCount = 0;
      }
    }
  }
}
void Game::printField() {
  int ascii = 0;
  char letter;

  for (int i = 0; i < LENGTH - 1; i++) {
    for (int j = 0; j < LENGTH - 1; j++) {
      if ((i > 0 && j > 0) && (i < LENGTH - 1 && j < LENGTH - 1)) {
        if (field[i][j].mine){
          std::cout << "M ";
          }
        else if (!field[i][j].revealed)
        {
            std::cout << "* ";
        }
        else if (field[i][j].mine_count == 0)
        {
            std::cout << "  ";
        }
        else
        {
            std::cout << field[i][j].mine_count << " ";
        }

        /* TESTING CODE
      if ((i > 0 && j > 0) && (i < LENGTH - 1 && j < LENGTH - 1)) {
        if (field[i][j].mine) {
          std::cout << "M ";
        } else if (field[i][j].mine_count == 0) {
          std::cout << "  ";
        } else {
          std::cout << field[i][j].mine_count << " ";
        }
      */

      } else if (i == 0 && j == 0) {
        std::cout << "  ";
      } else if (i == 0){
        ascii = j + 64;
        letter = char(ascii);
        std::cout << letter << " ";
      } else if (j == 0){
        std::cout << i << " ";
      }
    }
     std::cout << std::endl;
  }
}


void Game::explode(const int chain, int i, int j) {
  int new_i = 0, new_j = 0;
  field[i][j].exploded = true;
  for (int check = 0; check < 9; check++){
    new_i = (i-1) + (check / 3);
    new_j = (j-1) + (check % 3);

    field[new_i][new_j].revealed = true;
    field[new_i][new_j].mine = false;
    }
}


//void Game::explode(const int chain, int i, int j) {
//  int new_i = 0, new_j = 0;
//  field[i][j].exploded = true;
//
//
//
//
//// int new_i = 0, new_j = 0;
//// field[i][j].exploded = true;
//// if (chain == 0){
////   return;
//// }
// for (int check = 0; check < 9; check++){
//  new_i = (i-1) + (check / 3);
//  new_j = (j-1) + (check % 3);
//
//   if (!field[new_i][new_j].exploded && field[new_i][new_j].mine_count > 0){
//     field[new_i][new_j].mine_count--;
//   }
//   if ((new_i == i && new_j == j) && field[i][j].exploded == true){
//    ;
//  } else if (field[new_i][new_j].mine){
//   explode(chain - 1, new_i, new_j);
//   }
//  field[new_i][new_j].revealed = true;
//  field[new_i][new_j].mine = false;
//  }
//  return;
// }
//




//void Game::play(){
//  while (gameover == false){}
//}