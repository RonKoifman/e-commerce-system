#ifndef __SHOP_SYSTEM_H
#define __SHOP_SYSTEM_H

#include "OutResources.h"
#include "Validations.h"
#include "Customer.h"
#include "Seller.h"
#include "Product.h"

class ShopSystem
{
private:
	const char* name;
	Seller** sellers;
	unsigned int numOfSellers;
	Customer** customers;
	unsigned int numOfCustomers;

public:
	// enum declarations
	enum LoginOptions
	{
		SignupNewSeller = 1, SignupNewCustomer = 2, LoginSeller = 3,
		LoginCustomer = 4, Exit = 5
	};
	enum SellerOptions
	{
		AddNewProductToSeller = '1', SellerSearchProduct = '2', SellerViewCustomers = '3',
		SellerViewSellers = '4', SellerLogOut = '5', SellerExit = '6'
	};
	enum CustomerOptions
	{
		CustomerSearchProduct = '1', AddNewProductToCart = '2', Checkout = '3', WriteFeedback = '4',
		CustomerViewCustomers = '5', CustomerViewSellers = '6', CustomerLogOut = '7', CustomerExit = '8'
	};

	ShopSystem(const char* name); // C'tor
	ShopSystem(const ShopSystem& other) = delete; // Disable copy c'tor
	~ShopSystem(); // D'tor
	const char* getName() const;
	void showCustomers() const;
	void showSellers() const;
	bool showLoginMenu();
	bool showSellerMenu(Seller& seller);
	bool showCustomerMenu(Customer& seller);
	Seller* readSellerData();
	void addSeller(Seller* seller);
	Customer* readCustomerData();
	void addCustomer(Customer* customer);
	Product* readProductData(Seller* seller);
	Seller* loginSeller(char* username, char* password);
	Customer* loginCustomer(char* username, char* password);
};

#endif // __SHOP_SYSTEM_H
