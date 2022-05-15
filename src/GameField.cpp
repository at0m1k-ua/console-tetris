#include "GameField.h"
#include <new>
#include <iostream>

GameField::GameField(int gf_size_x, int gf_size_y)
{
    this->gf_size_x = gf_size_x;
    this->gf_size_y = gf_size_y;
    try
    {
        field = new int *[gf_size_y];
    }
    catch (std::bad_alloc xa)
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
void GameField::obj_fall()
{
}
void GameField::obj_stop()
{
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