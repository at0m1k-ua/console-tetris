#pragma once
#ifndef _ACTIVESHAPE_H_
#define _ACTIVESHAPE_H_
#include "Shape.h"
#include "GameField.h"
#include "ShapeLoader.h"
#include "ShapeState.h"

class Gui;

class ActiveShape {
    GameField* gamefield;
    Gui* gui;
    ShapeState* statesList;
    int color;
    int x;
    int y;

    public:
    ActiveShape(GameField* m_gm, Gui* m_gui, Shape *shape, int m_color, int m_x, int m_y);
    int getColor();
    void moveLeft();
    void moveRight();
    void moveDown();
    void setNextState();
    bool touchesGameFieldState();
    int getX();
    int getY();
    ShapeState* getStatesList();
    bool touchesBottom();
    bool touchesLeft();
    bool touchesRight();
};

#endif