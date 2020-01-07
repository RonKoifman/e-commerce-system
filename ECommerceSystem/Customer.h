#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include "Product.h"
#include "User.h"

class Checkout;

class Customer : virtual public User
{
protected:
	Product** cart;
	int numOfProductsInCart;
	Checkout** orders;
	int numOfOrders;

public:
	Customer() = default; // Default C'tor
	Customer(const char* username, const char* password, const Address& address); // C'tor
	Customer(const Customer& other) = delete; // Disable copy c'tor
	const Customer& operator=(const Customer& other) = delete; // Disable operator=
	virtual ~Customer(); // D'tor
	virtual void show() const override;
	void showCart() const;
	void showOrders() const;
	void addProductToCart(Product* newProduct);
	void addOrder(Checkout* newOrder);
	void initCart();
	// Setters
	void setNumOfPruductsInCart(int numOfProductsInCart);
	void setNumOfOrders(int numOfOrders);
	// Getters
	Product** getCart() const;
	int getNumOfProductsInCart() const;
	Checkout** getOrders() const;
	int getNumOfOrders() const;
};

#endif // __CUSTOMER_H