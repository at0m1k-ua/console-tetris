#include "ShapeLoader.h" 
#include <iostream>

using namespace std;

int main() {
  ShapeLoader huinya;
  
  for (int i = 0; i < (int) huinya.numStates.size(); i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cout << huinya.shapes[i].getValue(k, j) << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  
  return 0;
}
