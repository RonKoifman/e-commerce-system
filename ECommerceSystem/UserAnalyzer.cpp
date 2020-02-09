#include "SellerCustomer.h"
#include "UserAnalyzer.h"

User& UserAnalyzer::loadUser(ifstream& inFile)
{
	UserAnalyzer::UserType type;

	inFile.read((char*)&type, sizeof(UserAnalyzer::UserType));

	switch (type)
	{
	case TypeSeller:
		return *new Seller(inFile);
	case TypeCustomer:
		return *new Customer(inFile);
	default:
		return *new SellerCustomer(inFile);
	}
}

UserAnalyzer::UserType UserAnalyzer::getType(const User& user)
{
	if (typeid(user) == typeid(Seller))
	{
		return UserType::TypeSeller;
	}
	else if (typeid(user) == typeid(Customer))
	{
		return UserType::TypeCustomer;
	}
	else
	{
		return UserType::TypeSellerCustomer;
	}
}