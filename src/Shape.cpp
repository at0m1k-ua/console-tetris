#include "Shape.h"

Shape::Shape() {
        currentState = nullptr;
        color = 0;
}

Shape::Shape(ShapeState* firstShapeState, int in_color) {
	currentState = firstShapeState;
	color = in_color;
}

void Shape::rotate() {
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
	int newJ;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			switch (j) {
				case 0:
					newJ = 2;
					break;
				case 2:
					newJ = 0;
					break;
				default:
					newJ = j;
			}
			rotatedState->setValue(i, newJ, initialState->getValue(j, i));
		}
	}
	return rotatedState;
}
