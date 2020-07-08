#include "ShopSystem.h"

ShopSystem::ShopSystem()
{
	// Load users data if exists
	loadUsers("database.dat");
}

ShopSystem::~ShopSystem()
{
	// Save users data
	saveUsers("database.dat");

	for (User* user : users)
	{
		delete user;
	}
}

const vector<User*>& ShopSystem::getUsers() const
{
	return users;
}

const vector<Product*>& ShopSystem::getAllProducts() const
{
	return allProducts;
}

const ShopSystem& ShopSystem::operator+=(User& user)
{
	users.push_back(&user);

	return *this;
}

void ShopSystem::addNewUser(User& newUser)
{
	*this += newUser;
}

void ShopSystem::addProductToStock(Product& newProduct)
{
	allProducts.push_back(&newProduct);
}

User& ShopSystem::loadUser(ifstream& inFile) const
{
	return *new User(inFile);
}

void ShopSystem::loadUsers(const char* fileName)
{
	unsigned int numOfUsers = 0;
	ifstream inFile(fileName, ios::binary | ios::in);

	inFile.read((char*)&numOfUsers, sizeof(numOfUsers));
	for (unsigned int i = 0; i < numOfUsers; i++)
	{
		users.push_back(&loadUser(inFile));
	}

	inFile.close();
}

void ShopSystem::saveUsers(const char* fileName) const
{
	unsigned int numOfUsers = users.size();
	ofstream outFile(fileName, ios::binary | ios::trunc);

	outFile.write((const char*)&numOfUsers, sizeof(numOfUsers));
	for (User* user : users)
	{
		user->save(outFile);
	}

	outFile.close();
}

bool ShopSystem::isValidProductId(unsigned int id) const
{
	return Product::uniqueId - allProducts.size() <= id && id <= Product::uniqueId - 1;
}

bool ShopSystem::isValidCategory(unsigned int category) const
{
	return 1 <= category && category <= Product::NUM_OF_CATEGORIES;
}

bool ShopSystem::isUsernameExists(string& username, vector<User*> users) const
{
	for (User* user : users)
	{
		if (user->getUsername().compare(username) == 0)
		{
			return true;
		}
	}

	return false;
}

bool ShopSystem::isProductNameExists(const string& productName, vector<Product*> products) const
{
	for (Product* product : products)
	{
		if (product->getName().compare(productName) == 0)
		{
			return true;
		}
	}

	return false;
}

bool ShopSystem::isProductBelongsToUser(User& user, int productId) const
{
	return getProductById(productId, user.getProductsForSale()) != nullptr;
}

bool ShopSystem::isProductExistsInUserCart(User& user, int productId) const
{
	return getProductById(productId, user.getCart()) != nullptr;
}

bool ShopSystem::isProductExistsInUserOrder(Order& order, int productId) const
{
	return getProductById(productId, order.getChosenProducts()) != nullptr;
}

Product* ShopSystem::getProductById(int productId, const vector<Product*>& products) const
{
	for (Product* product : products)
	{
		if (productId == product->getSerialNumber())
		{
			return product;
		}
	}

	return nullptr;
}

User* ShopSystem::getUserByCredentials(string& username, string& password) const
{
	for (User* user : users)
	{
		if (user->getUsername().compare(username) == 0 && user->getPassword().compare(password) == 0)
		{
			return user;
		}
	}

	return nullptr;
}