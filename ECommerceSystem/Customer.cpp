#include "Checkout.h"
#include "Customer.h"

Customer::Customer(const char* username, const char* password, const Address& address) // C'tor
	: User(username, password, address), cart(nullptr), orders(nullptr), numOfProductsInCart(0), numOfOrders(0)
{
}

Customer::~Customer() // D'tor
{
	for (int i = 0; i < numOfOrders; i++)
	{
		delete orders[i];
	}

	delete[] orders; 
	delete[] cart; // The pointers already released at each of their seller d'tor
}

bool Customer::operator>(const Customer& other) const
{
	return (this->calculateCartTotalAmount() > other.calculateCartTotalAmount());
}

float Customer::calculateCartTotalAmount() const
{
	float res = 0;

	for (int i = 0; i < numOfProductsInCart; i++)
	{
		res += cart[i]->getPrice();
	}

	return res;
}

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

void Customer::show(ostream& os) const
{
	User::show(os);
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
			orders[i]->showSellersNames();
		}
	}
}

void Customer::addProductToCart(Product* newProduct)
{
	Product** temp = new Product*[numOfProductsInCart + 1]; // Create bigger array to add the new product

	// Move the pointers from the current array to temp
	for (int i = 0; i < numOfProductsInCart; i++)
	{
		temp[i] = cart[i];
	}
	temp[numOfProductsInCart] = newProduct; // Add the new product
	numOfProductsInCart++;

	delete[] cart; // Free the current array
	cart = temp; // Update products array to temp
}

void Customer::addOrder(Checkout* newOrder)
{
	Checkout** temp = new Checkout*[numOfOrders + 1]; // Create bigger array to add the new order

	// Move the pointers from the current array to temp
	for (int i = 0; i < numOfOrders; i++)
	{
		temp[i] = orders[i];
	}
	temp[numOfOrders] = newOrder; // Add the new order
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