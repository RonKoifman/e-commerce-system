#pragma once

#include "OutResources.h"

class User;

class UserAnalyzer
{
public:
	enum userType {UNKNOWN, SELLER, CUSTOMER, SELLERCUSTOMER};
	static User* loadUser(ifstream& inFile);
	static userType getType(const User* user);
};