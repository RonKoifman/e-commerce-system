#ifndef __DATE_H
#define __DATE_H

#include "Utils.h"

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(int day,int month, int year);
	// Setters
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	// Getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	// Friends
	friend ostream& operator<<(ostream& os, const Date& date);
};

#endif // __DATE_H