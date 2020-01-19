#ifndef __CHECKOUT_H
#define __CHECKOUT_H

#include "Product.h"
#include "Seller.h"

class User;

class Checkout
{
private:
	/*Product** chosenProducts;
	int numOfChosenProducts;*/
	vector<Product*> chosenProducts;
	/*User** sellers;
	int numOfSellers;*/
	vector<User*> sellers;
	User& customer;
	float totalPrice; 

public:
	Checkout(User& customer); // C'tor
	Checkout(const Checkout& other) = delete; // Disable copy c'tor
	const Checkout& operator=(const Checkout& other) = delete; // Disable operator=
	~Checkout(); // D'tor
	void showSellersNames() const;
	void showProductsNames() const;
	void calculateTotalPrice();
	/*void addChosenProduct(Product& newProduct);
	void addSeller(User& seller);*/
	void createNewOrder();
	// Getters
	vector<Product*> getChosenProducts() const;
	int getNumOfChosenProducts() const;
	float getTotalPrice() const;
	int getNumOfSellers() const;
	User& getCustomer() const;
	vector<User*> getSellers() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const Checkout& checkout);
};

#endif // __CHECKOUT_H