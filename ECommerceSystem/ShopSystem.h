#ifndef __SHOP_SYSTEM_H
#define __SHOP_SYSTEM_H

#include "User.h"

class ShopSystem
{
private:
	vector<User*> users;
	vector<Product*> allProducts;

public:
	ShopSystem();
	ShopSystem(const ShopSystem& other) = delete;
	const ShopSystem& operator=(const ShopSystem& other) = delete;
	~ShopSystem();
	const ShopSystem& operator+=(User& user);
	void loadUsers(const char* fileName);
	User& loadUser(ifstream& inFile) const;
	void saveUsers(const char* fileName) const;
	void addProductToStock(Product& newProduct);
	void addNewUser(User& newUser);
	bool isUsernameExists(string& username, vector<User*> users) const;
	bool isProductNameExists(const string& productName, vector<Product*> products) const;
	bool isProductBelongsToUser(User& user, int productId) const;
	bool isProductExistsInUserCart(User& user, int productId) const;
	bool isProductExistsInUserOrder(Checkout& order, int productId) const;
	bool isValidProductId(unsigned int id) const;
	bool isValidCategory(unsigned int category) const;
	User* getUserByCredentials(string& username, string& password) const;
	Product* getProductById(int productSerialNumber, const vector<Product*>& products) const;
	// Getters
	const vector<User*>& getUsers() const;
	const vector<Product*>& getAllProducts() const;
};

#endif // __SHOP_SYSTEM_H