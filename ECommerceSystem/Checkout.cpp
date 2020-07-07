#include "User.h"
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

const User& Checkout::getCustomer() const
{
	return customer;
}

void Checkout::updateTotalPrice()
{
	for (Product* product : chosenProducts)
	{
		totalPrice += product->getPrice();
	}
}

bool Checkout::isSellerExists(User& seller) const
{
	for (User* currSeller : sellers)
	{
		if (currSeller->getUsername().compare(seller.getUsername()) == 0)
		{
			return true;
		}
	}

	return false;
}

void Checkout::addProduct(Product& product)
{
	chosenProducts.push_back(&product);
}

void Checkout::addSeller(User& seller)
{
	if (!isSellerExists(seller))
	{
		sellers.push_back(&seller);
	}
}

const string& Checkout::sellersNamesToString() const
{
	unsigned int numOfSellers = sellers.size();
	string& sellersNames = *new string();

	sellersNames.append("\tSellers: ").append(sellers[0]->getUsername());
	for (unsigned int i = 1; i < numOfSellers; i++)
	{
		sellersNames.append(", ").append(sellers[i]->getUsername());
	}

	sellersNames.append("\n");

	return sellersNames;
}

const string& Checkout::productsNamesToString() const
{
	unsigned int numOfChosenProducts = chosenProducts.size();
	string& productsNames = *new string();

	productsNames.append("Products: ").append(chosenProducts[0]->getName());
	for (unsigned int i = 1; i < numOfChosenProducts; i++) 
	{
		productsNames.append(", ").append(chosenProducts[i]->getName());
	}

	productsNames.append("\n");

	return productsNames;
}

const string& Checkout::toString() const
{
	unsigned int numOfChosenProducts = chosenProducts.size();
	string& checkoutStr = *new string();

	checkoutStr.append("Products bought:\n\n");
	for (unsigned int i = 0; i < numOfChosenProducts; i++)
	{
		checkoutStr.append(to_string(i + 1)).append(".").append(chosenProducts[i]->toString()).append("\n\n");
	}

	return checkoutStr;
}