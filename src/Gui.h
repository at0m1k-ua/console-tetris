#pragma once
#ifndef _GUI_H_
#define _GUI_H_
#include <ncurses.h>
#include "ActiveShape.h"

class Gui {
	int screen_size_x,
		screen_size_y,
	    frame_size_x,
	    frame_size_y,
	    frame_x,
	    frame_y;
	WINDOW* frame;
public:
	Gui(int in_gf_size_x, int in_gf_size_y);
	WINDOW* getWin();
	void init();	
	void updateScreen();
	void updateFrame();
	void paint(int x, int y, int color);
	void fillCell(int x, int y);
	void drawActiveShape(ActiveShape* shape);
	void eraseActiveShape(ActiveShape* shape);
    void drawGameField(int **gameField);
};

#endif
