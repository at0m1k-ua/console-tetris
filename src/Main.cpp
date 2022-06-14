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

// get current time in milliseconds
long getTimeMillis() {
    struct timeval time_now{};
    gettimeofday(&time_now, nullptr);
    return (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
}

// active shape lifetime is time from creation until touch the bottom
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
    // check if one second from last fall time is passed
    if (currentTime - fallPeriod > lastFallTime) {
        lastFallTime = currentTime;
        gui->moveActiveShapeDown();
    }
}

bool handleGamdEnd(GameField* gameField, Gui* gui) {
    // game end is GameOver or GameWon events
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
        case ERR: // if no key is pressed
            handleActiveShapeLifetimeEnd(activeShape, gameField, loader);
            moveDownEachSecond(gui);
            break;
        case EXIT_KEY: // if ESC key is pressed
            return false;
        default: // if terminal size is changed
            gui->updateScreen();
            break;
    }
    return true;
}

int main() {
    auto* loader = new ShapeLoader();
    // load shapes from shapes.conf file
    loader->load();
    // create game field with given size
    auto* gameField = new GameField(15, 20);
    // create active shape with random shape from loader
    auto* activeShape = new ActiveShape(gameField, loader);
    // create gui handler to draw game field and active shape states
    auto* gui = new Gui(gameField, activeShape);
    gui->init();
    int choice; // variable for pressed key
    while (handleGamdEnd(gameField, gui) && // check if conditions for game end is met
           handleKeyPress(choice, gui, activeShape, gameField, loader)) { // check if ESC is not pressed
        choice = wgetch(gui->getFrame()); // get pressed key
    }
    gui->end();
    return 0;
}
