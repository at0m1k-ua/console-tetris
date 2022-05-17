#include "GameField.h"
#include "Gui.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int const gf_size_x = 25;
    int const gf_size_y = 25;
  //auto* loader = new ShapeLoader();
  auto* gameField = new GameField(gf_size_x, gf_size_y);
  gameField->field[0][0] = 1;
  gameField->field[0][1] = 2;
  gameField->field[0][2] = 3;
  gameField->field[1][0] = 4;
  gameField->field[1][1] = 5;
  gameField->field[1][1] = 6;
  auto* gui = new Gui(gf_size_x, gf_size_y);
  gui->init();
  gui->drawGameField(gameField->field);
  while (true) {
      getchar();
      gui->updateScreen();
  }
  return 0;
}
