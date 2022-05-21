#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <sys/time.h>
#include "ShapeLoader.h"
#include "Shape.h"
#include "GameField.h"
#include "Gui.h"
#include "ActiveShape.h"

using namespace std;

long getTimeMillis() {
    struct timeval time_now{};
    gettimeofday(&time_now, nullptr);
    return (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
}

void handle(Gui* gui, ActiveShape* activeShape, GameField* gameField, ShapeLoader* loader, bool* end) {
    if (activeShape->touchesBottom()) {
        gameField->mergeActiveShape(activeShape);
        activeShape->generateActiveShape(loader);
    }
    if(gameField->isGameOver()) {
        gui->clearFrame();
        gui->displayResult(false);
        *end = false;
    }
    else if(gameField->isGameWon()) {
        gui->clearFrame();
        gui->displayResult(true);
        *end = false;
    }
    const int fallPeriod = 1000;  //let it const for now
    static long lastFallTime = getTimeMillis();
    long currentTime = getTimeMillis();
    if (currentTime - fallPeriod > lastFallTime) {
        lastFallTime = currentTime;
        gui->moveActiveShapeDown();
    }
}

int main() {
    auto* loader = new ShapeLoader();
    loader->load();
    auto* gamefield = new GameField(15, 20);
    auto* gui = new Gui(gamefield);
    auto* activeShape = new ActiveShape(gamefield, loader);
    gui->setActiveShape(activeShape);
    gui->init();
    gui->updateScreen();
    int choice;
    curs_set(0);
    bool startGame = true;
    while((choice = wgetch(gui->getWin())) != KEY_F(2) && startGame) {
        switch (choice)
        {
        case KEY_DOWN:
            gui->moveActiveShapeDown();
            break;
        case KEY_LEFT:
            gui->moveActiveShapeLeft();
            break;
        case KEY_RIGHT:
            gui->moveActiveShapeRight();
            break;
        case KEY_UP:
            gui->rotateActiveShape();
            break;
        case ERR:
            handle(gui, activeShape, gamefield, loader, &startGame);
            break;
        default:
            gui->updateScreen();
            break;
        }
    }
    nodelay(gui->getWin(), FALSE);
    getch();
    endwin();

  return 0;
}
