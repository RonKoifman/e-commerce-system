#include "Feedback.h"

Feedback::Feedback(User& customer, Product& product, const Date& date, const string& text)
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

const string& Feedback:: toString() const
{
	string& feedbackStr = *new string();

	feedbackStr.append("\tCustomer: ").append(customer.getUsername()).append("\n");
	feedbackStr.append("\tName of the product: ").append(product.getName()).append("\n");
	feedbackStr.append("\tDate: ").append(getDate().toString()).append("\n");
	feedbackStr.append("\tText: ").append(text);

	return feedbackStr;
}