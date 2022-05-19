#pragma once
#ifndef _ACTIVESHAPE_H_
#define _ACTIVESHAPE_H_

#include "Shape.h"
#include "ShapeLoader.h"
#include "ShapeState.h"
#include "GameField.h"

class GameField;

class ActiveShape {
    GameField* gamefield;
    ShapeState* statesList;
    int color;
    int x;
    int y;

    public:
    ActiveShape(GameField* m_gm, Shape *shape, int m_color, int m_x, int m_y);
    int getColor();
    void moveLeft();
    void moveRight();
    void moveDown();
    void rotate();
    int getX();
    int getY();
    ShapeState* getCurrentState();
    bool touchesBottom();
    bool touchesBottom(ShapeState *);
    bool touchesLeft();
    bool touchesLeft(ShapeState *state);
    bool touchesRight();
    bool touchesRight(ShapeState *state);
    bool conflictsWithGameField(ShapeState *state);
};

#endif