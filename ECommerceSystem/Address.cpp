#include "Address.h"

Address::Address(const string& country, const string& city, const string& street, int buildingNumber) // C'tor
	: country(country), city(city), street(street), buildingNumber(buildingNumber)
{
}

void Address::setCountry(const string& country)
{
	this->country = country;
}

void Address::setCity(const string& city)
{
	this->city = city;
}

void Address::setStreet(const string& street)
{
	this->street = street;
}

void Address::setBuildingNumber(int buildingNumber)
{
	this->buildingNumber = buildingNumber;
}

const string& Address::getCountry() const
{
	return country;
}

const string& Address::getCity() const
{
	return city;
}

const string& Address::getStreet() const
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