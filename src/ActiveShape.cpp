#include "ActiveShape.h"

ActiveShape::ActiveShape(GameField* m_gm, Gui* m_gui, Shape *shape, int m_color, int m_x)
    : gamefield(m_gm), gui(m_gui), StatesList(shape->getCurrentState()), color(m_color), x(m_x)
{
    y = 0;
}

int ActiveShape::getColor() {
    return color;
}

void ActiveShape::moveDown() {

}

void ActiveShape::moveLeft() {
    
}

void ActiveShape::moveRight() {
    
}

void ActiveShape::setNextState() {

}

bool ActiveShape::touchesGameFieldState() {
    return false;
}