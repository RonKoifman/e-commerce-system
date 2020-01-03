#ifndef __SELLERCUSTOMER_H
#define __SELLERCUSTOMER_H

#include "Feedback.h"
#include "Product.h"
#include "Validations.h"
#include "Seller.h"
#include "Customer.h"


class SellerCustomer : public Seller, Customer
{
private:
	/*char* username;
	char* password;
	Address address;*/

public:
	SellerCustomer(const char* username, const char* password, const Address& address); // C'tor
	SellerCustomer(const SellerCustomer& other) = delete; // Disable copy c'tor
	~SellerCustomer(); // D'tor
	//virtual void show(ostream& os) const override;
	virtual void show() const;
	// Friend functions
	friend Product* readProductData(Seller* seller);
};

#endif // __SELLERCUSTOMER_H