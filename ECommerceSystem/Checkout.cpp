#include "Customer.h"
#include "Checkout.h"

Checkout::Checkout(Customer* customer, Product** chosenProducts, int numOfChosenProducts, Seller** sellers, int numOfSellers) // C'tor
	: customer(customer), sellers(nullptr), chosenProducts(nullptr), numOfChosenProducts(numOfChosenProducts), numOfSellers(numOfSellers)
{
	setChosenProducts(chosenProducts);
	setSellers(sellers);
	calculateTotalPrice();
}

Checkout::~Checkout() // D'tor
{
	delete[] chosenProducts; // The products pointers themselves will be released at each of their seller d'tor
	delete[] sellers; // The seller pointers themselves will be released at the shop system d'tor
}

void Checkout::setNumOfChosenProducts(int numOfChosenProducts)
{
	this->numOfChosenProducts = numOfChosenProducts;
}

void Checkout::setTotalPrice(float totalPrice)
{
	this->totalPrice = totalPrice;
}

void Checkout::setNumOfSellers(int numOfSellers)
{
	this->numOfSellers = numOfSellers;
}

void Checkout::setSellers(Seller** sellers)
{
	delete[] this->sellers; // Delete previous sellers if existed
	this->sellers = new Seller*[numOfSellers];
	for (int i = 0; i < numOfSellers; i++)
	{
		this->sellers[i] = sellers[i];
	}
}
void Checkout::setChosenProducts(Product** chosenProducts)
{
	delete[] this->chosenProducts; // Delete previous products if existed
	this->chosenProducts = new Product*[numOfChosenProducts];
	for (int i = 0; i < numOfChosenProducts; i++)
	{
		this->chosenProducts[i] = chosenProducts[i];
	}
}

Product** Checkout::getChosenProducts()
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

Seller** Checkout::getSellers()
{
	return sellers;
}

int Checkout::getNumOfSellers() const
{
	return numOfSellers;
}

Customer* Checkout::getCustomer()
{
	return customer;
}

void Checkout::show() const
{
	cout << "Chosen products:\n" << endl;
	for (int i = 0; i < numOfChosenProducts; i++)
	{
		cout << i + 1 << "."; chosenProducts[i]->show(); cout << endl;
	}
}

void Checkout::calculateTotalPrice()
{
	totalPrice = 0;

	for (int i = 0; i < numOfChosenProducts; i++)
	{
		totalPrice += chosenProducts[i]->getPrice();
	}
}