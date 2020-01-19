#include "Product.h"
#include "Seller.h"

Seller::Seller(const string& username, const string& password, const Address& address) // C'tor
	: User(username, password, address)
{
}

Seller::~Seller() // D'tor
{
	for (unsigned int i = 0; i < products.size(); i++)
	{
		delete products[i];
	}

	for (unsigned int i = 0; i < feedbacks.getSize(); i++)
	{
		delete feedbacks[i];
	}
}

const Array<Feedback*>& Seller::getFeedbacks() const
{
	return feedbacks;
}

Array<Feedback*>& Seller::getFeedbacks()
{
	return feedbacks;
}

const vector<Product*>& Seller::getProducts() const
{
	return products;
}

vector<Product*>& Seller::getProducts()
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
	cout << "Products: ";

	if (products.size() == 0)
	{
		cout << "none." << endl;
	}
	else
	{
		cout << endl;
		for (unsigned int i = 0; i < products.size(); i++)
		{
			cout << i + 1 << ". ";
			cout << *products[i] << endl;
		}
	}
}