#ifndef __SELLER_H
#define __SELLER_H

#include "Feedback.h"
#include "Product.h"
#include "Validations.h"
#include "User.h"

class Pruduct;

class Seller : virtual public User
{
private:
	/*char* username;
	char* password;
	Address address;*/
	Feedback** feedbacks;
	int numOfFeedbacks;
	Product** products;
	int numOfProducts;

public:
	Seller(const char* username, const char* password, const Address& address); // C'tor
	Seller(const Seller& other) = delete; // Disable copy c'tor
	~Seller(); // D'tor
	//virtual void show(ostream& os) const override;
	virtual void show() const;
	void showFeedbacks() const;
	void showProducts() const;
	void addProduct(Product* newProduct);
	void addFeedback(Feedback* newFeedback);
	// Setters
	/*void setUsername(const char* username);
	void setPassword(const char* password);
	void setAddress(const Address& address);*/
	// Getters
	/*char* getUsername() const;
	char* getPassword() const;
	Address getAddress() const;*/
	Feedback** getFeedbacks() const;
	int getNumOfFeedbacks() const;
	Product** getProducts() const;
	int getNumOfProducts() const;
	// Friend functions
	friend Product* readProductData(Seller* seller);
};

#endif // __SELLER_H