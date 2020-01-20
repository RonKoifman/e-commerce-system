#include "SellerCustomer.h"

SellerCustomer::SellerCustomer(const string& username, const string& password, const Address& address)
	: User(username, password, address), Seller(username, password, address), Customer(username, password, address)
{
}

SellerCustomer::SellerCustomer(ifstream& inFile) // C'tor for file
	: User(inFile), Seller(inFile), Customer(inFile)
{
}

void SellerCustomer::show(ostream& os) const
{
	Seller::show(os);
}