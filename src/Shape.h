#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "ShapeState.h"

class Shape
{
	ShapeState* currentState;
	int color;

public:
        Shape();
	Shape(ShapeState* shapeStateList, int in_color);
	void rotate();
	ShapeState* getCurrentState();
	void setColor(int in_color);
	int getColor();
};

#endif
