#include "Shape.h"

Shape::Shape(ShapeState* firstShapeState, int rotatesCount) {
	currentState = firstShapeState;
	createListOfRotatedStates(firstShapeState, rotatesCount);
}

void Shape::createListOfRotatedStates(ShapeState* firstShapeState, int rotatesCount) {
	ShapeState* lastRotation = firstShapeState;
    lastRotation->countCellsDistances();
	for (int i = 1; i < rotatesCount; i++) {
		ShapeState* newRotatedState = rotateState(lastRotation);
        newRotatedState->countCellsDistances();
		lastRotation->setNext(newRotatedState);
		lastRotation = newRotatedState;
	}
	lastRotation->setNext(firstShapeState);
}

void Shape::setNextState() {
	currentState = currentState->getNext();
}

ShapeState* Shape::getCurrentState() {
	return currentState;
}

ShapeState* Shape::rotateState(ShapeState* initialState) {
	ShapeState* rotatedState = new ShapeState();
	int newI;
	for (int i = 0; i < 4; i++) {
		switch (i) {
				case 0:
					newI = 2;
					break;
				case 2:
					newI = 0;
					break;
				default:
					newI = i;
			}
		for (int j = 0; j < 4; j++) {
			
			rotatedState->setValue(newI, j, initialState->getValue(j, i));
		}
	}
	return rotatedState;
}
