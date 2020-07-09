#include "User.h"
#include "Product.h"

unsigned int Product::uniqueId = 1000; // Generate unique id for each serial number of a product

Product::Product(const string& name, float price, eCategory category, User& seller)
	: name(name), serialNumber(uniqueId++), seller(seller), price(price), category(category)
{
}

void Product::setName(const string& name)
{
	this->name = name;
}

void Product::setPrice(float price)
{
	this->price = price;
}

void Product::setCategory(eCategory category)
{
	this->category = category;
}

const string& Product::getName() const
{
	return name;
}

float Product::getPrice() const
{
	return price;
}

Product::eCategory Product::getCategory() const
{
	return category;
}

User& Product::getSeller() const
{
	return seller;
}

const unsigned int Product::getSerialNumber() const
{
	return serialNumber;
}

const string Product::categoryToString() const
{
	string categoryStr;

	switch (category)
	{
	case Clothing:
		categoryStr.append("Clothing");
		break;

	case Kids:
		categoryStr.append("Kids");
		break;

	case Electricity:
		categoryStr.append("Electricity");
		break;

	case Office:
		categoryStr.append("Office");
		break;
	}

	return categoryStr;
}

const string Product::toString() const
{
	string productStr;

	productStr.append("\tName: ").append(name).append("\n");
	productStr.append("\tPrice: $").append(to_string(price)).append("\n");
	productStr.append("\tCategory: ").append(categoryToString()).append("\n");
	productStr.append("\tSerial number: ").append(to_string(serialNumber)).append("\n");
	productStr.append("\tSeller: ").append(seller.getUsername());

	return productStr;
}