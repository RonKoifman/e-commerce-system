#include "Address.h"

Address::Address(const string& country, const string& city, const string& street, int buildingNumber)
	: country(country), city(city), street(street), buildingNumber(buildingNumber)
{
}

Address::Address(ifstream& inFile)
{
	const int MAX_CHARACTERS_TO_READ = 1000;
	char tempStr[MAX_CHARACTERS_TO_READ + 1];
	int length;

	// Country
	inFile.read((char*)&length, sizeof(length));
	inFile.read((char*)&tempStr, length);
	tempStr[length] = '\0';
	country = tempStr;

	// City
	inFile.read((char*)&length, sizeof(length));
	inFile.read((char*)&tempStr, length);
	tempStr[length] = '\0';
	city = tempStr;
	
	// Street
	inFile.read((char*)&length, sizeof(length));
	inFile.read((char*)&tempStr, length);
	tempStr[length] = '\0';
	street = tempStr;

	// Building number
	inFile.read((char*)&buildingNumber, sizeof(buildingNumber));
}

void Address::save(ofstream& outFile) const
{
	// Country
	int length = country.length();
	outFile.write((const char*)&length, sizeof(length));
	outFile.write((const char*)country.c_str(), length);

	// City
	length = city.length();
	outFile.write((const char*)&length, sizeof(length));
	outFile.write((const char*)city.c_str(), length);

	// Street
	length = street.length();
	outFile.write((const char*)&length, sizeof(length));
	outFile.write((const char*)street.c_str(), length);

	// Building number
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

const string Address::toString() const
{
	string addressStr;

	addressStr.append(street).append(" ").append(to_string(buildingNumber)).append(", ").append(city).append(", ").append(country);

	return addressStr;
}