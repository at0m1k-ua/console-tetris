#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "ShapeState.h"

class Shape
{
	int statesNumber;
	ShapeState *states;
	int currentStateNumber;

public:
	Shape(int in_statesNumber, ShapeState *in_states);
	Shape(int in_statesNumber, ShapeState *in_states, int in_currentState);
	ShapeState getCurrentState();
	void rotate();
};

#endif