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
		AddNewProductToSeller = 1, SellerSearchProduct = 2, SellerViewCustomers = 3,
		SellerViewSellers = 4, SellerLogOut = 5, SellerExit = 6
	};
	enum CustomerOptions
	{
		CustomerSearchProduct = 1, Checkout = 2, WriteFeedback = 3,
		CustomerViewCustomers = 4, CustomerViewSellers = 5, CustomerLogOut = 6, CustomerExit = 7
	};
	enum SearchProductOptions
	{
		AllProducts = 1, SpecificProductName = 2
	};

	enum AddProductOptions
	{
		AddProductToCart = 1, GoBack = 2
	};

	ShopSystem(const char* name); // C'tor
	ShopSystem(const ShopSystem& other) = delete; // Disable copy c'tor
	~ShopSystem(); // D'tor
	void showCustomers() const;
	void showSellers() const;
	void showAllProducts() const;
	void showRequestedProducts(Product** requestedProducts, int numOfRequestedProducts) const;
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
	void searchProducts(Product*** requestedProducts, int& numOfRequestedProducts);
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