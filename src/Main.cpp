#include <iostream>
#include "ShapeLoader.h"

using namespace std;

int main() {
    auto* shapeLoader = new ShapeLoader();

    shapeLoader->load();
    ShapeState* shapeState = shapeLoader->getShape(0)->getCurrentState();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << shapeState->getValue(j, i) << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++){
        cout << shapeState->getBottomCellsDistance(i) << ' ';
    }
    cout << endl;

    for (int i = 0; i < 4; i++){
        cout << shapeState->getLeftCellsDistance(i) << ' ';
    }
    cout << endl;

    for (int i = 0; i < 4; i++){
        cout << shapeState->getRightCellsDistance(i) << ' ';
    }
    cout << endl;
    return 0;
}
