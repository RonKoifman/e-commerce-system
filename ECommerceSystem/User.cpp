#include "User.h"

User::User(const string& username, const string& password, const Address& address)
	: username(username), password(password), address(address)
{
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