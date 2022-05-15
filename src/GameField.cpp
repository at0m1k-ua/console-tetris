#include "GameField.h"

GameField::GameField(int gf_size_x, int gf_size_y) {
    field = new int*[gf_size_x];
    for(int i = 0; i < gf_size_y; i++)
        field[i] = new int[gf_size_x]{0};
}
void GameField::obj_fall()
{
}
void GameField::obj_stop()
{
}

