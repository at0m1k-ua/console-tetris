#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "ShapeState.h"

class Shape
{
	ShapeState* currentState;
	ShapeState* rotateState(ShapeState* initialState);
	void createListOfRotatedStates(ShapeState* firstShapeState, int rotatesCount);

public:
	Shape(ShapeState* shapeStateList, int rotatesCount);
	void setNextState();
	ShapeState* getCurrentState();
};

#endif
