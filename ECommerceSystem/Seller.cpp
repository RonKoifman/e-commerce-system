#include "Product.h"
#include "Seller.h"

Seller::Seller(const string& username, const string& password, const Address& address)
	: User(username, password, address)
{
}

Seller::Seller(ifstream& inFile)
	: User(inFile)
{
}

Seller::~Seller()
{
	unsigned int numOfProducts = products.size();
	unsigned int numOfFeedbacks = feedbacks.getSize();

	for (unsigned int i = 0; i < numOfProducts; i++)
	{
		delete products[i];
	}

	for (unsigned int i = 0; i < numOfFeedbacks; i++)
	{
		delete feedbacks[i];
	}
}

const Array<Feedback*>& Seller::getFeedbacks() const
{
	return feedbacks;
}

const vector<Product*>& Seller::getProducts() const
{
	return products;
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
}

void Seller::showProducts() const
{
	unsigned int numOfProducts = products.size();

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
			cout << *products[i] << endl;
		}
	}
}

void Seller::addFeedback(Feedback& newFeedback)
{
	feedbacks.push_back(&newFeedback);
}

void Seller::addProduct(Product& newProduct)
{
	products.push_back(&newProduct);
}