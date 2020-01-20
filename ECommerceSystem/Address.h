#ifndef __ADDRESS_H
#define __ADDRESS_H

#include "OutResources.h"

class Address 
{
private:
	string country;
	string city;
	string street;
	int buildingNumber;

public:
	Address(const string& country, const string& city, const string& street, int buildingNumber); // C'tor
	Address(ifstream& inFile);
	void save(ofstream& outFile) const;
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
	// Friend functions
	friend ostream& operator<<(ostream& os, const Address& address);
};

#endif // __ADDRESS_H