#include "Shape.h"

Shape::Shape(int in_statesNumber, ShapeState* in_states, int in_currentStateNumber) {
	statesNumber = in_statesNumber;
	states = in_states;
	currentStateNumber = in_currentStateNumber;
}

Shape::Shape(int in_statesNumber, ShapeState* in_states) : Shape::Shape(in_statesNumber, in_states, 0) {}

void Shape::rotate() {
	if (currentStateNumber == statesNumber - 1) {
		currentStateNumber = 0;
	} else {
		currentStateNumber++;
	}
}

ShapeState Shape::getCurrentState() {
	return states[currentStateNumber];
}