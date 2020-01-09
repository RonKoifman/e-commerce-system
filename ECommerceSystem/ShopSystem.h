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
	// Enum declarations
	enum UserType
	{
		TypeSeller = 1, TypeCustomer = 2, TypeSellerCustomer = 3
	};
	enum LoginOptions
	{
		SignupNewSeller = 1, SignupNewCustomer = 2, SignupNewSC = 3, Login = 4,
		ViewCustomers = 5, ViewSellers = 6, ViewSC = 7, CompareCarts = 8, Exit = 9
	};
	enum SellerOptions
	{
		AddNewProduct = 1, SellerSearchProduct = 2, ViewProducts = 3, ViewFeedbacks = 4,
		SellerPreviousMenu = 5, SellerExit = 6
	};
	enum CustomerOptions
	{
		CustomerSearchProduct = 1, AddProductToCart = 2, ViewCart = 3, CheckoutAndPlaceOrder = 4,
		WriteFeedback = 5, CustomerPreviousMenu = 6, CustomerExit = 7
	};
	enum SellerCustomerOptions
	{
		ViewCustomerMenu = 1, ViewSellerMenu = 2, SCPreviousMenu = 3, SCExit = 4
	};
	enum SearchProductOptions
	{
		AllProducts = 1, SpecificProductName = 2
	};

	ShopSystem(const char* name); // C'tor
	ShopSystem(const ShopSystem& other) = delete; // Disable copy c'tor
	const ShopSystem& operator=(const ShopSystem& other) = delete; // Disable operator=
	~ShopSystem(); // D'tor
	const ShopSystem& operator+=(User& user);
	void setName(const char* name);
	void showCustomers() const;
	void showSellers() const;
	void showSellerCustomers() const;
	void showAllProducts() const;
	bool mainMenu();
	bool sellerMenu(User* user);
	bool customerMenu(User* user);
	bool sellerCustomerMenu(User* user);
	User* readUserData(UserType type);
	Product* readProductData(User* user);
	Date readDate();
	void readTextForFeedback(char* text) const;
	User* loginUser();
	void searchProducts() const;
	void addProductToStock(Product* newProduct);
	void addProductToUserCart(User* user);
	void checkout(User* user);
	void writeFeedback(User* user);
	void compareUsersCartsAmount() const;
	// Getters
	char* getName() const;
	User** getUsers() const;
	int getNumOfUsers() const;
	Product** getAllProducts() const;
	int getNumOfAllProducts() const;
};

#endif // __SHOP_SYSTEM_H