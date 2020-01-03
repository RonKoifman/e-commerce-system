#ifndef __ADDRESS_H
#define __ADDRESS_H

#include "OutResources.h"

class Address 
{
private:
	char* country;
	char* city;
	char* street;
	int buildingNumber;

public:
	Address(const char* country, const char* city, const char* street, int buildingNumber); // C'tor
	Address(const Address& other); // Copy C'tor
	~Address(); // D'tor
	// Setters
	void setCountry(const char* country);
	void setCity(const char* city);
	void setStreet(const char* street);
	void setBuildingNumber(int buildingNumber);
	// Getters
	char* getCountry() const;
	char* getCity() const;
	char* getStreet() const;
	int getBuildingNumber() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const Address& address);
};

#endif // __ADDRESS_H