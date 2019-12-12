#include "Checkout.h"
#include "Customer.h"

Customer::Customer(char* username, char* password, Address address) // C'tor
	: username(nullptr), password(nullptr), cart(nullptr), orders(nullptr), address(address)
{
	setUsername(username);
	setPassword(password);

	// Initialize data members
	numOfProductsInCart = numOfOrders = 0;
}

Customer::~Customer() // D'tor
{
	delete[] username;
	delete[] password;

	// The products pointers themselves already released at each of their seller d'tor
	delete[] cart;
	delete[] orders; 
}

void Customer::setUsername(char* username)
{
	delete[] this->username; // Free the previous username - if exists
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void Customer::setPassword(char* password)
{
	delete[] this->password; // Free the previous password - if exists
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

void Customer::setAddress(Address address)
{
	this->address = address;
}

void Customer::setNumOfPruductsInCart(int numOfProductsInCart)
{
	this->numOfProductsInCart = numOfProductsInCart;
}

void Customer::setNumOfOrders(int numOfOrders)
{
	this->numOfOrders = numOfOrders;
}

char* Customer::getUsername() const
{
	return username;
}

char* Customer::getPassword() const
{
	return password;
}

Address Customer::getAddress() const
{
	return address;
}

Product*** Customer::getCartByPointer()
{
	return &cart;
}

int& Customer::getNumOfProductsInCart()
{
	return numOfProductsInCart;
}

Checkout** Customer::getOrders() const
{
	return orders;
}

int Customer::getNumOfOrders() const
{
	return numOfOrders;
}

void Customer::show() const
{
	cout << "Username: " << username << endl;
	cout << "Address: "; address.show();
}

void Customer::showCart() const
{
	if (numOfProductsInCart == 0)
	{
		cout << "No products in the cart.\n" << endl;
	}
	else
	{
		cout << "Your cart:\n" << endl;
		for (int i = 0; i < numOfProductsInCart; i++)
		{
			cout << i + 1 << "."; cart[i]->show(); cout << endl;
		}
	}
}

void Customer::showOrders() const
{
	if(numOfOrders == 0)
	{
		cout << "No products in the cart.\n" << endl;
	}
	else
	{
	cout << "Your order:\n" << endl;
	for (int i = 0; i < numOfOrders; i++)
	{
		cout << i + 1 << ". \t";
		orders[i]->showProductsNames();
		cout << "\tPrice: " << orders[i]->getTotalPrice() << endl;
		orders[i]->showSellers();
	}
	}
}

Customer* readCustomerData(const ShopSystem& shop)
{
	char username[MAX_CHARACTERS], password[MAX_CHARACTERS];
	char country[MAX_CHARACTERS], city[MAX_CHARACTERS], street[MAX_CHARACTERS];
	int buildingNumber;

	cout << "Thanks for joining in, new customer! Let's get you a good deal!" << endl;
	cout << "We are using an universal and decentralized authentication." << endl;
	cout << "Please fill in the following fields:\n" << endl;

	usernameValidation(username, shop);
	passwordValidation(password);
	countryValidation(country);
	cityValidation(city);
	streetValidation(street);
	buildingNumberValidation(buildingNumber);
	cout << endl;

	Address address(country, city, street, buildingNumber);
	return new Customer(username, password, address);
}