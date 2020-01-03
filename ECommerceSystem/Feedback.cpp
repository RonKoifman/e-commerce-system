#include "Feedback.h"

Feedback::Feedback(Customer* customer, Product* product, const Date& date, const char* text) // C'tor
	: text(nullptr), date(date), customer(customer), product(product)
{
	setText(text);
}

Feedback::Feedback(const Feedback& other) // Copy C'tor
	: text(nullptr), date(other.date), customer(other.customer), product(other.product)
{
	setText(other.text);
}

Feedback::~Feedback() // D'tor
{
	delete[] text;
}

void Feedback::setDate(const Date& date)
{
	this->date = date;
}

void Feedback::setText(const char* text)
{
	delete[] this->text; // Free the previous text - if exists
	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);
}

Customer* Feedback::getCustomer() const
{
	return customer;
}

Product* Feedback::getProduct() const
{
	return product;
}

Date Feedback::getDate() const
{
	return date;
}

char* Feedback::getText() const
{
	return text;
}

ostream& operator<<(ostream& os, const Feedback& feedback)
{
	os << "\tCustomer: " << feedback.customer->getUsername() << endl;
	os << "\tName of the product: " << feedback.product->getName() << endl;
	os << "\tDate: " << feedback.date << endl;
	os << "\tText: " << feedback.text;
	return os;
}