#ifndef __USER_ANALYZER_H
#define __USER_ANALYZER_H

class User;

class UserAnalyzer
{
public:
	enum UserType { SELLER, CUSTOMER, SELLER_CUSTOMER, UNKNOWN };
	static User* loadUser(ifstream& inFile);
	static UserType getType(const User& user);
};

#endif // __USER_ANALYZER_H