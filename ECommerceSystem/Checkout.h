#ifndef __CHECKOUT_H
#define __CHECKOUT_H

#include "OutResources.h"
#include "Product.h"
#include "Seller.h"
#include "Customer.h"

class Customer;

class Checkout
{
private:
	Product** chosenProducts;
	int numOfChosenProducts;
	float totalPrice; 
	float payment;
	Seller** sellers;
	int numOfSellers;
	Customer* customer;

public:
	Checkout(Customer* customer); // C'tor
	Checkout(const Checkout& other) = delete; // Disable copy c'tor
	~Checkout(); // D'tor
	void show() const;
	// Setters
	void setNumOfChosenProducts(int numOfChosenProducts);
	void setTotalPrice(float totalPrice);
	void setPayment(float payment);
	void setNumOfSellers(int numOfSellers);
	// Getters
	Product** getChosenProducts() const;
	int getNumOfChosenProducts() const;
	float getTotalPrice() const;
	float getPayment();
	int getNumOfSellers() const;
	Customer* getCustomer() const;
	Seller** getSellers() const;
};

#endif // __CHECKOUT_H