#include "Feedback.h"

Feedback::Feedback(User& customer, Product& product, const Date& date, const string& text) // C'tor
	: text(text), date(date), customer(customer), product(product)
{
}

void Feedback::setDate(const Date& date)
{
	this->date = date;
}

void Feedback::setText(const string& text)
{
	this->text = text;
}

User& Feedback::getCustomer() const
{
	return customer;
}

Product& Feedback::getProduct() const
{
	return product;
}

const Date& Feedback::getDate() const
{
	return date;
}

const string& Feedback::getText() const
{
	return text;
}

ostream& operator<<(ostream& os, const Feedback& feedback)
{
	os << "\tCustomer: " << feedback.customer.getUsername() << endl;
	os << "\tName of the product: " << feedback.product.getName() << endl;
	os << "\tDate: " << feedback.date << endl;
	os << "\tText: " << feedback.text;
	return os;
}