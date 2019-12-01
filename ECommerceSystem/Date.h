#ifndef __DATE_H
#define __DATE_H

#include "OutResources.h"

class Date
{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

public:
	Date(unsigned int day, unsigned int month, unsigned int year); // C'tor
	void show() const;
	// Setters
	void setDay(unsigned int day);
	void setMonth(unsigned int month);
	void setYear(unsigned int year);
	// Getters
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
};

#endif // __DATE_H