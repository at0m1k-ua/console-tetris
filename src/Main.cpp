#include "Gui.h"

int main(int argc, char** argv) {

	Gui* gui = new Gui(10, 10);
	gui->init();
	while (true) {
		gui->updateScreen();
		getch();
	}

	delete gui;
	return 0;
}