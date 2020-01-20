#ifndef __USER_H
#define __USER_H

#include "Address.h"
#include "UserAnalyzer.h"

class User
{
protected:
	Address address;
	string username;
	string password;

public:
	User(const string& username, const string& password, const Address& address); // C'tor
	User(const User& other) = delete; // Disable copy c'tor
	User(ifstream& inFile);
	virtual ~User() {}; // D'tor
	const User& operator=(const User& other) = delete; // Disable operator=
	virtual void show(ostream& os) const = 0; // Make user class an abstract class
	void saveType(ofstream& outFile) const;
	virtual void save(ofstream& outFile) const;
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