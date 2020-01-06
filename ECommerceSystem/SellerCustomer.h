#ifndef __SELLERCUSTOMER_H
#define __SELLERCUSTOMER_H

#include "Seller.h"
#include "Customer.h"

class SellerCustomer : public Seller, public Customer
{
public:
	SellerCustomer(const char* username, const char* password, const Address& address); // C'tor
	SellerCustomer(const SellerCustomer& other) = delete; // Disable copy c'tor
	const SellerCustomer& operator=(const SellerCustomer& other) = delete; // Disable operator=
	virtual void show() const override;
	// Friend functions
	friend Product* readProductData(Seller* seller);
};

#endif // __SELLERCUSTOMER_H