#ifndef __SELLER_H
#define __SELLER_H

#include "User.h"
#include "Feedback.h"
#include "Product.h"
#include "Validations.h"

class Product;

class Seller : virtual public User
{
protected:
	Feedback** feedbacks;
	int numOfFeedbacks;
	Product** products;
	int numOfProducts;

public:
	Seller(const char* username, const char* password, const Address& address); // C'tor
	Seller(const Seller& other) = delete; // Disable copy c'tor
	virtual ~Seller(); // D'tor
	virtual void show() const override;
	void showFeedbacks() const;
	void showProducts() const;
	void addProduct(Product* newProduct);
	void addFeedback(Feedback* newFeedback);
	// Getters
	Feedback** getFeedbacks() const;
	int getNumOfFeedbacks() const;
	Product** getProducts() const;
	int getNumOfProducts() const;
	// Friend functions
	friend Product* readProductData(Seller* seller);
};

#endif // __SELLER_H