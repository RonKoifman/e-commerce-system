#ifndef __USER_H
#define __USER_H

#include "OutResources.h"
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
	virtual void show() const = 0;
	// Setters
	void setUsername(const char* username);
	void setPassword(const char* password);
	void setAddress(const Address& address);
	// Getters
	char* getUsername() const;
	char* getPassword() const;
	Address getAddress() const;
};

#endif // __USER_H