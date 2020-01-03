#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "OutResources.h"
#include "Date.h"
#include "Customer.h"
#include "Product.h"

class Feedback
{
private:
	Customer* customer;
	Product* product;
	Date date;
	char* text;

public:
	Feedback(Customer* customer, Product* product, const Date& date, const char* text); // C'tor
	Feedback(const Feedback& other); // Copy C'tor
	~Feedback(); // D'tor
	// Setters
	void setDate(const Date& date);
	void setText(const char* text);
	// Getters
	Customer* getCustomer() const;
	Product* getProduct() const;
	Date getDate() const;
	char* getText() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const Feedback& feedback);
};

#endif // __FEEDBACK_H