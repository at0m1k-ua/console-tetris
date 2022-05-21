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
    Shape* currentShape;
    int x, y, color;

    public:
    ActiveShape(GameField* m_gm, ShapeLoader* loader);
    int getColor();
    void moveLeft();
    void moveRight();
    void moveDown();
    void rotate();
    int getX();
    int getY();
    ShapeState* getCurrentState();
    bool touchesBottom();
    bool touchesBottom(ShapeState* state);
    bool touchesLeft();
    bool touchesLeft(ShapeState *state);
    bool touchesRight();
    bool touchesRight(ShapeState *state);
    bool conflictsWithGameField(ShapeState *state);
    void generateNextShape(ShapeLoader* loader);
};

#endif