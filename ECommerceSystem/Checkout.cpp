#include "Customer.h"
#include "Checkout.h"

Checkout::Checkout(User& customer)
	: customer(customer), totalPrice(0)
{
}

const vector<Product*>& Checkout::getChosenProducts() const
{
	return chosenProducts;
}

const vector<User*>& Checkout::getSellers() const
{
	return sellers;
}

float Checkout::getTotalPrice() const
{
	return totalPrice;
}

User& Checkout::getCustomer() const
{
	return customer;
}

ostream& operator<<(ostream& os, const Checkout& checkout)
{
	unsigned int numOfChosenProducts = checkout.chosenProducts.size();

	os << "Chosen products:\n" << endl;
	for (unsigned int i = 0; i < numOfChosenProducts; i++)
	{
		os << i + 1 << "." << *checkout.chosenProducts[i] << endl;
		os << endl;
	}
	return os;
}

void Checkout::calculateTotalPrice()
{
	unsigned int numOfChosenProducts = chosenProducts.size();

	for (unsigned int i = 0; i < numOfChosenProducts; i++)
	{
		totalPrice += chosenProducts[i]->getPrice();
	}
}

void Checkout::createNewOrder()
{
	Product* product;
	unsigned int index = 0;
	bool toContinue = true;
	Customer* customer = dynamic_cast<Customer*>(&this->customer);
	if (customer == nullptr)
	{
		return;
	}

	while (toContinue)
	{
		product = Validator::indexOfCheckoutProductValidation(index, customer->getCart(), chosenProducts);
		if (index == -1) // Customer finished to add products to order
		{
			toContinue = false;
		}
		else
		{
			// Add product to the chosen products array
			chosenProducts.push_back(product);
			// Only if seller not exists already - add product's seller to the sellers array
			if (!Validator::isSellerExists(product->getSeller(), sellers))
			{
				sellers.push_back(&product->getSeller());
			}
		}
	}
	calculateTotalPrice();
}

void Checkout::showSellersNames() const
{
	unsigned int numOfSellers = sellers.size();

	cout << "\tSellers names: " << sellers[0]->getUsername();
	for (unsigned int i = 1; i < numOfSellers; i++)
	{
		cout << ", " << sellers[i]->getUsername();
	}
	cout << endl;
}

void Checkout::showProductsNames() const
{
	unsigned int numOfChosenProducts = chosenProducts.size();

	cout << "Products names: " << chosenProducts[0]->getName();
	for (unsigned int i = 1; i < numOfChosenProducts; i++) 
	{
		cout << ", " << chosenProducts[i]->getName();
	}
	cout << endl;
}