#include "Menu.h"

void Menu::displayLoginMenu()
{
	cout << "====================================Login Menu====================================" << endl;
	cout << "Press 1 to signup as a new user." << endl;
	cout << "Press 2 to login to an existing account." << endl;
	cout << "Press 3 to exit from the app." << endl;
	cout << "==================================================================================" << endl;
}

void Menu::displayMainMenu()
{
	cout << "====================================Main Menu====================================" << endl;
	cout << "Press 1 to add a new product for sale." << endl;
	cout << "Press 2 to search for a product." << endl;
	cout << "Press 3 to add a product to your cart." << endl;
	cout << "Press 4 to view your cart." << endl;
	cout << "Press 5 to checkout." << endl;
	cout << "Press 6 to write a feedback to other user." << endl;
	cout << "Press 7 to view your products for sale." << endl;
	cout << "Press 8 to view your received feedbacks." << endl;
	cout << "Press 9 to view the orders you've made." << endl;
	cout << "Press 10 to view all the users in the shop." << endl;
	cout << "Press 11 to logout and return back to login menu." << endl;
	cout << "Press 12 to exit from the app." << endl;
	cout << "=================================================================================" << endl;
}