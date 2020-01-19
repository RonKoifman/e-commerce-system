#include "SellerCustomer.h"

SellerCustomer::SellerCustomer(const string& username, const string& password, const Address& address)
	: User(username, password, address), Seller(username, password, address), Customer(username, password, address)
{
}

void SellerCustomer::show(ostream& os) const
{
	Seller::show(os);
}