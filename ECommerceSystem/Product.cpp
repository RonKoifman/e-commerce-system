#include "Seller.h"
#include "Product.h"

unsigned int Product::uniqueID = 1000; // Generate unique id for each serial number of a product

Product::Product(const string& name, float price, Product::Category category, User& seller)
	: name(name), serialNumber(uniqueID++), seller(seller), price(price), category(category)
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

void Product::setCategory(Product::Category category)
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

Product::Category Product::getCategory() const
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

ostream& operator<<(ostream& os, const Product& product)
{
	os << "\tName: " << product.name << endl;
	os << "\tPrice: $" << product.price << endl;
	os << "\tCategory: "; product.showCategory();
	os << "\tSerial number: " << product.serialNumber << endl;
	os << "\tSeller: " << product.seller.getUsername();

	return os;
}

void Product::showCategory() const
{
	switch (category)
	{
	case Clothing:
		cout << "Clothing" << endl;
		break;

	case Kids:
		cout << "Kids" << endl;
		break;

	case Electricity:
		cout << "Electricity" << endl;
		break;

	case Office:
		cout << "Office" << endl;
		break;
	}
}