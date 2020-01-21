#include "SellerCustomer.h"
#include "UserAnalyzer.h"

User& UserAnalyzer::loadUser(ifstream& inFile)
{
	UserType type;

	inFile.read((char*)&type, sizeof(UserType));

	switch (type)
	{
	case SELLER:
		return *new Seller(inFile);
	case CUSTOMER:
		return *new Customer(inFile);
	default:
		return *new SellerCustomer(inFile);
	}
}

UserAnalyzer::UserType UserAnalyzer::getType(const User& user)
{
	if (typeid(user) == typeid(Seller))
	{
		return SELLER;
	}
	else if (typeid(user) == typeid(Customer))
	{
		return CUSTOMER;
	}
	else
	{
		return SELLER_CUSTOMER;
	}
}