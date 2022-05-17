#pragma once
#ifndef _ACTIVESHAPE_H_
#define _ACTIVESHAPE_H_
#include "Gui.h"
#include "Shape.h"
#include "GameField.h"
#include "ShapeLoader.h"

class ActiveShape {
    GameField* gamefield;
    Gui* gui;
    ShapeState* StatesList;
    int color;
    int x;
    int y;

public:
    ActiveShape(GameField* m_gm, Gui* m_gui, Shape *shape, int m_color, int m_x);
    int getColor();
    void moveLeft();
    void moveRight();
    void moveDown();
    void setNextState();
    bool touchesGameFieldState();
};

#endif