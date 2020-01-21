#ifndef __SELLER_CUSTOMER_H
#define __SELLER_CUSTOMER_H

#include "Seller.h"
#include "Customer.h"

class SellerCustomer : public Seller, public Customer
{
public:
	SellerCustomer(const string& username, const string& password, const Address& address); // C'tor
	SellerCustomer(ifstream& inFile); // C'tor for file
	SellerCustomer(const SellerCustomer& other) = delete; // Disable copy c'tor
	const SellerCustomer& operator=(const SellerCustomer& other) = delete; // Disable operator=
	virtual void show(ostream& os) const override;
};

#endif // __SELLER_CUSTOMER_H