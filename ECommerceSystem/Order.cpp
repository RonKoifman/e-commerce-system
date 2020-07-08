#include "User.h"
#include "Order.h"

Order::Order(User& customer)
	: customer(customer), totalPrice(0)
{
}

const vector<Product*>& Order::getChosenProducts() const
{
	return chosenProducts;
}

const vector<User*>& Order::getSellers() const
{
	return sellers;
}

float Order::getTotalPrice() const
{
	return totalPrice;
}

const User& Order::getCustomer() const
{
	return customer;
}

void Order::updateTotalPrice()
{
	for (Product* product : chosenProducts)
	{
		totalPrice += product->getPrice();
	}
}

bool Order::isSellerExists(User& seller) const
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

void Order::addProduct(Product& product)
{
	chosenProducts.push_back(&product);
}

void Order::addSeller(User& seller)
{
	if (!isSellerExists(seller))
	{
		sellers.push_back(&seller);
	}
}

const string& Order::sellersNamesToString() const
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

const string& Order::productsNamesToString() const
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

const string& Order::toString() const
{
	unsigned int numOfChosenProducts = chosenProducts.size();
	string& orderStr = *new string();

	orderStr.append("Products bought:\n\n");
	for (unsigned int i = 0; i < numOfChosenProducts; i++)
	{
		orderStr.append(to_string(i + 1)).append(".").append(chosenProducts[i]->toString()).append("\n\n");
	}

	return orderStr;
}