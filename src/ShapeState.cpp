#include "ShapeState.h"

ShapeState::ShapeState() {
	bool initialValues[16] = {false};
	values = initialValues;
}

ShapeState::ShapeState(bool* in_values) {
	values = in_values;
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