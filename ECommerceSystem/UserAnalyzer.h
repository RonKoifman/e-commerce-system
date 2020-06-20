#ifndef __USER_ANALYZER_H
#define __USER_ANALYZER_H

class User;

class UserAnalyzer
{
public:
	enum UserType
	{ 
		TypeSeller = 1,
		TypeCustomer = 2,
		TypeSellerCustomer = 3
	};
	static User& loadUser(ifstream& inFile);
	static UserAnalyzer::UserType getType(const User& user);
};

#endif // __USER_ANALYZER_H