#include "Customer.h"
#include "Checkout.h"

Checkout::Checkout(User& customer) // C'tor
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
	os << "Chosen products:\n" << endl;
	for (unsigned int i = 0; i < checkout.chosenProducts.size(); i++)
	{
		os << i + 1 << "." << *checkout.chosenProducts[i] << endl;
		os << endl;
	}
	return os;
}

void Checkout::calculateTotalPrice()
{
	for (unsigned int i = 0; i < chosenProducts.size(); i++)
	{
		totalPrice += chosenProducts[i]->getPrice();
	}
}

void Checkout::createNewOrder()
{
	Customer* customer = dynamic_cast<Customer*>(&this->customer); if (!customer) return;
	Product* product;
	unsigned int index = 0;
	bool toContinue = true;

	while (toContinue)
	{
		product = Validations::indexOfCheckoutProductValidation(index, customer->getCart(), chosenProducts);
		if (index == -1) // Customer finished to add products to order
		{
			toContinue = false;
		}
		else
		{
			// Add product to the chosen products array
			chosenProducts.push_back(product);
			// Only if seller not exists already - add product's seller to the sellers array
			if (!Validations::isSellerExists(product->getSeller(), sellers))
			{
				sellers.push_back(&product->getSeller());
			}
		}
	}
	calculateTotalPrice();
}

void Checkout::showSellersNames() const
{
	cout << "\tSellers names: " << sellers[0]->getUsername();
	for (unsigned int i = 1; i < sellers.size(); i++)
	{
		cout << ", " << sellers[i]->getUsername();
	}
	cout << endl;
}

void Checkout::showProductsNames() const
{
	cout << "Products names: " << chosenProducts[0]->getName();
	for (unsigned int i = 1; i < chosenProducts.size(); i++) 
	{
		cout << ", " << chosenProducts[i]->getName();
	}
	cout << endl;
}