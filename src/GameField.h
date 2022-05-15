#pragma once
#ifndef _GAMEFIELD_H_
#define _GAMEFIELD_H_

class GameField
{

	int gf_size_x;
	int gf_size_y;
	int **field;

public:
	GameField(int gf_size_x, int gf_size_y);
	~GameField();
	void obj_fall();
	void obj_stop();
    int getSizeX();
    int getSizeY();
    int getFieldValue(int x, int y);
};

#endif