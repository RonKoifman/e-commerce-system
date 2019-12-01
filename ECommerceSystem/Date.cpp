#include "Date.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year) // C'tor
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Date::setDay(unsigned int day)
{
	this->day = day;
}

void Date::setMonth(unsigned int month)
{
	this->month = month;
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

unsigned int Date::getDay() const
{
	return day;
}

unsigned int Date::getMonth() const
{
	return month;
}

unsigned int Date::getYear() const
{
	return year;
}

void Date::show() const
{
	cout << day << "/" <<  month << "/" << year << endl;
}