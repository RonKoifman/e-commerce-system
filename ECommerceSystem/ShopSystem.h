#ifndef __SHOP_SYSTEM_H
#define __SHOP_SYSTEM_H

#include "Menu.h"
#include "Checkout.h"
#include "SellerCustomer.h"
#include "UserAnalyzer.h"

class ShopSystem
{
private:
	string name;
	vector<User*> users;
	vector<Product*> allProducts;

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

	ShopSystem(const string& name); // C'tor
	ShopSystem(const ShopSystem& other) = delete; // Disable copy c'tor
	const ShopSystem& operator=(const ShopSystem& other) = delete; // Disable operator=
	~ShopSystem(); // D'tor
	const ShopSystem& operator+=(User& user);
	void setName(const string& name);
	void showCustomers() const;
	void showSellers() const;
	void showSellerCustomers() const;
	void showAllProducts() const;
	bool mainMenu();
	bool sellerMenu(User& user);
	bool customerMenu(User& user);
	bool sellerCustomerMenu(User& user);
	User& readUserData(UserType type) const;
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
	void loadAllUsers(const char* fileName);
	void saveUsers(const char* fileName);

	// Getters
	const string& getName() const;
	vector<User*> getUsers() const;
	vector<Product*> getAllProducts() const;
};

#endif // __SHOP_SYSTEM_H