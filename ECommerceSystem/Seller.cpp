#include "Product.h"
#include "Seller.h"

Seller::Seller(char* username, char* password, Address address) // C'tor
	: username(nullptr), password(nullptr), address(address)
{
	setUsername(username);
	setPassword(password);

	// Initialize data members
	numOfProducts = 0;
	numOfFeedbacks = 0;
	products = nullptr; 
	feedbacks = nullptr;
}

Seller::~Seller() // D'tor
{
	delete[] username;
	delete[] password;

	for (unsigned int i = 0; i < numOfProducts; i++)
	{
		delete products[i];
	}
	for (unsigned int i = 0; i < numOfFeedbacks; i++)
	{
		delete feedbacks[i];
	}

	delete[] products;
	delete[] feedbacks;
}

void Seller::setUsername(char * username)
{
	delete[] this->username; // Free the previous username - if exists
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void Seller::setPassword(char* password)
{
	delete[] this->password; // Free the previous password - if exists
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

void Seller::setAddress(Address address)
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

unsigned int Seller::getNumOfFeedbacks() const
{
	return numOfFeedbacks;
}

Product** Seller::getProducts() const
{
	return products;
}

unsigned int Seller::getNumOfProducts() const
{
	return numOfProducts;
}

void Seller::show() const
{
	cout << "Username: " << username << endl;
	cout << "Address: "; address.show();
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
		for (unsigned int i = 0; i < numOfFeedbacks; i++)
		{
			cout << i + 1 << ". ";
			feedbacks[i]->show(); cout << endl;
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
		for (unsigned int i = 0; i < numOfProducts; i++)
		{
			cout << i + 1 << ". ";
			products[i]->show();
		}
	}
}

void Seller::addProduct(Product* product)
{
	unsigned int i;

	Product** temp = new Product*[numOfProducts + 1]; // Create bigger array to add the new product

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfProducts; i++)
	{
		temp[i] = products[i];
	}
	temp[i] = product; // Add the new product
	numOfProducts++;

	delete[] products; // Free the current array
	products = temp; // Update products array to temp
}