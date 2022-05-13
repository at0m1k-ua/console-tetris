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
