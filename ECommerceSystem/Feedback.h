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
	Feedback(Customer* customer, Product* product, Date date, char* text); // C'tor
	Feedback(const Feedback& other); // Copy C'tor
	~Feedback(); // D'tor
	void show() const;
	// Setters
	void setDate(Date date);
	void setText(char* text);
	// Getters
	Customer* getCustomer() const;
	Product* getProduct() const;
	Date getDate() const;
	char* getText() const;
};

#endif // __FEEDBACK_H