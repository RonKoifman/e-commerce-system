#include "Address.h"

Address::Address(const char* country, const char* city, const char* street, int buildingNumber) // C'tor
	: country(nullptr), city(nullptr), street(nullptr)
{
	setCountry(country);
	setCity(city);
	setStreet(street);
	setBuildingNumber(buildingNumber);
}

Address::Address(const Address& other) // Copy C'tor
	: country(nullptr), city(nullptr), street(nullptr)
{
	setCountry(other.country);
	setCity(other.city);
	setStreet(other.street);
	setBuildingNumber(other.buildingNumber);
}

Address::~Address() // D'tor
{
	delete[] country;
	delete[] city;
	delete[] street;
}

void Address::setCountry(const char* country)
{
	delete[] this->country; // Free the previous country - if exists
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);
}

void Address::setCity(const char* city)
{
	delete[] this->city; // Free the previous city - if exists
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);
}

void Address::setStreet(const char* street)
{
	delete[] this->street; // Free the previous street - if exists
	this->street = new char[strlen(street) + 1];
	strcpy(this->street, street);
}

void Address::setBuildingNumber(int buildingNumber)
{
	this->buildingNumber = buildingNumber;
}

char* Address::getCountry() const
{
	return country;
}

char* Address::getCity() const
{
	return city;
}

char* Address::getStreet() const
{
	return street;
}

int Address::getBuildingNumber() const
{
	return buildingNumber;
}

void Address::show() const
{
	cout << street << " " << buildingNumber << ", " << city << ", " << country << endl;
}