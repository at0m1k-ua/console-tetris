#pragma once
#ifndef _SHAPESTATE_H_
#define _SHAPESTATE_H_

class ShapeState {

	bool* values;
    int* bottomCellsDistances;
    int* leftCellsDistances;
    int* rightCellsDistances;
	ShapeState* next;
    void countBottomCellsDistances();
    void countLeftCellsDistances();
    void countRightCellsDistances();

public:
	ShapeState();
	~ShapeState();
	ShapeState* getNext();
	void setNext(ShapeState* in_next);
	bool getValue(int x, int y);
	void setValue(int x, int y, bool value);
    int getBottomCellsDistance(int index);
    int getLeftCellsDistance(int index);
    int getRightCellsDistance(int index);
    void countCellsDistances();
};

#endif