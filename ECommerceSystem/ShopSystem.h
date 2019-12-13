#ifndef __SHOP_SYSTEM_H
#define __SHOP_SYSTEM_H

#include "OutResources.h"
#include "Menu.h"
#include "Validations.h"
#include "Customer.h"
#include "Seller.h"
#include "Product.h"
#include "Checkout.h"

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
		LoginCustomer = 4, ViewCustomers = 5, ViewSellers = 6, Exit = 7
	};
	enum SellerOptions
	{
		AddNewProductToSeller = 1, SellerSearchProduct = 2, ViewProducts = 3, ViewFeedbacks = 4,
		SellerLogOut = 5, SellerExit = 6
	};
	enum CustomerOptions
	{
		CustomerSearchProduct = 1, AddNewProductToCart = 2, ViewCart = 3, CheckoutAndPlaceOrder = 4,
		WriteFeedback = 5, CustomerLogOut = 6, CustomerExit = 7
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
	void addSeller(Seller* seller);
	void addCustomer(Customer* customer);
	void addProduct(Product* newProduct);
	Seller* loginSeller(char* username, char* password);
	Customer* loginCustomer(char* username, char* password);
	void searchProducts();
	void addProductToCart(Customer& customer);
	void checkout(Customer* customer);
	Date readDate();
	void getTextForFeedback(char* text);
	void writeFeedback(Customer& customer);
	// Getters
	const char* getName() const;
	Seller** getSellers() const;
	Customer** getCustomers() const;
	int getNumOfSellers() const;
	int getNumOfCustomers() const;
	Product** getAllProducts() const;
	int getNumOfAllProducts() const;
	// Friend functions
	friend Customer* readCustomerData(const ShopSystem& shop);
	friend Seller* readSellerData(const ShopSystem& shop);
	friend Product* readProductData(Seller* seller);
};

#endif // __SHOP_SYSTEM_H