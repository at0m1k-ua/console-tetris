#include "ShapeLoader.h"
#include "Shape.h"
#include "GameField.h"
#include <iostream>

using namespace std;

int main() {
  auto* loader = new ShapeLoader();
  loader->load();

  for (int i = 0; i < loader->getAmount(); i++) {
      Shape* shape = loader->getShape(i);
      ShapeState* state = shape->getCurrentState();
      for (int y = 0; y < 4; y++) {
          for (int x = 0; x < 4; x++) {
              cout << state->getValue(x, y) << ' ';
          }
          cout << "\n";
      }
      cout << endl;
  }
  auto* gameField = new GameField(10, 10);
  for(int i = 0; i < 10; i++)
  {
      for (int j = 0; j < 10; j++)
      {
          std::cout << gameField->getFieldValue(j, i) << " ";
      }
      std::cout << std::endl;
  }
  return 0;
}
