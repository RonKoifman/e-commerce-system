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
	Checkout(User& customer); // C'tor
	Checkout(const Checkout& other) = delete; // Disable copy c'tor
	const Checkout& operator=(const Checkout& other) = delete; // Disable operator=
	void showSellersNames() const;
	void showProductsNames() const;
	void calculateTotalPrice();
	void createNewOrder();
	// Getters
	const vector<Product*>& getChosenProducts() const;
	vector<Product*>& getChosenProducts();
	const vector<User*>& getSellers() const;
	vector<User*>& getSellers();
	User& getCustomer() const;
	float getTotalPrice() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const Checkout& checkout);
};

#endif // __CHECKOUT_H