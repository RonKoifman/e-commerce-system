#ifndef __USER_H
#define __USER_H

#include "Address.h"

class User
{
protected:
	string username;
	string password;
	Address address;

public:
	User(const string& username, const string& password, const Address& address); // C'tor
	virtual ~User() {}; // D'tor
	User(const User& other) = delete; // Disable copy c'tor
	const User& operator=(const User& other) = delete; // Disable operator=
	virtual void show(ostream& os) const = 0; // Make user class an abstract class
	// Setters
	void setUsername(const string& username);
	void setPassword(const string& password);
	void setAddress(const Address& address);
	// Getters
	const string& getUsername() const;
	const string& getPassword() const;
	const Address& getAddress() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const User& user);
};

#endif // __USER_H