#pragma once
#ifndef _GUI_H_
#define _GUI_H_

#include <ncurses.h>
#include "GameField.h"

class ActiveShape;
class GameField;

class Gui {
	int screen_size_x,
		screen_size_y,
	    frame_size_x,
	    frame_size_y,
	    frame_x,
	    frame_y;
	WINDOW* frame;
    GameField* gameField;
    ActiveShape* activeShape;
    bool messageLose[5][42] = {
        {false, true, true , false, false, true, true, true , false, false, true, false, false, false, true, false, true, true, true , true, false, false, false, true, true, false, false, true, false, false, false, true, false, true, true, true , true, false, true, true, true, false},
        {true, false, false , false, false, true, false, false , true, false, true, true, false , true, true, false, true, false, false ,false, false, false, true, false, false, true, false, true, false, false , false, true, false, true, false, false ,false, false, true, false, false, true},
        {true, false, true, true, false, true, false, false ,true, false, true, false, true , false, true, false, true, true, true, true, false, false, true, false , false, true, false, true, false, false, false, true, false, true, true, true, true, false, true, true, true, false},
        {true, false , false, true, false, true, true, true, true, false, true, false , false, false, true, false, true, false , false, false, false, false, true, false, false, true, false, false, true , false, true, false, false, true, false , false, false, false, true, false , false, true},
        {false, true, true, false, false, true, false , false, true, false, true, false, false, false, true, false, true, true, true, true, false, false, false, true, true, false, false, false, false, true, false, false, false, true, true, true, true, false, true, false, false, true}
    };  
    bool messageWin[5][30] = {
        {true, false, false, false, true, false, false, true, true, false, false, true, false, false, true, false, false, true, false, false , false, true, false, true, false, true, false, false, false, true},
        {false, true, false , true, false, false, true, false,  false, true, false, true, false, false, true, false, false, true, false, false, false, true, false, true, false, true, true, false, false, true},
        {false, false, true, false, false, false, true, false, false, true, false, true, false, false , true, false, false, true, false, true, false, true, false, true, false, true, false, true, false, true},  
        {false, false, true, false, false, false, true, false ,false, true, false, true, false, false, true, false, false, false, true , false, true, false, false, true, false, true, false , false, true, true},
        {false, false , true, false, false, false, false, true, true, false, false, false, true, true, false, false, false, false, true, false, true, false, false, true, false, true, false, false, false, true}
    };

    void updateFrame();
    void fillCell(int x, int y);
    void fillCell(WINDOW* win, int x, int y);
    void paint(int x, int y, int color);
    void eraseActiveShape();
    void clearFrame();

public:
	Gui(GameField* gameField, ActiveShape* activeShape);
	WINDOW* getFrame();
	void init();
	void updateScreen();
    void drawGameField();
    void drawActiveShape();
    void moveActiveShapeLeft();
    void moveActiveShapeRight();
    void moveActiveShapeDown();
    void rotateActiveShape();
    void setGameField(GameField* gameField);
	void displayResult(bool flag);
	void displayWin();
	void displayLose();
    bool isGameOver();
    bool isGameWon();
    void drawLose(int size_x, int size_y, bool* letter);
    void drawWin(int size_x, int size_y, bool* letter);
    const static int NUM_COLORS = 6;
    void end();
};

#endif
