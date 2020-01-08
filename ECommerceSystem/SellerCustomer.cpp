#include "SellerCustomer.h"

SellerCustomer::SellerCustomer(const char* username, const char* password, const Address& address)
	: User(username, password, address), Seller(username, password, address), Customer(username, password, address)
{
}

void SellerCustomer::show(ostream& os) const
{
	Seller::show(os);
}