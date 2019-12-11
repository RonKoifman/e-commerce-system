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
	int numOfChosenProducts;
	float totalPrice; 
	Seller** sellers;
	int numOfSellers;
	Customer* customer;

public:
	Checkout(Customer* customer, Product** chosenProducts, int numOfChosenProducts, Seller** sellers, int numOfSellers); // C'tor
	Checkout(const Checkout& other) = delete; // Disable copy c'tor
	~Checkout(); // D'tor
	void show() const;
	void calculateTotalPrice();
	// Setters
	void setNumOfChosenProducts(int numOfChosenProducts);
	void setTotalPrice(float totalPrice);
	void setNumOfSellers(int numOfSellers);
	void setSellers(Seller** sellers);
	void setChosenProducts(Product** chosenProducts);
	// Getters
	Product** getChosenProducts();
	int getNumOfChosenProducts() const;
	float getTotalPrice() const;
	int getNumOfSellers() const;
	Customer* getCustomer();
	Seller** getSellers();
};

#endif // __CHECKOUT_H