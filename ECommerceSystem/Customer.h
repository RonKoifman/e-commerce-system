#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include "Product.h"
#include "User.h"

class Checkout;

class Customer : virtual public User
{
protected:
	vector<Product*> cart;
	vector<Checkout*> orders;

public:
	Customer(const string& username, const string& password, const Address& address); // C'tor
	Customer(ifstream& inFile); // C'tor for file
	Customer(const Customer& other) = delete; // Disable copy c'tor
	const Customer& operator=(const Customer& other) = delete; // Disable operator=
	virtual ~Customer(); // D'tor
	bool operator>(const Customer& other) const;
	float calculateCartTotalAmount() const;
	virtual void show(ostream& os) const override;
	void showCart() const;
	void showOrders() const;
	void initCart();
	void addProductToCart(Product& chosenProduct);
	void addOrder(Checkout& newOrder);
	// Getters
	const vector<Product*>& getCart() const;
	const vector<Checkout*>& getOrders() const;
};

#endif // __CUSTOMER_H