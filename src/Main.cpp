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

void handleActiveShapeLifetimeEnd(ActiveShape* activeShape, GameField* gameField, ShapeLoader* loader) {
    if (activeShape->touchesBottom()) {
        gameField->mergeActiveShape(activeShape);
        activeShape->generateNextShape(loader);
    }
}

void moveDownEachSecond(Gui* gui) {
    const int fallPeriod = 1000;  //let it const for now
    static long lastFallTime = getTimeMillis();
    long currentTime = getTimeMillis();
    if (currentTime - fallPeriod > lastFallTime) {
        lastFallTime = currentTime;
        gui->moveActiveShapeDown();
    }
}

bool handleGamdEnd(GameField* gameField, Gui* gui) {
    if(gameField->isGameOver()) {
        gui->displayLose();
        sleep(5);
        return false;
    }
    if(gameField->isGameWon()) {
        gui->displayWin();
        sleep(5);
        return false;
    }
    return true;
}

bool handleKeyPress(int choice,
                    Gui* gui,
                    ActiveShape* activeShape,
                    GameField* gameField,
                    ShapeLoader* loader) {
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
            handleActiveShapeLifetimeEnd(activeShape, gameField, loader);
            moveDownEachSecond(gui);
            break;
        case EXIT_KEY:
            return false;
        default:
            gui->updateScreen();
            break;
    }
    return true;
}

int main() {
    auto* loader = new ShapeLoader();
    loader->load();
    auto* gameField = new GameField(15, 20);
    auto* activeShape = new ActiveShape(gameField, loader);
    auto* gui = new Gui(gameField, activeShape);
    gui->init();
    int choice;
    while (handleGamdEnd(gameField, gui) &&
           handleKeyPress(choice, gui, activeShape, gameField, loader)) {
        choice = wgetch(gui->getFrame());
    }
    gui->end();
    return 0;
}
