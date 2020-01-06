#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "Date.h"
#include "Customer.h"
#include "Product.h"

class Feedback
{
private:
	User* customer;
	Product* product;
	Date date;
	char* text;

public:
	Feedback(User* customer, Product* product, const Date& date, const char* text); // C'tor
	Feedback(const Feedback& other) = delete; // Disable copy c'tor
	const Feedback& operator=(const Feedback& other) = delete; // Disable operator=
	~Feedback(); // D'tor
	// Setters
	void setDate(const Date& date);
	void setText(const char* text);
	// Getters
	User* getCustomer() const;
	Product* getProduct() const;
	Date getDate() const;
	char* getText() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const Feedback& feedback);
};

#endif // __FEEDBACK_H