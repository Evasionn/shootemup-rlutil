#pragma once
#include "rlutil.h"

using namespace std;
class Menu
{
public:
	Menu();
	bool callMenu(); // calls the menu
	bool callHelp(); // prints the help screen
	void printMenu(); // prints the menu screen
};

