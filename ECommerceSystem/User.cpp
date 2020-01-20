#include "User.h"

User::User(const string& username, const string& password, const Address& address)
	: username(username), password(password), address(address)
{
}

User::User(ifstream& inFile)
	: address(Address(inFile))
{
	int len;
	//USERNAME
	inFile.read((char*)&len, sizeof(len));
	inFile.read((char*)&username, len); 
	//username[len] = '\0';

	//PASSWORD
	inFile.read((char*)&len, sizeof(len));
	inFile.read((char*)&password, len);
	//password[len] = '\0';

	//ADDRESS
	//address = Address(inFile);
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

void User::saveType(ofstream& outFile) const
{
	UserAnalyzer::userType type = UserAnalyzer::getType(this);
	outFile.write((const char*)&type, sizeof(UserAnalyzer::userType));
}

void User::save(ofstream& outFile) const
{
	address.save(outFile);

	//USERNAME
	int len = username.length();
	outFile.write((const char*)&len, sizeof(len));
	outFile.write((const char*)username.c_str(), len);

	//PASSWORD
	len = password.length();
	outFile.write((const char*)&len, sizeof(len));
	outFile.write((const char*)password.c_str(), len);

}

ostream& operator<<(ostream& os, const User& user)
{
	user.show(os);
	return os;
}