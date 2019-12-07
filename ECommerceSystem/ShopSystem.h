#ifndef __SHOP_SYSTEM_H
#define __SHOP_SYSTEM_H

#include "OutResources.h"
#include "Menu.h"
#include "Validations.h"
#include "Customer.h"
#include "Seller.h"
#include "Product.h"

class ShopSystem
{
private:
	const char* name;
	Seller** sellers;
	int numOfSellers;
	Customer** customers;
	int numOfCustomers;
	Product** allProducts;
	int numOfAllProducts;

public:
	// enum declarations
	enum LoginOptions
	{
		SignupNewSeller = 1, SignupNewCustomer = 2, LoginSeller = 3,
		LoginCustomer = 4, Exit = 5
	};
	enum SellerOptions
	{
		AddNewProductToSeller = 1, SellerSearchProduct = 2, ViewProducts = 3,
		SellerViewCustomers = 4, SellerViewSellers = 5, SellerLogOut = 6, SellerExit = 7
	};
	enum CustomerOptions
	{
		CustomerSearchProduct = 1, AddNewProductToCart = 2, ViewCart = 3, Checkout = 4, WriteFeedback = 5,
		CustomerViewCustomers = 6, CustomerViewSellers = 7, CustomerLogOut = 8, CustomerExit = 9
	};
	enum SearchProductOptions
	{
		AllProducts = 1, SpecificProductName = 2
	};

	ShopSystem(const char* name); // C'tor
	ShopSystem(const ShopSystem& other) = delete; // Disable copy c'tor
	~ShopSystem(); // D'tor
	void showCustomers() const;
	void showSellers() const;
	void showAllProducts() const;
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
	void addProductToProductsArray(Product* newProduct, Product*** products, int& numOfProducts);
	void searchProducts();
	void addProductToCart(Customer& customer);
	// Getters
	const char* getName() const;
	Seller** getSellers() const;
	Customer** getCustomers() const;
	int getNumOfSellers() const;
	int getNumOfCustomers() const;
	Product** getAllProducts() const;
	int getNumOfAllProducts() const;
};

#endif // __SHOP_SYSTEM_H