#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "OutResources.h"

class Seller;

class Product
{
public:
	enum Category { Clothing = '1', Kids = '2', Electricity = '3', Office = '4' };

private:
	static unsigned int uniqueID;
	char* name;
	float price;
	Category category;
	Seller* seller;
	const unsigned int serialNumber;

public:
	Product(char* name, float price, char category, Seller* seller); // C'tor
	Product(const Product& other); // Copy C'tor
	~Product(); // D'tor
	void show() const;
	// Setters
	void setName(char* name);
	void setPrice(float price);
	void setCategory(Category category);
	// Getters
	char* getName() const;
	float getPrice() const;
	Category getCategory() const;
	Seller* getSeller() const;
	const unsigned int getSerialNumber() const;
	void showCategory() const;
};

#endif // __PRODUCT_H