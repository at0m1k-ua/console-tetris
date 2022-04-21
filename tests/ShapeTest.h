#pragma once
#include "../src/ShapeState.h"

class ShapeTest{
	ShapeState testShapeStates[4];

public:
	ShapeTest();

	void testGetCurrentState();
	void testRotate();
	void testAll();
};