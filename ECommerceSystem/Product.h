#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "Utils.h"

class User;

class Product
{
public:
	// Enum declarations
	enum Category 
	{ 
		Clothing = 1,
		Kids = 2,
		Electricity = 3,
		Office = 4 
	};

private:
	static unsigned int uniqueID;
	string name;
	float price;
	Category category;
	User& seller;
	const unsigned int serialNumber;

public:
	Product(const string& name, float price, Product::Category category, User& seller);
	Product(const Product& other) = delete;
	const Product& operator=(const Product& other) = delete;
	void showCategory() const;
	// Setters
	void setName(const string& name);
	void setPrice(float price);
	void setCategory(Product::Category category);
	// Getters
	const string& getName() const;
	float getPrice() const;
	Product::Category getCategory() const;
	User& getSeller() const;
	const unsigned int getSerialNumber() const;
	// Friends
	friend class Validator;
	friend ostream& operator<<(ostream& os, const Product& product);
};

#endif // __PRODUCT_H