#include "Date.h"

Date::Date(int day, int month, int year)
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

const string& Date::toString() const
{
	string& dateStr = *new string();

	dateStr.append(to_string(day)).append("/").append(to_string(month)).append("/").append(to_string(year));

	return dateStr;
}