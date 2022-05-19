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
    if (!touchesLeft()) {
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

int ActiveShape::getX() {
    return x;
}

int ActiveShape::getY() {
    return y;
}

ShapeState* ActiveShape::getStatesList() {
    return statesList;
}
bool ActiveShape::touchesBottom() {
    return false;
}

bool ActiveShape::touchesLeft() {
    return touchesLeft(statesList);
}

bool ActiveShape::touchesLeft(ShapeState* state) {
    for (int cell_y = 0; cell_y < 4; cell_y++) {
        int cell_x = state->getLeftCellsDistance(cell_y);
        if (
                x + cell_x < -1 // (-1)|XX is possible
                || (x + cell_x >= 0 && gamefield->getFieldValue(x + cell_x, y + cell_y) != 0) // cell is colored
                ) {
            return true;
        }
    }
    return false;
}

bool ActiveShape::touchesRight() {
    return false;
}