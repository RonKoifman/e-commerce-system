#ifndef __ADDRESS_H
#define __ADDRESS_H

#include "Utils.h"

class Address 
{
private:
	string country;
	string city;
	string street;
	int buildingNumber;

public:
	Address(const string& country, const string& city, const string& street, int buildingNumber);
	Address(ifstream& inFile);
	void save(ofstream& outFile) const;
	const string& toString() const;
	// Setters
	void setCountry(const string& country);
	void setCity(const string& city);
	void setStreet(const string& street);
	void setBuildingNumber(int buildingNumber);
	// Getters
	const string& getCountry() const;
	const string& getCity() const;
	const string& getStreet() const;
	int getBuildingNumber() const;
};

#endif // __ADDRESS_H