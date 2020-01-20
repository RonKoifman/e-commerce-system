#include "UserAnalyzer.h"
#include "SellerCustomer.h"

User* UserAnalyzer::loadUser(ifstream& inFile)
{
	User* temp;
	userType type;
	inFile.read((char*)&type, sizeof(userType));
	switch (type)
	{
		case SELLER:
		{
			temp = new Seller(inFile);
			break;
		}
		case CUSTOMER:
		{
			temp = new Customer(inFile);
			break;
		}
		case SELLERCUSTOMER:
		{
			temp = new SellerCustomer(inFile);
			break;
		}
		default:
			temp = nullptr;
	}
	return temp;
}

UserAnalyzer::userType UserAnalyzer::getType(const User* user)
{
	if (typeid(*user) == typeid(Seller))
		return SELLER;
	else if (typeid(*user) == typeid(Customer))
		return CUSTOMER;
	else if (typeid(*user) == typeid(SellerCustomer))
		return SELLERCUSTOMER;
	else
		return UNKNOWN;
}
