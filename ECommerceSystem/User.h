#ifndef __USER_H
#define __USER_H

#include "Address.h"

class User
{
protected:
	char* username;
	char* password;
	Address address;

public:
	User(const char* username, const char* password, const Address& address); // C'tor
	User(const User& other) = delete; // Disable copy c'tor
	const User& operator=(const User& other) = delete; // Disable operator=
	virtual ~User(); // D'tor
	virtual void show(ostream& os) const = 0; // Make user class an abstract class
	// Setters
	void setUsername(const char* username);
	void setPassword(const char* password);
	void setAddress(const Address& address);
	// Getters
	const char* getUsername() const;
	const char* getPassword() const;
	const Address& getAddress() const;
	// Friend functions
	friend ostream& operator<<(ostream& os, const User& user);
};

#endif // __USER_H