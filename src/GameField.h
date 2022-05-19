#pragma once
#ifndef _GAMEFIELD_H_
#define _GAMEFIELD_H_

#include "ShapeState.h"
#include "ActiveShape.h"
#include "Gui.h"

class GameField
{

	int gf_size_x;
	int gf_size_y;


public:
    int **field;
	GameField(int gf_size_x, int gf_size_y);
	~GameField();
    int getSizeX();
    int getSizeY();
    int getFieldValue(int x, int y);
    void setFieldValue(int x, int y, int value);
    void mergeActiveShape(ActiveShape *state);
};

#endif