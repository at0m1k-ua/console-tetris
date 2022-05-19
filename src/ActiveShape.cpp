#include "ActiveShape.h"

ActiveShape::ActiveShape(GameField* m_gm, Shape *shape, int m_color, int m_x, int m_y)
{
    gamefield = m_gm;
    statesList = shape->getCurrentState();
    color = m_color;
    x = m_x;
    y = m_y;

}

int ActiveShape::getColor() {
    return color;
}

void ActiveShape::moveDown() {
    if(!touchesBottom()) {
        y++;
    }
}

void ActiveShape::moveLeft() {
    if (!touchesLeft()) {
        x--;
    }
}

void ActiveShape::moveRight() {
    if (!touchesRight()) {
        x++;
    }
}

void ActiveShape::rotate() {
    if (!conflictsWithGameField(statesList->getNext())) {
        statesList = statesList->getNext();
    }
}

int ActiveShape::getX() {
    return x;
}

int ActiveShape::getY() {
    return y;
}

ShapeState* ActiveShape::getCurrentState() {
    return statesList;
}
bool ActiveShape::touchesBottom() {
    return touchesBottom(statesList);
}

bool ActiveShape::touchesBottom(ShapeState* state) {
    for (int cell_x = 0; cell_x < 4; cell_x++) {
        int cell_y = state->getBottomCellsDistance(cell_x); // relative to shape
        if (cell_y != ShapeState::NO_CELLS) {
            int gf_cell_x = x + cell_x; // relative to game field
            int gf_cell_y = y + cell_y;
            if (gf_cell_y >= gamefield->getSizeY() || gamefield->getFieldValue(gf_cell_x, gf_cell_y) != 0) {
                return true;
            }
        }
    }
    return false;
}

bool ActiveShape::touchesLeft() {
    return touchesLeft(statesList);
}

bool ActiveShape::touchesLeft(ShapeState* state) {
    for (int cell_y = 0; cell_y < 4; cell_y++) {
        int cell_x = state->getLeftCellsDistance(cell_y); // relative to shape
        if (cell_x != ShapeState::NO_CELLS) {
            int gf_cell_x = x + cell_x; // relative to game field
            int gf_cell_y = y + cell_y;
            if (gf_cell_x < 0 || gamefield->getFieldValue(gf_cell_x, gf_cell_y) != 0) {
                return true;
            }
        }
    }
    return false;
}

bool ActiveShape::touchesRight() {
    return touchesRight(statesList);
}

bool ActiveShape::touchesRight(ShapeState* state) {
    for (int cell_y = 0; cell_y < 4; cell_y++) {
        int cell_x = state->getRightCellsDistance(cell_y); // relative to shape
        if (cell_x != ShapeState::NO_CELLS) {
            int gf_cell_x = x + cell_x; // relative to game field
            int gf_cell_y = y + cell_y;
            if (gf_cell_x >= gamefield->getSizeX() || gamefield->getFieldValue(gf_cell_x, gf_cell_y) != 0) {
                return true;
            }
        }
    }
    return false;
}

bool ActiveShape::conflictsWithGameField(ShapeState* state) {
    for (int shape_y = 0; shape_y < 4; shape_y++) {
        for(int shape_x = 0; shape_x < 4; shape_x++) {
            if (state->getValue(shape_x, shape_y)) {
                // shape_x is relative to shape state
                int gf_shape_x = x + shape_x, // relative to game field
                    gf_shape_y = y + shape_y;
                if (gf_shape_x < 0 || gf_shape_x >= gamefield->getSizeX()
                 || gf_shape_y < 0 || gf_shape_y >= gamefield->getSizeY()
                 || gamefield->getFieldValue(gf_shape_x, gf_shape_y) != 0){
                    return true;
                }
            }
        }
    }

    return false;
}