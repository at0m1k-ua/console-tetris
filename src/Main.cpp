#include <iostream>
#include <ncurses.h>
#include <sys/time.h>
#include "ShapeLoader.h"
#include "GameField.h"
#include "Gui.h"
#include "ActiveShape.h"
#include <unistd.h>

const int EXIT_KEY = 27; // ASCII code of Esc

using namespace std;

long getTimeMillis() {
    struct timeval time_now{};
    gettimeofday(&time_now, nullptr);
    return (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
}

void handle(Gui* gui, ActiveShape* activeShape, GameField* gameField, ShapeLoader* loader) {
    if (activeShape->touchesBottom()) {
        gameField->mergeActiveShape(activeShape);
        activeShape->generateNextShape(loader);
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
    auto* activeShape = new ActiveShape(gamefield, loader);
    auto* gui = new Gui(gamefield, activeShape);
    gui->init();
    curs_set(0);
    int choice;
    bool loop = true;
    while(loop) {
        choice = wgetch(gui->getFrame());
        if(gamefield->isGameOver()) {
            gui->displayLose();
            sleep(5);
            loop = false;
        }
        if(gamefield->isGameWon()) {
            gui->displayWin();
            sleep(5);
            loop = false;
        }
        switch (choice){
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
                handle(gui, activeShape, gamefield, loader);
                break;
            case EXIT_KEY:
                loop = false;
                break;
            default:
                gui->updateScreen();
                break;
        }
    }
    gui->end();
    return 0;
}
