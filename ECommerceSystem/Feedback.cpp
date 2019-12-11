#include "Feedback.h"

Feedback::Feedback(Customer* customer, Product* product, Date date, char* text) // C'tor
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

void Feedback::setDate(Date date)
{
	this->date = date;
}

void Feedback::setText(char* text)
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

void Feedback::show() const
{
	cout << "Customer: " << customer->getUsername() << endl;
	cout << "Name of the product: " << product->getName() << endl;
	cout << "Date: "; date.show();
	cout << "Text: " << text << endl;
}