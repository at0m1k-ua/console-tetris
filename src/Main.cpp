#include "ShapeLoader.h" 
#include <iostream>

using namespace std;

int main() {
  ShapeLoader test;
  ShapeState* state = new ShapeState();

  state->setValue(0, 0, true);
  state->setValue(0, 1, true);
  state->setValue(1, 1, true);
  state->setValue(2, 1, true);
  state->setValue(2, 0, true);

  Shape* shape = new Shape(state, 4, 1);

  for (int i = 0; i <= 4; i++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cout << shape->getCurrentState()->getValue(x, y) << ' ';
      }
      cout << endl;
    }
    shape->setNextState();
    cout << endl;
  }

  return 0;
}
