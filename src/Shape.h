#pragma once
#include "ShapeState.h"

class Shape {
	int statesNumber;
	ShapeState* states;
	int currentState;

public:
	Shape(int in_statesNumber, ShapeState* in_states, int in_currentState);
	Shape(int in_statesNumber, ShapeState* in_states);
	void rotate();
};