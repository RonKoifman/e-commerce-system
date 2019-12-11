#ifndef __SELLER_H
#define __SELLER_H

#include "OutResources.h"
#include "Address.h"
#include "Feedback.h"
#include "Product.h"
#include "Validations.h"

class Pruduct;

class Seller
{
private:
	char* username;
	char* password;
	Address address;
	Feedback** feedbacks;
	int numOfFeedbacks;
	Product** products;
	int numOfProducts;

public:
	Seller(char* username, char* password, Address address); // C'tor
	Seller(const Seller& other) = delete; // Disable copy c'tor
	~Seller(); // D'tor
	void show() const;
	void showFeedbacks() const;
	void showProducts() const;
	// Setters
	void setUsername(char* username);
	void setPassword(char* password);
	void setAddress(Address address);
	// Getters
	char* getUsername() const;
	char* getPassword() const;
	Address getAddress() const;
	Feedback** getFeedbacks() const;
	int getNumOfFeedbacks() const;
	Product*** getProductsByPointer();
	int& getNumOfProducts();
	// Friend functions
	friend Product* readProductData(Seller* seller);
};

#endif // __SELLER_H