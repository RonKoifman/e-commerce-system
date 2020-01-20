#include "SellerCustomer.h"
#include "UserAnalyzer.h"

User* UserAnalyzer::loadUser(ifstream& inFile)
{
	UserType type;

	inFile.read((char*)&type, sizeof(UserType));

	switch (type)
	{
	case SELLER:
		return new Seller(inFile);
	case CUSTOMER:
		return new Customer(inFile);
	case SELLER_CUSTOMER:
		return new SellerCustomer(inFile);
	default:
		return nullptr;
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
	else if (typeid(user) == typeid(SellerCustomer))
	{
		return SELLER_CUSTOMER;
	}
	else
	{
		return UNKNOWN;
	}
}