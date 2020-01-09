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
	*this = other;
}

Address::~Address() // D'tor
{
	delete[] country;
	delete[] city;
	delete[] street;
}

const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		setCountry(other.country);
		setCity(other.city);
		setStreet(other.street);
		setBuildingNumber(other.buildingNumber);
	}

	return *this;
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

const char* Address::getCountry() const
{
	return country;
}

const char* Address::getCity() const
{
	return city;
}

const char* Address::getStreet() const
{
	return street;
}

int Address::getBuildingNumber() const
{
	return buildingNumber;
}

ostream& operator<<(ostream& os, const Address& address)
{
	os << address.street << " " << address.buildingNumber << ", " << address.city << ", " << address.country;
	return os;
}