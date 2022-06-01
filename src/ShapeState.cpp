#include "ShapeState.h"

ShapeState::ShapeState() {
	values = new bool[16]{false};
    bottomCellsDistances = new int[4]{NO_CELLS};
    leftCellsDistances = new int[4]{NO_CELLS};
    rightCellsDistances = new int[4]{NO_CELLS};
    next = nullptr;
}

ShapeState::~ShapeState() {
	delete[] values;
    delete[] bottomCellsDistances;
    delete[] leftCellsDistances;
    delete[] rightCellsDistances;
}

ShapeState* ShapeState::getNext() {
	return next;
}

void ShapeState::setNext(ShapeState* in_next) {
	next = in_next;
}

bool ShapeState::getValue(int x, int y) {
	return *(values + x + y * 4);
}

void ShapeState::setValue(int x, int y, bool value) {
	*(values + x + y * 4) = value;
}

void ShapeState::countBottomCellsDistances() {
    for (int i = 0; i < 4; i++) {
        int distance = NO_CELLS;
        for (int j = 3; j >= 0 && distance == NO_CELLS; j--) {
            if (getValue(i, j)){
                distance = j + 1;
            }
        }
        bottomCellsDistances[i] = distance;
    }
}

void ShapeState::countLeftCellsDistances() {
    for (int i = 0; i < 4; i++) {
        int distance = NO_CELLS;
        for (int j = 0; j < 4 && distance == NO_CELLS; j++) {
            if(getValue(j, i)) {
                distance = j - 1;
            }
        }
        leftCellsDistances[i] = distance;
    }
}

void ShapeState::countRightCellsDistances() {
    for (int i = 0; i < 4; i++) {
        int distance = NO_CELLS;
        for (int j = 3; j >= 0 && distance == NO_CELLS; j-- ) {
            if (getValue(j, i)) {
                distance = j + 1;
            }
        }
        rightCellsDistances[i] = distance;
    }
}

void ShapeState::countCellsDistances() {
    countBottomCellsDistances();
    countLeftCellsDistances();
    countRightCellsDistances();
}

int ShapeState::getBottomCellsDistance(int index){
    return bottomCellsDistances[index];
}

int ShapeState::getLeftCellsDistance(int index){
    return leftCellsDistances[index];
}

int ShapeState::getRightCellsDistance(int index){
    return rightCellsDistances[index];
}