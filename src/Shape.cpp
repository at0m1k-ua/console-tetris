#include "Shape.h"

Shape::Shape() {
        currentState = nullptr;
        color = 0;
}

Shape::Shape(ShapeState* firstShapeState, int rotatesCount, int in_color) {
	currentState = firstShapeState;
	color = in_color;
	createListOfRotatedStates(firstShapeState, rotatesCount);
}

void Shape::createListOfRotatedStates(ShapeState* firstShapeState, int rotatesCount) {
	ShapeState* lastRotation = firstShapeState;
	for (int i = 0; i < rotatesCount; i++) {
		ShapeState* newRotatedState = rotateState(lastRotation);
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

void Shape::setColor(int in_color) {
	color = in_color;
}

int Shape::getColor() {
	return color;
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
