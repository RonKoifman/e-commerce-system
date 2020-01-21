#include "Address.h"

Address::Address(const string& country, const string& city, const string& street, int buildingNumber) // C'tor
	: country(country), city(city), street(street), buildingNumber(buildingNumber)
{
}

Address::Address(ifstream& inFile) // C'tor for file
{
	int len;
	char temp[MAX_CHARACTERS_TO_READ + 1];

	// COUNTRY
	inFile.read((char*)&len, sizeof(len));
	inFile.read((char*)&temp, len); temp[len] = '\0';
	country = temp;

	// CITY
	inFile.read((char*)&len, sizeof(len));
	inFile.read((char*)&temp, len); temp[len] = '\0';
	city = temp;

	// STREET
	inFile.read((char*)&len, sizeof(len));
	inFile.read((char*)&temp, len); temp[len] = '\0';
	street = temp;

	// BUILDING NUMBER
	inFile.read((char*)&buildingNumber, sizeof(buildingNumber));
}

void Address::save(ofstream& outFile) const
{
	// COUNTRY
	int len = country.length();
	outFile.write((const char*)&len, sizeof(len));
	outFile.write((const char*)country.c_str(), len);

	// CITY
	len = city.length();
	outFile.write((const char*)&len, sizeof(len));
	outFile.write((const char*)city.c_str(), len);

	// STREET
	len = street.length();
	outFile.write((const char*)&len, sizeof(len));
	outFile.write((const char*)street.c_str(), len);

	// BUILDING NUMBER
	outFile.write((const char*)&buildingNumber, sizeof(buildingNumber));
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
