#ifndef __SELLER_H
#define __SELLER_H

#include "Feedback.h"
#include "Validator.h"
#include "User.h"
#include "Array.h"

class Product;

class Seller : virtual public User
{
protected:
	Array<Feedback*> feedbacks;
	vector<Product*> products;

public:
	Seller(const string& username, const string& password, const Address& address);
	Seller(ifstream& inFile);
	Seller(const Seller& other) = delete;
	const Seller& operator=(const Seller& other) = delete;
	virtual ~Seller();
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