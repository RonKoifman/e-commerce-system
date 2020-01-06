#include "Seller.h"
#include "Product.h"

unsigned int Product::uniqueID = 1000; // Generate unique id for each serial number of a product

Product::Product(const char* name, float price, int category, Seller* seller) // C'tor
	: name(nullptr), serialNumber(uniqueID++), seller(seller), price(price)
{
	setName(name);
	setCategory((Category)category);
}

Product::~Product() // D'tor
{
	delete[] name;
}

void Product::setName(const char* name)
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

ostream& operator<<(ostream& os, const Product& product)
{
	os << "\tName: " << product.name << endl;
	os << "\tPrice: $" << product.price << endl;
	os << "\tCategory: "; product.showCategory();
	os << "\tSerial number: " << product.serialNumber << endl;
	os << "\tSeller: " << product.seller->getUsername();
	return os;
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

Product* readProductData(Seller* seller)
{
	char productName[MAX_PRODUCT_NAME_LENGTH];
	float price;
	int category;

	cout << "Please fill in the following fields.\n" << endl;
	productNameValidation(productName, *seller);
	priceValidation(price);
	categoryValidation(category);

	cout << endl << "Product added successfully!\n" << endl;
	return new Product(productName, price, category, seller);
}