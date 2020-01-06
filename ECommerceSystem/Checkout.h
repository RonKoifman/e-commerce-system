#ifndef __CHECKOUT_H
#define __CHECKOUT_H

#include "Product.h"
//#include "Seller.h"
#include "SellerCustomer.h"

class Customer;

class Checkout
{
private:
	Product** chosenProducts;
	int numOfChosenProducts;
	float totalPrice; 
	Seller** sellers;
	int numOfSellers;
	Customer* customer;

public:
	Checkout(Customer* customer); // C'tor
	Checkout(const Checkout& other) = delete; // Disable copy c'tor
	const Checkout& operator=(const Checkout& other) = delete; // Disable operator=
	~Checkout(); // D'tor
	void showSellers() const;
	void showProductsNames() const;
	void calculateTotalPrice();
	void addChosenProduct(Product* newProduct);
	void addSeller(Seller* seller);
	void createNewOrder();
	void placeOrder() const;
	// Getters
	Product** getChosenProducts() const;
	int getNumOfChosenProducts() const;
	float getTotalPrice() const;
	int getNumOfSellers() const;
	Customer* getCustomer() const;
	Seller** getSellers() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const Checkout& checkout);
};

#endif // __CHECKOUT_H