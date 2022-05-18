#include "ShapeLoader.h"
#include "Shape.h"
#include "GameField.h"
#include "Gui.h"
#include "ActiveShape.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int main() {
    auto* loader = new ShapeLoader();
    loader->load();
    auto* gui = new Gui(20, 30);
    auto* gamefield = new GameField(20, 30);
    Shape *shape  = loader->getShape(1);
    auto* activeshape = new ActiveShape(gamefield, gui, shape, 1, 0, 0);
    gui->init();
    keypad(gui->getWin(), true);
    gui->drawActiveShape(activeshape);
    int choice;
    curs_set(0);
    while((choice = wgetch(gui->getWin())) != KEY_F(1)) {
        switch (choice)
        {
        case KEY_DOWN:
            gui->eraseActiveShape(activeshape);
            activeshape->moveDown();
            gui->drawActiveShape(activeshape);
            gui->updateFrame();
            break;
        case KEY_LEFT:
            gui->eraseActiveShape(activeshape);
            activeshape->moveLeft();
            gui->drawActiveShape(activeshape);
            gui->updateFrame();
            break;
        case KEY_RIGHT:
            gui->eraseActiveShape(activeshape);
            activeshape->moveRight();
            gui->drawActiveShape(activeshape);
            gui->updateFrame();
            break;
        default:
            break;
        }
    }
    getch();
    endwin();

  return 0;
}
