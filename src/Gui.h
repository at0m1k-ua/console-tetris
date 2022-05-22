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
    bool letterG[5][4] = {
        {false, true, true , false},
        {true, false, false , false},
        {true, false, true, true},
        {true, false , false, true},
        {false, true, true, false }
    };
    bool letterA[5][4] = {
        {true, true, true , false},
        {true, false, false , true},
        {true, false, false ,true},
        {true, true, true, true},
        {true, false , false, true},
    };
    bool letterM[6][5] = {
        {true, false, false, false, true},
        {true, true, false , true, true},
        {true, false, true , false, true},
        {true, false, true , false, true},  
        {true, false , false, false, true},
        {true, false, false, false, true}
    };
    bool letterE[5][4] = {
        {true, true, true , true},
        {true, false, false ,false},
        {true, true, true, true},
        {true, false , false, false},
        {true, true, true, true}
    };
    bool letterO[6][5] = {
        {false, true, true, true, false},
        {true, false, false , false, true},
        {true, false, false, false, true},
        {true, false, false , false, true},  
        {true, false , false, false, true},
        {false, true, true, true, false}
    };
     bool letterV[6][5] = {
        {true, false, false, false, true},
        {true, false, false , false, true},
        {true, false, false, false, true},
        {true, false, false , false, true},  
        {false, true , false, true, false},
        {false, true, true, false, false}
    };
    bool letterR[6][5] = {
        {true, true, true, true, false},
        {true, false, false , false, true},
        {true, false, false, false, true},
        {true, true, true, true, false},  
        {true, false , false, false, true},
        {true, false, false, false, true}
    };
    bool letterY[6][5] = {
        {true, false, false, false, true},
        {false, true, false , true, false},
        {false, false, true, false, false},
        {false, false, true, false, false},  
        {false, false , true, false, false},
        {false, false, true, false, false}
    };
    bool letterU[6][5] = {
        {true, false, false, false, true},
        {true, false, false , false, true},
        {true, false, false, false, true},
        {true, false, false , false, true},  
        {true, false , false, false, true},
        {false, true, true, true, false}
    };
    bool letterW[6][5] = {
        {true, false, false, false, true},
        {true, false, false , false, true},
        {true, false, false, false, true},
        {true, false, true, false, true},  
        {false, true , false, true, false},
        {false, true, false, true, false}
    };
    bool letterI[6][5] = {
        {false, false, true, false, false},
        {false, false, true , false, false},
        {false, false, true, false, false},
        {false, false, true , false, false},  
        {false, false , true, false, false},
        {false, false, true, false, false}
    };
    bool letterN[5][5] = {
        {true, false, false , false, true},
        {true, true, false, false, true},
        {true, false, true , false, true},  
        {true, false , false, true, true},
        {true, false, false, false, true}
    };
    bool messageLose[5][42] = {
        {false, true, true , false, false, true, true, true , false, false, true, false, false, false, true, false, true, true, true , true, false, false, false, true, true, false, false, true, false, false, false, true, false, true, true, true , true, false, true, true, true, false}, 
        {true, false, false , false, false, true, false, false , true, false, true, true, false , true, true, false, true, false, false ,false, false, false, true, false, false, true, false, true, false, false , false, true, false, true, false, false ,false, false, true, false, false, true},
        {true, false, true, true, false, true, false, false ,true, false, true, false, true , false, true, false, true, true, true, true, false, false, true, false , false, true, false, true, false, false, false, true, false, true, true, true, true, false, true, true, true, false},
        {true, false , false, true, false, true, true, true, true, false, true, false , false, false, true, false, true, false , false, false, false, false, true, false, false, true, false, false, true , false, true, false, false, true, false , false, false, false, true, false , false, true},
        {false, true, true, false, false, true, false , false, true, false, true, false, false, false, true, false, true, true, true, true, false, false, false, true, true, false, false, false, false, true, false, false, false, true, true, true, true, false, true, false, false, true}
    };

    bool messageWin[5][30] = {
        {true, false, false, true, false, false, true, false, false , false, true, false, true, false, true, true, false, false, true},
        {true, false, false, true, false, false, true, false, false, false, true, false, true, false, true, true, false, false, true},
        {true, false, false , true, false, false, true, false, true, false, true}, false, true, false, true, false, true , false, true},  
        {true, false , false, true, false, false, false, true , false, true, false, false, true, false, true, false , false, true, true},
        {false, true, true, false, false, false, false, true, false, true, false, false, true, false, true, false, false, false, true}
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
    void drawLose(bool letter[][42]);
    const static int NUM_COLORS = 6;
    void end();
};

#endif
