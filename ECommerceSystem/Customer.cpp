#include "Checkout.h"
#include "Customer.h"

Customer::Customer(const string& username, const string& password, const Address& address) // C'tor
	: User(username, password, address)
{
}

Customer::Customer(ifstream& inFile) // C'tor for file
	: User(inFile)
{
}

Customer::~Customer() // D'tor
{
	unsigned int numOfOrders = orders.size();

	for (unsigned int i = 0; i < numOfOrders; i++)
	{
		delete orders[i];
	}
}

bool Customer::operator>(const Customer& other) const
{
	return (this->calculateCartTotalAmount() > other.calculateCartTotalAmount());
}

float Customer::calculateCartTotalAmount() const
{
	float res = 0;
	unsigned int numOfProductsInCart = cart.size();

	for (unsigned int i = 0; i < numOfProductsInCart; i++)
	{
		res += cart[i]->getPrice();
	}

	return res;
}

const vector<Product*>& Customer::getCart() const
{
	return cart;
}

const vector<Checkout*>& Customer::getOrders() const
{
	return orders;
}

void Customer::show(ostream& os) const
{
	User::show(os);
}

void Customer::showCart() const
{
	unsigned int numOfProductsInCart = cart.size();

	if (numOfProductsInCart == 0)
	{
		cout << "No products in the cart.\n" << endl;
	}
	else
	{
		cout << "Your cart:\n" << endl;
		for (unsigned int i = 0; i < numOfProductsInCart; i++)
		{
			cout << i + 1 << "." << *cart[i] << endl;
			cout << endl;
		}
	}
}

void Customer::showOrders() const
{
	unsigned int numOfOrders = orders.size();

	if (numOfOrders == 0)
	{
		cout << "No orders yet.\n" << endl;
	}
	else
	{
		cout << "Your orders:\n" << endl;
		for (unsigned int i = 0; i < numOfOrders; i++)
		{
			cout << i + 1 << ". \t";
			orders[i]->showProductsNames();
			cout << "\tPrice: $" << orders[i]->getTotalPrice() << endl;
			orders[i]->showSellersNames();
		}
	}
}

void Customer::initCart()
{
	cart.clear();
}

void Customer::addProductToCart(Product& chosenProduct)
{
	cart.push_back(&chosenProduct);
}

void Customer::addOrder(Checkout& newOrder)
{
	orders.push_back(&newOrder);
}