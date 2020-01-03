#include "Checkout.h"
#include "Customer.h"

Customer::Customer(const char* username, const char* password, const Address& address) // C'tor
	: User(username, password, address), cart(nullptr), orders(nullptr)
{
	/*setUsername(username);
	setPassword(password);*/

	// Initialize data members
	numOfProductsInCart = numOfOrders = 0;
}

Customer::~Customer() // D'tor
{
	/*delete[] username;
	delete[] password;*/

	for (int i = 0; i < numOfOrders; i++)
	{
		delete orders[i];
	}

	delete[] orders; 
	delete[] cart; // The products pointers themselves already released at each of their seller d'tor
}

//void Customer::setUsername(const char* username)
//{
//	delete[] this->username; // Free the previous username - if exists
//	this->username = new char[strlen(username) + 1];
//	strcpy(this->username, username);
//}
//
//void Customer::setPassword(const char* password)
//{
//	delete[] this->password; // Free the previous password - if exists
//	this->password = new char[strlen(password) + 1];
//	strcpy(this->password, password);
//}
//
//void Customer::setAddress(const Address& address)
//{
//	this->address = address;
//}
//
void Customer::setNumOfPruductsInCart(int numOfProductsInCart)
{
	this->numOfProductsInCart = numOfProductsInCart;
}

void Customer::setNumOfOrders(int numOfOrders)
{
	this->numOfOrders = numOfOrders;
}
//
//char* Customer::getUsername() const
//{
//	return username;
//}
//
//char* Customer::getPassword() const
//{
//	return password;
//}
//
//Address Customer::getAddress() const
//{
//	return address;
//}

Product** Customer::getCart() const
{
	return cart;
}

int Customer::getNumOfProductsInCart() const
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
	/*cout << "Username: " << username << endl;
	cout << "Address: " << address << endl;*/
	User::show();
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
			cout << i + 1 << "." << *cart[i] << endl;
			cout << endl;
		}
	}
}

void Customer::showOrders() const
{
	if (numOfOrders == 0)
	{
		cout << "No orders yet.\n" << endl;
	}
	else
	{
		cout << "Your orders:\n" << endl;
		for (int i = 0; i < numOfOrders; i++)
		{
			cout << i + 1 << ". \t";
			orders[i]->showProductsNames();
			cout << "\tPrice: $" << orders[i]->getTotalPrice() << endl;
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

void Customer::addProductToCart(Product* newProduct)
{
	int i;

	Product** temp = new Product*[numOfProductsInCart + 1]; // Create bigger array to add the new product

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfProductsInCart; i++)
	{
		temp[i] = cart[i];
	}
	temp[i] = newProduct; // Add the new product
	numOfProductsInCart++;

	delete[] cart; // Free the current array
	cart = temp; // Update products array to temp
}

void Customer::addOrder(Checkout* newOrder)
{
	int i;

	Checkout** temp = new Checkout*[numOfOrders + 1]; // Create bigger array to add the new order

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfOrders; i++)
	{
		temp[i] = orders[i];
	}
	temp[i] = newOrder; // Add the new order
	numOfOrders++;

	delete[] orders; // Free the current array
	orders = temp; // Update orders array to temp
}

void Customer::initCart()
{
	delete[] cart;
	cart = nullptr;
	numOfProductsInCart = 0;
}