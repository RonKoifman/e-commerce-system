#ifndef __MENU_H
#define __MENU_H

#include "Utils.h"

class Menu
{
private:
	string loginMenu;
	string mainMenu;

public:
	Menu();
	const string& loginMenuToString() const;
	const string& mainMenuToString() const;

private:
	void initLoginMenu();
	void initMainMenu();
};

#endif // __MENU_H