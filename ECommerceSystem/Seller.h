#ifndef __SELLER_H
#define __SELLER_H

#include "Feedback.h"
#include "Validations.h"
#include "User.h"
#include "Array.h"

class Product;



class Seller : virtual public User
{
protected:
	Array<Feedback> feedbacks;
	//int numOfFeedbacks;
	Product** products;
	int numOfProducts;

public:
	Seller(const char* username, const char* password, const Address& address); // C'tor
	Seller(const Seller& other) = delete; // Disable copy c'tor
	const Seller& operator=(const Seller& other) = delete; // Disable operator=
	virtual ~Seller(); // D'tor
	virtual void show(ostream& os) const override;
	void showFeedbacks() const;
	void showProducts() const;
	void addProduct(Product& newProduct);
	//void addFeedback(Feedback& newFeedback);

	// Getters
	Array<Feedback>& getFeedbacks();
	const Array<Feedback>& getFeedbacks() const;
	int getNumOfFeedbacks() const;
	Product** getProducts() const;
	int getNumOfProducts() const;
};

#endif // __SELLER_H