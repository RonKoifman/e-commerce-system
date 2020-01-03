#include "Seller.h"

Seller::Seller(const char* username, const char* password, const Address& address) // C'tor
	: username(nullptr), password(nullptr), address(address), products(nullptr), feedbacks(nullptr)
{
	setUsername(username);
	setPassword(password);

	// Initialize data members
	numOfProducts = numOfFeedbacks = 0;
}

Seller::~Seller() // D'tor
{
	delete[] username;
	delete[] password;

	for (int i = 0; i < numOfProducts; i++)
	{
		delete products[i];
	}
	for (int i = 0; i < numOfFeedbacks; i++)
	{
		delete feedbacks[i];
	}

	delete[] products;
	delete[] feedbacks;
}

void Seller::setUsername(const char* username)
{
	delete[] this->username; // Free the previous username - if exists
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void Seller::setPassword(const char* password)
{
	delete[] this->password; // Free the previous password - if exists
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

void Seller::setAddress(const Address& address)
{
	this->address = address;
}

char* Seller::getUsername() const
{
	return username;
}

char* Seller::getPassword() const
{
	return password;
}

Address Seller::getAddress() const
{
	return address;
}

Feedback** Seller::getFeedbacks() const
{
	return feedbacks;
}

int Seller::getNumOfFeedbacks() const
{
	return numOfFeedbacks;
}

int Seller::getNumOfProducts() const
{
	return numOfProducts;
}

void Seller::show() const
{
	cout << "Username: " << username << endl;
	cout << "Address: " << address << endl;
	showProducts();
	showFeedbacks();
}

void Seller::showFeedbacks() const
{
	cout << "Feedbacks: ";

	if (numOfFeedbacks == 0)
	{
		cout << "none." << endl;
	}
	else
	{
		cout << endl;
		for (int i = 0; i < numOfFeedbacks; i++)
		{
			cout << i + 1 << ".";
			cout << *feedbacks[i] << endl;
		}
	}
}

void Seller::showProducts() const
{
	cout << "Products: ";

	if (numOfProducts == 0)
	{
		cout << "none." << endl;
	}
	else
	{
		cout << endl;
		for (int i = 0; i < numOfProducts; i++)
		{
			cout << i + 1 << ". ";
			cout << *products[i] << endl;
		}
	}
}

Product** Seller::getProducts() const
{
	return products;
}

Seller* readSellerData(const ShopSystem& shop)
{
	char username[MAX_CHARACTERS], password[MAX_CHARACTERS];
	char country[MAX_CHARACTERS], city[MAX_CHARACTERS], street[MAX_CHARACTERS];
	int buildingNumber;

	cout << "Thanks for joining in, new seller! You are on the way of getting rich!" << endl;
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
	return new Seller(username, password, address);
}

void Seller::addProduct(Product* newProduct)
{
	int i;

	Product** temp = new Product*[numOfProducts + 1]; // Create bigger array to add the new product

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfProducts; i++)
	{
		temp[i] = products[i];
	}
	temp[i] = newProduct; // Add the new product
	numOfProducts++;

	delete[] products; // Free the current array
	products = temp; // Update products array to temp
}

void Seller::addFeedback(Feedback* newFeedback)
{
	int i;

	Feedback** temp = new Feedback*[numOfFeedbacks + 1]; // Create bigger array to add the new feedback

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfFeedbacks; i++)
	{
		temp[i] = feedbacks[i];
	}
	temp[i] = newFeedback; // Add the new feedback
	numOfFeedbacks++;

	delete[] feedbacks; // Free the current array
	feedbacks = temp; // Update feedbacks array to temp
}