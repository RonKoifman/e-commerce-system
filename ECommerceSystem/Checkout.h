#ifndef __CHECKOUT_H
#define __CHECKOUT_H

#include "OutResources.h"
#include "Product.h"
#include "Seller.h"

class Customer;

class Checkout
{
private:
	Product** chosenProducts;
	unsigned int numOfChosenProducts;
	float totalPrice; 
	float payment;
	Seller** sellers;
	unsigned int numOfSellers;
	Customer* customer;

public:
	Checkout(Customer* customer); // C'tor
	Checkout(const Checkout& other) = delete; // Disable copy c'tor
	~Checkout(); // D'tor
	void show() const;
	// Setters
	void setNumOfChosenProducts(unsigned int numOfChosenProducts);
	void setTotalPrice(float totalPrice);
	void setPayment(float payment);
	void setNumOfSellers(unsigned int numOfSellers);
	// Getters
	Product** getChosenProducts() const;
	unsigned int getNumOfChosenProducts() const;
	float getTotalPrice() const;
	float getPayment();
	unsigned int getNumOfSellers() const;
	Customer* getCustomer() const;
	Seller** getSellers() const;
};

#endif // __CHECKOUT_H