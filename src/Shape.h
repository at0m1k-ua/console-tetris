#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "ShapeState.h"

class Shape
{
	ShapeState* currentState;
	int color;
	ShapeState* rotateState(ShapeState* initialState);
	void createListOfRotatedStates(ShapeState* firstShapeState, int rotatesCount);

public:
    Shape();
	Shape(ShapeState* shapeStateList, int rotatesCount, int in_color);
	void setNextState();
	ShapeState* getCurrentState();
	void setColor(int in_color);
	int getColor();
};

#endif
