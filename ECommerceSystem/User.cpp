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
	delete[] this->username; // Free the previous username - if exists
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void User::setPassword(const char* password)
{
	delete[] this->password; // Free the previous password - if exists
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

void User::setAddress(const Address& address)
{
	this->address = address;
}

char* User::getUsername() const
{
	return username;
}

char* User::getPassword() const
{
	return password;
}

Address User::getAddress() const
{
	return address;
}

void User::show() const
{
	cout << "Username: " << username << endl;
	cout << "Address: " << address << endl;
}

//void User::show(ostream & os) const {}

//ostream& operator<<(ostream& os, const User& user)
//{
//	os << "Username: " << user.username << endl;
//	os << "Address: "; user.address.show();
//	user.show(os);
//	return os;
//}