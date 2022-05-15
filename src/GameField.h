#pragma once
#ifndef _GAMEFIELD_H_
#define _GAMEFIELD_H_


class GameField {

	int** field;

public:
	GameField(int gf_size_x, int gf_size_y);
	void obj_fall();
	void obj_stop();
};

#endif