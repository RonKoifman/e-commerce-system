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
	for (unsigned int i = 0; i < orders.size(); i++)
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

	for (unsigned int i = 0; i < cart.size(); i++)
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
	if (cart.size() == 0)
	{
		cout << "No products in the cart.\n" << endl;
	}
	else
	{
		cout << "Your cart:\n" << endl;
		for (unsigned int i = 0; i < cart.size(); i++)
		{
			cout << i + 1 << "." << *cart[i] << endl;
			cout << endl;
		}
	}
}

void Customer::showOrders() const
{
	if (orders.size() == 0)
	{
		cout << "No orders yet.\n" << endl;
	}
	else
	{
		cout << "Your orders:\n" << endl;
		for (unsigned int i = 0; i < orders.size(); i++)
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