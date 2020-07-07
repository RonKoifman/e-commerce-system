#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "Utils.h"

class User;

class Product
{
public:
	enum Category 
	{ 
		Clothing = 1,
		Kids,
		Electricity,
		Office 
	};
	static const int NUM_OF_CATEGORIES = 4;

private:
	static unsigned int uniqueId;
	string name;
	float price;
	Category category;
	User& seller;
	const unsigned int serialNumber;

public:
	Product(const string& name, float price, Product::Category category, User& seller);
	Product(const Product& other) = delete;
	const Product& operator=(const Product& other) = delete;
	const string& categoryToString() const;
	const string& toString() const;
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
	friend class ShopSystem;
};

#endif // __PRODUCT_H