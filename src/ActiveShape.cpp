#include "ActiveShape.h"
#include "ncurses.h"

ActiveShape::ActiveShape(GameField* m_gm, Gui* m_gui, Shape *shape, int m_color, int m_x, int m_y)
{
    gamefield = m_gm;
    gui = m_gui;
    statesList = shape->getCurrentState();
    color = m_color;
    x = m_x;
    y = m_y;

}

int ActiveShape::getColor() {
    return color;
}

void ActiveShape::moveDown() {
    if(y < gamefield->getSizeY() - 3) {
        y++;
    }
}

void ActiveShape::moveLeft() {
    if(x > 0) {
        x--;
    }
}

void ActiveShape::moveRight() {
    if(x < gamefield->getSizeX() - 2) {
        x++;
    }
}

void ActiveShape::setNextState() {

}

bool ActiveShape::touchesGameFieldState() {
    return false;
}

int ActiveShape::getX() {
    return x;
}

int ActiveShape::getY() {
    return y;
}

ShapeState* ActiveShape::getStatesList() {
    return statesList;
}