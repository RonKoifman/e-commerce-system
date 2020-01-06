#ifndef __SHOP_SYSTEM_H
#define __SHOP_SYSTEM_H

#include "Menu.h"
#include "Checkout.h"
#include "SellerCustomer.h"

class ShopSystem
{
private:
	char* name;
	User** users;
	int numOfUsers;
	Product** allProducts;
	int numOfAllProducts;

public:
	ShopSystem(const char* name); // C'tor
	ShopSystem(const ShopSystem& other) = delete; // Disable copy c'tor
	const ShopSystem& operator=(const ShopSystem& other) = delete; // Disable operator=
	~ShopSystem(); // D'tor
	void setName(const char* name);
	void showCustomers() const;
	void showSellers() const;
	void showSellerCustomers() const;
	void showAllProducts() const;
	bool showLoginMenu();
	bool showSellerMenu(Seller& seller);
	bool showCustomerMenu(Customer& seller);
	User* readUserData(bool isCustomer, bool isSeller, bool isSellerCustomer);
	void addUser(User* user);
	void addProduct(Product* newProduct);
	User* loginUser(char* username, char* password);
	void searchProducts() const;
	void addProductToCart(Customer& customer);
	void checkout(Customer* customer);
	Date readDate();
	void getTextForFeedback(char* text) const;
	void writeFeedback(Customer& customer);
	// Getters
	char* getName() const;
	User** getUsers() const;
	int getNumOfUsers() const;
	Product** getAllProducts() const;
	int getNumOfAllProducts() const;

	// enum declarations
	enum LoginOptions
	{
		SignupNewSeller = 1, SignupNewCustomer = 2, SignupNewSC = 3, Login = 4,
		ViewCustomers = 5, ViewSellers = 6, ViewSC = 7, Exit = 8
	};
	enum SellerOptions
	{
		AddNewProduct = 1, SellerSearchProduct = 2, ViewProducts = 3, ViewFeedbacks = 4,
		SellerLogOut = 5, SellerExit = 6
	};
	enum CustomerOptions
	{
		CustomerSearchProduct = 1, AddProductToCart = 2, ViewCart = 3, CheckoutAndPlaceOrder = 4,
		WriteFeedback = 5, CustomerLogOut = 6, CustomerExit = 7
	};
	enum SellerCustomerOptions
	{
		SCSearchProduct = 1, SCAddProductToCart = 2, SCViewCart = 3, SCCheckoutAndPlaceOrder = 4,
		SCWriteFeedback = 5, SCAddNewProduct = 6, SCViewProducts = 7, SCViewFeedbacks = 8,
		SCLogOut = 9, SCExit = 10
	};
	enum SearchProductOptions
	{
		AllProducts = 1, SpecificProductName = 2
	};
};

#endif // __SHOP_SYSTEM_H