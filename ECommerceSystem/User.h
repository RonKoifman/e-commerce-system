#ifndef __USER_H
#define __USER_H

#include "Address.h"
#include "Checkout.h"
#include "Product.h"

class Feedback;

class User
{
protected:
	string username;
	string password;
	Address address;
	vector<Product*> productsForSale;
	vector<Feedback*> feedbacks;
	vector<Product*> cart;
	vector<Checkout*> orders;

public:
	User(const string& username, const string& password, const Address& address);
	User(ifstream& inFile);
	~User();
	User(const User& other) = delete;
	const User& operator=(const User& other) = delete;
	void save(ofstream& outFile) const;
	void addFeedback(Feedback& newFeedback);
	void addProductForSale(Product& newProduct);
	void addProductToCart(Product& chosenProduct);
	void addOrder(Checkout& newOrder);
	void initCart();
	const string& ordersToString() const;
	const string& productsForSaleToString() const;
	const string& feedbacksToString() const;
	const string& cartToString() const;
	const string& toString() const;
	// Setters
	void setUsername(const string& username);
	void setPassword(const string& password);
	void setAddress(const Address& address);
	// Getters
	const string& getUsername() const;
	const string& getPassword() const;
	const Address& getAddress() const;
	const vector<Feedback*>& getFeedbacks() const;
	const vector<Product*>& getProductsForSale() const;
	const vector<Product*>& getCart() const;
	const vector<Checkout*>& getOrders() const;
};

#endif // __USER_H