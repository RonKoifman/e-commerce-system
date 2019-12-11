#include "Customer.h"
#include "Checkout.h"

Checkout::Checkout(Customer* customer) // C'tor
	: customer(customer), sellers(nullptr), chosenProducts(nullptr)
{
	// Initialize data members
	numOfChosenProducts = numOfSellers = 0;
	totalPrice = payment = 0;
}

Checkout::~Checkout() // D'tor
{
	for (int i = 0; i < numOfChosenProducts; i++)
	{
		delete chosenProducts[i];
	}
	for (int i = 0; i < numOfSellers; i++)
	{
		delete sellers[i];
	}

	delete[] chosenProducts;
	delete[] sellers;
}

void Checkout::setNumOfChosenProducts(int numOfChosenProducts)
{
	this->numOfChosenProducts = numOfChosenProducts;
}

void Checkout::setTotalPrice(float totalPrice)
{
	this->totalPrice = totalPrice;
}

void Checkout::setPayment(float payment)
{
	this->payment = payment;
}

void Checkout::setNumOfSellers(int numOfSellers)
{
	this->numOfSellers = numOfSellers;
}

Product** Checkout::getChosenProducts() const
{
	return chosenProducts;
}

int Checkout::getNumOfChosenProducts() const
{
	return numOfChosenProducts;
}

float Checkout::getTotalPrice() const
{
	return totalPrice;
}

float Checkout::getPayment()
{
	return payment;
}

Seller** Checkout::getSellers() const
{
	return sellers;
}

int Checkout::getNumOfSellers() const
{
	return numOfSellers;
}

Customer* Checkout::getCustomer() const
{
	return customer;
}

void Checkout::show() const
{
	cout << "Chosen products:" << endl;
	for (int i = 0; i < numOfChosenProducts; i++)
	{
		chosenProducts[i]->show(); cout << endl;
	}
	cout << "Total price: " << totalPrice << endl;
}