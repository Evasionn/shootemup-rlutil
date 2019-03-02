#include "Menu.h"



Menu::Menu()
{
}

void Menu::printMenu() {
	rlutil::resetColor();
	rlutil::cls();
	rlutil::setColor(2);
	gotoxy(rlutil::tcols() / 2 - 5, rlutil::trows() / 2);
	cout << "N - New Game" << endl;
	rlutil::setColor(3);
	gotoxy(rlutil::tcols() / 2 - 5, rlutil::trows() / 2 + 1);
	cout << "F1 - How to Play" << endl;
	rlutil::setColor(4);
	gotoxy(rlutil::tcols() / 2 - 5, rlutil::trows() / 2 + 2);
	cout << "Q - Exit" << endl;
}

bool Menu::callMenu() {
	printMenu();
	while (true) {
		if (kbhit()) {
			int key = rlutil::getkey();
			if (key == rlutil::KEY_F1) { // F1 for the calling help screen
				if (callHelp()) {
					printMenu();
				}
			}
			else if (key == 'N' || key == 'n') return true; // true for a new game
			else if (key == 'Q' || key == 'q') return false; // false to exit game
			cout.flush();
		}
}

}


bool Menu::callHelp() {
	rlutil::cls();
	rlutil::setColor(11);
	gotoxy(rlutil::tcols() / 2 - 10, rlutil::trows() / 2 - 3);
	cout << "M - Your ship" << endl;
	rlutil::setColor(12);
	gotoxy(rlutil::tcols() / 2 - 10, rlutil::trows() / 2 - 2);
	cout << "Y - Enemy ship" << endl;
	gotoxy(rlutil::tcols() / 2 - 10, rlutil::trows() / 2  - 1);
	rlutil::setColor(14);
	cout << "o - Bullets" << endl;
	gotoxy(rlutil::tcols() / 2 - 10, rlutil::trows() / 2);
	rlutil::setColor(8);
	cout << "X - Obstacles" << endl;
	gotoxy(rlutil::tcols() / 2 - 10, rlutil::trows() / 2 + 3);
	rlutil::setColor(15);
	cout << "Use arrow keys or WASD to move your ship" << endl;
	gotoxy(rlutil::tcols() / 2 - 10, rlutil::trows() / 2 + 4);
	cout << "Use 'space' key to fire" << endl;
	gotoxy(rlutil::tcols() / 2 - 10, rlutil::trows() / 2 + 7);
	rlutil::setColor(0);
	rlutil::setBackgroundColor(15);
	cout << "Press 'B' to go back" << endl;
	while (true) {
		if (kbhit()) {
			int key = rlutil::getkey();
			if (key == 'B' || key == 'b') return true;
		}
	}
}