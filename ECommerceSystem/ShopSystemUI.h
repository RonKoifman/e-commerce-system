#ifndef __SHOP_SYSTEM_UI_H
#define __SHOP_SYSTEM_UI_H

#include "ShopSystem.h"
#include "Feedback.h"

class ShopSystemUI
{
private:
	ShopSystem shopSystem;

public:
	void runShopSystem();

private:
	void showLoginMenu() const;
	void showMainMenu() const;
	bool isEmptyString(string& str) const;
	bool isValidPositiveIntNumber(string& str) const;
	void getNonEmptyStringFromUser(const char* msgToUser, string& userInput) const;
	void getPositiveNumberFromUser(const char* msgToUser, int& userInput) const;
	void getPositiveNumberFromUser(const char* msgToUser, float& userInput) const;
	void runLoginMenu(bool& toExit); 
	void runMainMenu(User& user, bool& toExit);
	User& readUserData() const;
	Product& readProductData(User& user) const;
	Date readDate() const;
	void getUsernameInputFromUser(const char* msgToUser, string& userInput) const;
	void getProductNameInputFromUser(const char* msgToUser, string& userInput, User& user) const;
	void getCategoryInputFromUser(const char* msgToUser, int& userInput) const;
	void loginUser(bool& toExit);
	void signupUser(bool& toExit);
	void searchProducts() const;
	void showProductsByName() const;
	void addNewProductForSale(User& user);
	bool getValidProductIdToSearch(int& productId) const;
	bool getValidOrderIndexForFeedback(User& user, int& orderIndex) const;
	bool getValidProductIndexForFeedback(Order& selectedOrder, int& productIndex) const;
	void getFeedbackFromUserAndAddToSeller(Product& chosenProduct, User& customer) const;
	void showAllUsers() const;
	void showAllProducts() const;
	void waitForKeyToContinue() const;
	void viewUserCart(User& user) const;
	void viewUserOrders(User& user) const;
	void viewUserProducts(User& user) const;
	void viewUserFeedbacks(User& user) const;
	void addProductToUserCart(User& user) const;
	void checkoutUserAndPlaceOrder(User& user) const;
	Order& createNewOrder(User& user) const;
	Product* getProductToAddToOrder(User& user, Order& order) const;
	void placeOrder(Order& order) const;
	void writeFeedbackToOtherUser(User& user) const;

	enum eLoginOptions
	{
		Signup = 1,
		Login,
		LoginMenuExit
	};
	enum eRegisteredUserOptions
	{
		AddNewProductForSale = 1,
		SearchProducts,
		AddProductToCart,
		ViewCart,
		CheckoutAndPlaceOrder,
		WriteFeedback,
		ViewPersonalProducts,
		ViewPersonalFeedbacks,
		ViewOrders,
		ViewAllUsers,
		Logout,
		MainMenuExit
	};
	enum eSearchProductsOptions
	{
		AllProducts = 1,
		SpecificProductName
	};
};

#endif // __SHOP_SYSTEM_UI_H