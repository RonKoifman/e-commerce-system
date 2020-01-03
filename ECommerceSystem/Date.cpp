#include "Date.h"

Date::Date(int day, int month, int year) // C'tor
	: day(day), month(month), year(year)
{
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}