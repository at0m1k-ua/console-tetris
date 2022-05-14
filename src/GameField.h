#pragma once
#ifndef _GAMEFIELD_H_
#define _GAMEFIELD_H_


class GameField {
	int Field[gf_size_x][gf_size_y]);


public:
	GameField(int gf_size_x, int gf_size_y);
	void obj_fall();
	void obj_stop();
	void obj_change();
	void line_elimination();
};

#endif