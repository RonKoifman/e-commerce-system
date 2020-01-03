#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include "Product.h"
#include "User.h"

class Checkout;

class Customer : virtual public User
{
private:
	/*char* username;
	char* password;
	Address address;*/
	Product** cart;
	int numOfProductsInCart;
	Checkout** orders;
	int numOfOrders;

public:
	Customer(const char* username, const char* password, const Address& address); // C'tor
	Customer(const Customer& other) = delete; // Disable copy c'tor
	~Customer(); // D'tor
	void show() const;
	void showCart() const;
	void showOrders() const;
	void addProductToCart(Product* newProduct);
	void addOrder(Checkout* newOrder);
	void initCart();
	// Setters
	/*void setUsername(const char* username);
	void setPassword(const char* password);
	void setAddress(const Address& address);*/
	void setNumOfPruductsInCart(int numOfProductsInCart);
	void setNumOfOrders(int numOfOrders);
	// Getters
	/*char* getUsername() const;
	char* getPassword() const;
	Address getAddress() const;*/
	Product** getCart() const;
	int getNumOfProductsInCart() const;
	Checkout** getOrders() const;
	int getNumOfOrders() const;
};

#endif // __CUSTOMER_H