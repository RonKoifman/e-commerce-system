#ifndef __SHOP_SYSTEM_H
#define __SHOP_SYSTEM_H

#include "Menu.h"
#include "Checkout.h"
#include "SellerCustomer.h"
#include "UserAnalyzer.h"

class ShopSystem
{
private:
	vector<User*> users;
	vector<Product*> allProducts;

public:
	// Enum declarations
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

	ShopSystem(); // C'tor
	ShopSystem(const ShopSystem& other) = delete; // Disable copy c'tor
	const ShopSystem& operator=(const ShopSystem& other) = delete; // Disable operator=
	~ShopSystem(); // D'tor
	const ShopSystem& operator+=(User& user);
	void showSelectedUsers(const string& selectedUsersType) const;
	void showAllProducts() const;
	void runProgram();
	bool mainMenu();
	bool sellerMenu(User& user);
	bool customerMenu(User& user);
	bool sellerCustomerMenu(User& user);
	User& readUserData(UserAnalyzer::UserType type) const;
	Product& readProductData(User& user) const;
	Date readDate() const;
	void readTextForFeedback(string& text) const;
	User* loginUser() const;
	void searchProducts() const;
	void addProductToStock(Product& newProduct);
	void addProductToUserCart(User& user) const;
	void checkout(User& user) const;
	void placeOrder(const Checkout& order) const;
	void writeFeedback(User& user) const;
	void compareUsersCartsAmount() const;
	void loadUsers(const char* fileName);
	void saveUsers(const char* fileName);
	// Getters
	const string& getName() const;
	const vector<User*>& getUsers() const;
	const vector<Product*>& getAllProducts() const;
};

#endif // __SHOP_SYSTEM_H