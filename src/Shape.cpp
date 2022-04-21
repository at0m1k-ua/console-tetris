#include "Shape.h"

Shape::Shape(int in_statesNumber, ShapeState* in_states, int in_currentState) {
	statesNumber = in_statesNumber;
	states = in_states;
	currentState = in_currentState;
}

Shape::Shape(int in_statesNumber, ShapeState* in_states) : Shape::Shape(in_statesNumber, in_states, 0) {}