#ifndef __ADDRESS_H
#define __ADDRESS_H

#include "OutResources.h"

class Address 
{
private:
	char* country;
	char* city;
	char* street;
	unsigned int buildingNumber;

public:
	Address(char* country, char* city, char* street, unsigned int buildingNumber); // C'tor
	Address(const Address &other); // Copy C'tor
	~Address(); // D'tor
	void show() const;
	// Setters
	void setCountry(char* country);
	void setCity(char* city);
	void setStreet(char* street);
	void setBuildingNumber(unsigned int buildingNumber);
	// Getters
	char* getCountry() const;
	char* getCity() const;
	char* getStreet() const;
	unsigned int getBuildingNumber() const;
};

#endif // __ADDRESS_H