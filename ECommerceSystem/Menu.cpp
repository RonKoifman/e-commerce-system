#include "Menu.h"

void Menu::printMainMenu()
{
	cout << "==================================== Main Menu ====================================" << endl;
	cout << "Press 1 to create a new seller account." << endl;
	cout << "Press 2 to create a new customer account." << endl;
	cout << "Press 3 to create a new seller-customer account." << endl;
	cout << "Press 4 to login to an existing account." << endl;
	cout << "Press 5 to view all the customers in the shop." << endl;
	cout << "Press 6 to view all the sellers in the shop." << endl;
	cout << "Press 7 to view all the seller-customers in the shop." << endl;
	cout << "Press 8 to exit from the app." << endl;

	cout << "Your selection: ";
}

void Menu::printSellerMenu()
{
	cout << "=================================== Seller Menu ===================================" << endl;
	cout << "Press 1 to add a new product to your account." << endl;
	cout << "Press 2 to search for a product." << endl;
	cout << "Press 3 to view your products." << endl;
	cout << "Press 4 to view your feedbacks." << endl;
	cout << "Press 5 to go back to previous menu." << endl;
	cout << "Press 6 to exit from the app." << endl;

	cout << "Your selection: ";
}

void Menu::printCustomerMenu()
{
	cout << "================================== Customer Menu ==================================" << endl;
	cout << "Press 1 to search for a product." << endl;
	cout << "Press 2 to add product to your cart." << endl;
	cout << "Press 3 to view your cart." << endl;
	cout << "Press 4 to checkout." << endl;
	cout << "Press 5 to write a feedback to a seller." << endl;
	cout << "Press 6 to go back to previous menu." << endl;
	cout << "Press 7 to exit from the app." << endl;

	cout << "Your selection: ";
}

void Menu::printSellerCustomerMenu()
{
	cout << "=============================== Seller-Customer Menu ===============================" << endl;
	cout << "Press 1 to view customer menu." << endl;
	cout << "Press 2 to view seller menu." << endl;
	cout << "Press 3 to go back to previous menu." << endl;
	cout << "Press 4 to exit from the app." << endl;

	cout << "Your selection: ";
}