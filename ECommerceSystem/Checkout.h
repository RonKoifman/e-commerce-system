#ifndef __CHECKOUT_H
#define __CHECKOUT_H

#include "Product.h"

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
	const string& toString() const;
	const string& sellersNamesToString() const;
	const string& productsNamesToString() const;
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

#endif // __CHECKOUT_H