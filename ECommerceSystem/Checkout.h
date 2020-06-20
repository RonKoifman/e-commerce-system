#ifndef __CHECKOUT_H
#define __CHECKOUT_H

#include "Product.h"
#include "Seller.h"

class User;

class Checkout
{
private:
	vector<Product*> chosenProducts;
	vector<User*> sellers;
	User& customer;
	float totalPrice; 

public:
	Checkout(User& customer);
	Checkout(const Checkout& other) = delete;
	const Checkout& operator=(const Checkout& other) = delete;
	void showSellersNames() const;
	void showProductsNames() const;
	void calculateTotalPrice();
	void createNewOrder();
	// Getters
	const vector<Product*>& getChosenProducts() const;
	const vector<User*>& getSellers() const;
	User& getCustomer() const;
	float getTotalPrice() const;
	// Friends
	friend ostream& operator<<(ostream& os, const Checkout& checkout);
};

#endif // __CHECKOUT_H