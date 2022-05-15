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
void GameField::obj_fall()
{
}
void GameField::obj_stop()
{
}
