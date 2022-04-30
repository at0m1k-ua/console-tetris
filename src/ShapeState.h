#pragma once
#ifndef _SHAPESTATE_H_
#define _SHAPESTATE_H_

class ShapeState {
	
	bool* values;
	ShapeState* next;

public:
	ShapeState();
	ShapeState(bool* in_values);
	ShapeState* getNext();
	void setNext(ShapeState* in_next);
	bool getValue(int x, int y);
	void setValue(int x, int y, bool value);
};

#endif