#pragma once
#ifndef _SHAPETEST_H_
#define _SHAPETEST_H_
#include "../src/ShapeState.h"

class ShapeTest
{
	ShapeState testShapeStates[4];

public:
	ShapeTest();

	void testGetCurrentState();
	void testRotate();
	void testAll();
};

#endif