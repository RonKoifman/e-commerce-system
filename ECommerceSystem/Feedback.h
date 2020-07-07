#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "Date.h"
#include "User.h"
#include "Product.h"

class Feedback
{
private:
	User& customer;
	Product& product;
	Date date;
	string text;

public:
	Feedback(User& customer, Product& product, const Date& date, const string& text);
	Feedback(const Feedback& other) = delete;
	const Feedback& operator=(const Feedback& other) = delete;
	const string& toString() const;
	// Setters
	void setDate(const Date& date);
	void setText(const string& text);
	// Getters
	User& getCustomer() const;
	Product& getProduct() const;
	const Date& getDate() const;
	const string& getText() const;
};

#endif // __FEEDBACK_H