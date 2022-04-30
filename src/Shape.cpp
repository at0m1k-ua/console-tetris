#include "Shape.h"

Shape::Shape(ShapeState* shapeStateList, int in_color) {
	currentState = shapeStateList;
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