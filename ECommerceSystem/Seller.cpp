#include "Product.h"
#include "Seller.h"

Seller::Seller(const char* username, const char* password, const Address& address) // C'tor
	: User(username, password, address), products(nullptr), numOfProducts(0)
{
}

Seller::~Seller() // D'tor
{
	for (int i = 0; i < numOfProducts; i++)
	{
		delete products[i];
	}
	for (int i = 0; i < feedbacks.getSize(); i++)
	{
		delete &feedbacks[i];
	}

	delete[] products;
	//delete[] feedbacks;
}

Array<Feedback>& Seller::getFeedbacks()
{
	return feedbacks;
}

const Array<Feedback>& Seller::getFeedbacks() const
{
	return feedbacks;
}

int Seller::getNumOfFeedbacks() const
{
	return feedbacks.getSize();
}

int Seller::getNumOfProducts() const
{
	return numOfProducts;
}

void Seller::show(ostream& os) const
{
	User::show(os);
	showProducts();
	showFeedbacks();
}

void Seller::showFeedbacks() const
{
	cout << feedbacks;
	/*cout << "Feedbacks: ";

	if (numOfFeedbacks == 0)
	{
		cout << "None." << endl;
	}
	else
	{
		cout << endl;
		for (int i = 0; i < numOfFeedbacks; i++)
		{
			cout << i + 1 << ".";
			cout << *feedbacks[i] << endl;
		}
	}*/
}

void Seller::showProducts() const
{
	cout << "Products: ";

	if (numOfProducts == 0)
	{
		cout << "None." << endl;
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

void Seller::addProduct(Product& newProduct)
{
	Product** temp = new Product*[numOfProducts + 1]; // Create bigger array to add the new product

	// Move the pointers from the current array to temp
	for (int i = 0; i < numOfProducts; i++)
	{
		temp[i] = products[i];
	}
	temp[numOfProducts] = &newProduct; // Add the new product
	numOfProducts++;

	delete[] products; // Free the current array
	products = temp; // Update products array to temp
}

//void Seller::addFeedback(Feedback& newFeedback)
//{
//	feedbacks += newFeedback;
//}