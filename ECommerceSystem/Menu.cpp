#include "Menu.h"

Menu::Menu()
{
	initLoginMenu();
	initMainMenu();
}

void Menu::initLoginMenu()
{
	loginMenu.append("====================================Login Menu====================================\n");
	loginMenu.append("Press 1 to signup as a new user.\n");
	loginMenu.append("Press 2 to login to an existing account.\n");
	loginMenu.append("Press 3 to exit from the app.\n");
	loginMenu.append("==================================================================================\n");
}

void Menu::initMainMenu()
{
	mainMenu.append("====================================Main Menu====================================\n");
	mainMenu.append("Press 1 to add a new product for sale.\n");
	mainMenu.append("Press 2 to search for a product.\n");
	mainMenu.append("Press 3 to add a product to your cart.\n");
	mainMenu.append("Press 4 to view your cart.\n");
	mainMenu.append("Press 5 to checkout.\n");
	mainMenu.append("Press 6 to write a feedback to other user.\n");
	mainMenu.append("Press 7 to view your products for sale.\n");
	mainMenu.append("Press 8 to view your received feedbacks.\n");
	mainMenu.append("Press 9 to view the orders you've made.\n");
	mainMenu.append("Press 10 to view all the users in the shop.\n");
	mainMenu.append("Press 11 to logout and return back to login menu.\n");
	mainMenu.append("Press 12 to exit from the app.\n");
	mainMenu.append("=================================================================================\n");
}

const string& Menu::loginMenuToString() const
{
	return loginMenu;
}

const string& Menu::mainMenuToString() const
{
	return mainMenu;
}