#include "Product.h"
#include "Seller.h"

unsigned int Product::uniqueID = 1000; // Generate unique id for each serial number of a product

Product::Product(char* name, float price, char category, Seller* seller) // C'tor
	: name(nullptr), serialNumber(uniqueID++)
{
	setName(name);
	setPrice(price);
	setCategory((Category)category);
	this->seller = seller;
}

Product::Product(const Product& other) // Copy C'tor
	: name(nullptr), serialNumber(other.serialNumber)
{
	setName(other.name);
	setPrice(other.price);
	setCategory(other.category);
	this->seller = other.seller;
}

Product::~Product() // D'tor
{
	delete[] name;
}

void Product::setName(char* name)
{
	delete[] this->name; // Free the previous name - if exists
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Product::setPrice(float price)
{
	this->price = price;
}

void Product::setCategory(Category category)
{
	this->category = category;
}

char* Product::getName() const
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

Seller* Product::getSeller() const
{
	return seller;
}

const unsigned int Product::getSerialNumber() const
{
	return serialNumber;
}

void Product::show() const
{
	cout << "\tName: " << name << endl;
	cout << "\tPrice: $" << price << endl;
	cout << "\tCategory: "; showCategory();
	cout << "\tSerial number: " << serialNumber << endl;
}

void Product::showCategory() const
{
	switch ((Category)category)
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