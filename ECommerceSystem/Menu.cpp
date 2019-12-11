#include "Menu.h"

void printLoginMenu()
{
	cout << "Press 1 to create a new seller account." << endl;
	cout << "Press 2 to create a new customer account." << endl;
	cout << "Press 3 to login as a seller." << endl;
	cout << "Press 4 to login as a customer." << endl;
	cout << "Press 5 to view all the customers in the shop." << endl;
	cout << "Press 6 to view all the sellers in the shop." << endl;
	cout << "Press 7 to exit." << endl;

	cout << "Your selection: ";
}

void printSellerMenu()
{
	cout << "Press 1 to add a new product to your account." << endl;
	cout << "Press 2 to search for a product." << endl;
	cout << "Press 3 to view your products." << endl;
	cout << "Press 4 to view your feedbacks." << endl;
	cout << "Press 5 to logout." << endl;
	cout << "Press 6 to exit." << endl;

	cout << "Your selection: ";
}

void printCustomerMenu()
{
	cout << "Press 1 to search for a product." << endl;
	cout << "Press 2 to add product to your cart." << endl;
	cout << "Press 3 to view your cart." << endl;
	cout << "Press 4 to checkout." << endl;
	cout << "Press 5 to write a feedback to a seller." << endl;
	cout << "Press 6 to logout." << endl;
	cout << "Press 7 to exit." << endl;

	cout << "Your selection: ";
}