#include "User.h"

User::User(const char* username, const char* password, const Address& address)
	: username(nullptr), password(nullptr), address(address)
{
	setUsername(username);
	setPassword(password);
}

User::~User()
{
	delete[] username;
	delete[] password;
}

void User::setUsername(const char* username)
{
	delete[] this->username;
	this->username = strdup(username);
}

void User::setPassword(const char* password)
{
	delete[] this->password;
	this->password = strdup(password);
}

void User::setAddress(const Address& address)
{
	this->address = address;
}

const char* User::getUsername() const
{
	return username;
}

const char* User::getPassword() const
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