#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include "Gui.h"
#include "ActiveShape.h"
#include "GameField.h"

Gui::Gui(GameField* gameField, ActiveShape* activeShape) {
    this->gameField = gameField;
    this->activeShape = activeShape;
	frame_size_x = 2*gameField->getSizeX();
	frame_size_y = gameField->getSizeY();
}

void Gui::init() {
	initscr();
	cbreak();

	if (!has_colors()) {
		endwin();
		std::cout << "The terminal does not support colors" << std::endl;
	}
	start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_CYAN);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	init_pair(6, COLOR_BLACK, COLOR_MAGENTA);   

	frame = newwin(frame_size_y + 2, frame_size_x + 2, 0, 0);
    keypad(frame, true);
    nodelay(frame, TRUE);

	updateScreen();

}

void Gui::updateScreen() {
	clear();
	getmaxyx(stdscr, screen_size_y, screen_size_x);
	frame_y = (screen_size_y - frame_size_y) / 2 - 1;
	frame_x = (screen_size_x - frame_size_x) / 2 - 1;

	if (frame_x <= 0 || frame_y <= 0){
    	endwin();
    	std::cout << "Terminal window is too small" << std::endl;
    	exit(1);
    }

    mvwin(frame, frame_y, frame_x);
	box(frame, 0, 0);

    refresh();
    move(0, 0);
    drawGameField();
    drawActiveShape();
    updateFrame();
}

void Gui::updateFrame() {
    wrefresh(frame);
    move(0, 0);
}

void Gui::paint(int x, int y, int color) {
	switch(color) {
		case 0:
		fillCell(x, y);
		break;
		default:
		wattron(frame, COLOR_PAIR(color));
		fillCell(x, y);
		wattroff(frame, COLOR_PAIR(color));
	}
}

void Gui::fillCell(int x, int y) {
	mvwaddch(frame, y + 1, 2*x + 1, ' ');
	mvwaddch(frame, y + 1, 2*x + 2, ' ');
}

void Gui::fillCell(WINDOW* win,int x, int y) {
	mvwaddch(win, y + 1, 2*x + 1, ' ');
	mvwaddch(win, y + 1, 2*x + 2, ' ');
}

void Gui::drawActiveShape() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(activeShape->getCurrentState()->getValue(i, j)) {
				paint(i + activeShape->getX(), j + activeShape->getY(), activeShape->getColor());
			}
		}
	}
}

void Gui::eraseActiveShape() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(activeShape->getCurrentState()->getValue(i, j)) {
				paint(i + activeShape->getX(), j + activeShape->getY(), 0);
			}
		}
	}
}

WINDOW* Gui::getFrame() {
	return frame;
}
void Gui::drawGameField() {
    for(int i = 0; i < gameField->getSizeY(); i++) {
        for(int j = 0; j < gameField->getSizeX(); j++) {
            paint(j, i, gameField->getCellValue(j, i));
        }
    }
}

void Gui::moveActiveShapeLeft() {
    eraseActiveShape();
    activeShape->moveLeft();
    drawActiveShape();
    updateFrame();
}

void Gui::moveActiveShapeRight() {
    eraseActiveShape();
    activeShape->moveRight();
    drawActiveShape();
    updateFrame();
}

void Gui::moveActiveShapeDown() {
    eraseActiveShape();
    activeShape->moveDown();
    drawActiveShape();
    updateFrame();
}

void Gui::rotateActiveShape() {
    eraseActiveShape();
    activeShape->rotate();
    drawActiveShape();
    updateFrame();
}

void Gui::setGameField(GameField* gameField) {
    this->gameField = gameField;
}

void Gui::clearFrame() {
    wclear(frame);
    updateFrame();
}

void Gui::drawResult(int size_x, int size_y, bool* letter) {
	int msg_x = (screen_size_x/2 - size_x)/2;
    // we get half of msg_x because each cell is two characters
    int msg_y = (screen_size_y - size_y)/2;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < size_x; j++) {
			if(*(letter + size_x*i + j)) {
				fillCell(stdscr, j + (msg_x), i + (msg_y));
			}
		}
	}
}

void Gui::displayWin() {
	clearFrame();
	attron(COLOR_PAIR(3));
    drawResult(
            sizeof(messageWin[0])/sizeof(messageWin[0][0]),
            sizeof(messageWin)/sizeof(messageWin[0]),
            messageWin[0]);
	attroff(COLOR_PAIR(3));
	wrefresh(stdscr);
}

void Gui::displayLose() {
	clearFrame();
	attron(COLOR_PAIR(1));
    drawResult(
            sizeof(messageLose[0])/sizeof(messageLose[0][0]),
            sizeof(messageLose)/sizeof(messageLose[0]),
            messageLose[0]);
	attroff(COLOR_PAIR(1));
	wrefresh(stdscr);
}

bool Gui::isGameOver() {
    for(int x = 0; x < gameField->getSizeX(); x++) {
        if(gameField->getCellValue(x, 0)) {
            return true;
        }
    }
    return false;
}

bool Gui::isGameWon() {

    for(int y = 1; y < gameField->getSizeY(); y++) {
        bool flag = true;
        for(int x = 0; x < gameField->getSizeX(); x++)
            if(!gameField->getCellValue(x, y))
                flag = false;
        if (flag)
            return true;
    }
    return false;
}

void Gui::end() {
    endwin();
}

