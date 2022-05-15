#include "ShapeLoader.h"
#include "Shape.h"
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
  return 0;
}
