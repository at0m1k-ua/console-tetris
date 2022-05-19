#include <iostream>
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

void handle(Gui* gui, ActiveShape* activeShape, GameField* gameField) {
    if (activeShape->touchesBottom()) {
        gameField->mergeActiveShape(activeShape);
    }

    const int fallPeriod = 1000;  //let it const for now
    static long lastFallTime = getTimeMillis();
    long currentTime = getTimeMillis();
    if (currentTime - fallPeriod > lastFallTime) {
        lastFallTime = currentTime;
        gui->eraseActiveShape();
        activeShape->moveDown();
        gui->drawActiveShape();
        gui->updateFrame();
    }
}

int main() {
    auto* loader = new ShapeLoader();
    loader->load();
    auto* gamefield = new GameField(15, 20);
    auto* gui = new Gui(gamefield);
    gamefield->setFieldValue(5, 8, 2);
    Shape *shape  = loader->getShape(0);
    auto* activeShape = new ActiveShape(gamefield, shape, 1, 0, 0);
    gui->setActiveShape(activeShape);
    gui->init();
    gui->updateScreen();
    int choice;
    curs_set(0);

    while((choice = wgetch(gui->getWin())) != KEY_F(1)) {
        switch (choice)
        {
        case KEY_DOWN:
            gui->eraseActiveShape();
            activeShape->moveDown();
            gui->drawActiveShape();
            gui->updateFrame();
            break;
        case KEY_LEFT:
            gui->eraseActiveShape();
            activeShape->moveLeft();
            gui->drawActiveShape();
            gui->updateFrame();
            break;
        case KEY_RIGHT:
            gui->eraseActiveShape();
            activeShape->moveRight();
            gui->drawActiveShape();
            gui->updateFrame();
            break;
        case KEY_UP:
            gui->eraseActiveShape();
            activeShape->rotate();
            gui->drawActiveShape();
            gui->updateFrame();
            break;
        case ERR:
            handle(gui, activeShape, gamefield);
            break;
        default:
            gui->updateScreen();
            break;
        }
    }
    endwin();

  return 0;
}
