#include "User.h"

User::User(const string& username, const string& password, const Address& address)
	: username(username), password(password), address(address)
{
}

User::User(ifstream& inFile)
	: address(Address(inFile))
{
	int len;
	char temp[MAX_CHARACTERS_TO_READ + 1];

	// Read username
	inFile.read((char*)&len, sizeof(len));
	inFile.read((char*)&temp, len);
	temp[len] = '\0';
	username = temp;

	// Read password
	inFile.read((char*)&len, sizeof(len));
	inFile.read((char*)&temp, len);
	temp[len] = '\0';
	password = temp;
}

void User::saveType(ofstream& outFile) const
{
	UserAnalyzer::UserType type = UserAnalyzer::getType(*this);
	outFile.write((const char*)&type, sizeof(UserAnalyzer::UserType));
}

void User::save(ofstream& outFile) const
{
	// Save address
	address.save(outFile);

	// Save username
	int len = username.length();
	outFile.write((const char*)&len, sizeof(len));
	outFile.write((const char*)username.c_str(), len);

	// Save password
	len = password.length();
	outFile.write((const char*)&len, sizeof(len));
	outFile.write((const char*)password.c_str(), len);
}

void User::setUsername(const string& username)
{
	this->username = username;
}

void User::setPassword(const string& password)
{
	this->password = password;
}

void User::setAddress(const Address& address)
{
	this->address = address;
}

const string& User::getUsername() const
{
	return username;
}

const string& User::getPassword() const
{
	return password;
}

const Address& User::getAddress() const
{
	return address;
}

void User::show(ostream& os) const
{
	os << "Username: " << username << endl;
	os << "Address: " << address << endl;
}

ostream& operator<<(ostream& os, const User& user)
{
	user.show(os);
	return os;
}