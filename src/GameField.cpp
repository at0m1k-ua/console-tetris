#include "GameField.h"
#include "ActiveShape.h"
#include <iostream>

GameField::GameField(int gf_size_x, int gf_size_y)
{
    this->gf_size_x = gf_size_x;
    this->gf_size_y = gf_size_y;
    try
    {
        field = new int *[gf_size_y];
    }
    catch (std::bad_alloc &xa)
    {
        std::cout << "Allocation failure.\n";
        return;
    }
    for (int i = 0; i < gf_size_y; i++)
        field[i] = new int[gf_size_x]{0};
}

GameField::~GameField()
{
    for (int i = 0; i < gf_size_y; i++)
    {
        delete[] field[i];
    }
}
int GameField::getSizeX()
{
    return gf_size_x;
}

int GameField::getSizeY()
{
    return gf_size_y;
}
int GameField::getFieldValue(int x, int y)
{
    return field[y][x];
}

void GameField::setFieldValue(int x, int y, int value) {
    field[y][x] = value;
}

void GameField::mergeActiveShape(ActiveShape* shape) {
    for (int in_y = 0; in_y < 4; in_y++) {
        for(int in_x = 0; in_x < 4; in_x++) {
            if (shape->getCurrentState()->getValue(in_x, in_y)) {
                field[shape->getY() + in_y][shape->getX() + in_x] = shape->getColor();
            }
        }
    }
}

bool GameField::isGameOver() {
    for(int x = 0; x < gf_size_x; x++) {
        if(field[0][x]) {
            return true;
        }
    }
    return false;
}

bool GameField::isGameWon() {
    int count = 0;
    for(int y = 1; y < gf_size_y; y++) {
        for(int x = 0; x < gf_size_x; x++) {
            if(field[y][x]) {
                count++;
                if(count == (gf_size_x-2)) {
                    return true;
                }
            }
            if(!(x % (gf_size_x-2))) {
                count = 0;
            }
        }
    }
    return false;
}