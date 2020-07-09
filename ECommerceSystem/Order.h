#ifndef __ORDER_H
#define __ORDER_H

#include "Product.h"

class Order
{
private:
	vector<Product*> chosenProducts;
	vector<User*> sellers;
	User& customer;
	float totalPrice; 

public:
	Order(User& customer);
	Order(const Order& other) = delete;
	const Order& operator=(const Order& other) = delete;
	const string toString() const;
	const string sellersNamesToString() const;
	const string productsNamesToString() const;
	bool isSellerExists(User& seller) const;
	void updateTotalPrice();
	void addProduct(Product& product);
	void addSeller(User& seller);
	// Getters
	const vector<Product*>& getChosenProducts() const;
	const vector<User*>& getSellers() const;
	const User& getCustomer() const;
	float getTotalPrice() const;
};

#endif // __ORDER_H