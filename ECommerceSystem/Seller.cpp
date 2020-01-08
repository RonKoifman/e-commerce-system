#include "Product.h"
#include "Seller.h"

Seller::Seller(const char* username, const char* password, const Address& address) // C'tor
	: User(username, password, address), products(nullptr), feedbacks(nullptr), numOfProducts(0), numOfFeedbacks(0)
{
}

Seller::~Seller() // D'tor
{
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
	User::show();
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