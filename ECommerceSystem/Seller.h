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
	Array<Feedback*> feedbacks;
	vector<Product*> products;

public:
	Seller(const string& username, const string& password, const Address& address); // C'tor
	Seller(ifstream& inFile); // C'tor for file
	Seller(const Seller& other) = delete; // Disable copy c'tor
	const Seller& operator=(const Seller& other) = delete; // Disable operator=
	virtual ~Seller(); // D'tor
	virtual void show(ostream& os) const override;
	void showFeedbacks() const;
	void showProducts() const;
	void addFeedback(Feedback& newFeedback);
	void addProduct(Product& newProduct);
	// Getters
	const Array<Feedback*>& getFeedbacks() const;
	const vector<Product*>& getProducts() const;
};

#endif // __SELLER_H