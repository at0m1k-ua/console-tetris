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
    int **field;

public:

	GameField(int gf_size_x, int gf_size_y);
	~GameField();
    int getSizeX();
    int getSizeY();
    int getFieldValue(int x, int y);
    void mergeActiveShape(ActiveShape *shape);
};

#endif