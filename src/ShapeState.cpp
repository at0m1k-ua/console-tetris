#include "ShapeState.h"

ShapeState::ShapeState() {
	values = new bool[16]{false};
}

ShapeState::~ShapeState() {
	delete[] values;
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