#pragma once
#include "ShapeState.h"

class Shape {
	int statesNumber;
	ShapeState* states;
	int currentStateNumber;

public:
	Shape(int in_statesNumber, ShapeState* in_states);
	Shape(int in_statesNumber, ShapeState* in_states, int in_currentState);
	ShapeState getCurrentState();
	void rotate();
};