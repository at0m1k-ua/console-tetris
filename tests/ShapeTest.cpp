#include "../src/Shape.h"
#include "ShapeTest.h"
#include <cassert>

ShapeTest::ShapeTest() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				testShapeStates[i].value[j][k] = (i == j && j == k);
			}
		}
	}
}

void ShapeTest::testGetCurrentState() {
	Shape shape(4, testShapeStates);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			assert(shape.getCurrentState().value[i][j] == (i == 0 && j == 0));
		}
	}
}

void ShapeTest::testRotate() {
	Shape shape(4, testShapeStates);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				assert(shape.getCurrentState().value[j][k] == (i % 4 == j && j == k));
			}
		}
		shape.rotate();
	}
}

void ShapeTest::testAll() {
	testGetCurrentState();
	testRotate();
}