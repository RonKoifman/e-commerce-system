#include "Customer.h"
#include "Checkout.h"

Checkout::Checkout(Customer* customer) // C'tor
{
	// Initialize data members
	numOfChosenProducts = 0;
	totalPrice = 0;
	payment = 0;
	numOfSellers = 0;
	sellers = nullptr;
	chosenProducts = nullptr;

	this->customer = customer;
}

Checkout::~Checkout() // D'tor
{
	for (unsigned int i = 0; i < numOfChosenProducts; i++)
	{
		delete chosenProducts[i];
	}
	for (unsigned int i = 0; i < numOfSellers; i++)
	{
		delete sellers[i];
	}

	delete[] chosenProducts;
	delete[] sellers;
}

void Checkout::setNumOfChosenProducts(unsigned int numOfChosenProducts)
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

void Checkout::setNumOfSellers(unsigned int numOfSellers)
{
	this->numOfSellers = numOfSellers;
}

Product** Checkout::getChosenProducts() const
{
	return chosenProducts;
}

unsigned int Checkout::getNumOfChosenProducts() const
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

unsigned int Checkout::getNumOfSellers() const
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
	for (unsigned int i = 0; i < numOfChosenProducts; i++)
	{
		chosenProducts[i]->show(); cout << endl;
	}
	cout << "Total price: " << totalPrice << endl;
}