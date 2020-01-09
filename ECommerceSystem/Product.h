#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "OutResources.h"

class User;

class Product
{
public:
	// Enum declarations
	enum Category { Clothing = 1, Kids = 2, Electricity = 3, Office = 4 };

private:
	static unsigned int uniqueID;
	char* name;
	float price;
	Category category;
	User& seller;
	const unsigned int serialNumber;

public:
	Product(const char* name, float price, int category, User& seller); // C'tor
	Product(const Product& other) = delete; // Disable copy c'tor
	const Product& operator=(const Product& other) = delete; // Disable operator=
	~Product(); // D'tor
	void showCategory() const;
	// Setters
	void setName(const char* name);
	void setPrice(float price);
	void setCategory(Category category);
	// Getters
	const char* getName() const;
	float getPrice() const;
	Category getCategory() const;
	User& getSeller() const;
	const unsigned int getSerialNumber() const;
	// Friend functions and classes
	friend class Validations;
	friend ostream& operator<<(ostream& os, const Product& product);
};

#endif // __PRODUCT_H