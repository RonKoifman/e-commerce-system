#ifndef __VALIDATIONS_H
#define __VALIDATIONS_H

// Consts declaration
const int MAX_CHARACTERS = 20;
const int MAX_PRODUCT_NAME_LENGTH = 30;
const int MIN_CHARACTERS_PASSWORD = 6;
const int MAX_FEEDBACK_LENGTH = 90;
const int MAX_CATEGORIES = 4;
const int CURRENT_YEAR = 2020;

class Validations
{
public:
	void cleanBuffer();
	bool getInput(string& str, const int maxLen);
	bool cinTypeCheck();
	void usernameValidation(string& username, User** users, int numOfUsers);
	bool checkUniqueUsername(const string& username, User** users, int numOfUsers);
	void passwordValidation(string& password);
	bool checkLettersAndDigits(const string& str);
	bool checkSpecialCharacters(const string& str);
	bool checkLettersAndSpace(const string& str);
	bool checkLettersDigitsAndSpace(const string& str);
	void countryValidation(string& country);
	void cityValidation(string& city);
	void streetValidation(string& street);
	void buildingNumberValidation(int& buildingNumber);
	void productNameValidation(string& productName, User& user);
	bool isProductNameExists(const string& productName, Product** products, int numOfProducts);
	void priceValidation(float& price);
	void categoryValidation(int& category);
	bool productSerialNumberValidation(unsigned int& productID, int numOfAllProducts);
	bool isProductExists(int productSerialNumber, Product** products, int numOfProducts);
	bool isProductBelongsToUser(User& user, int productSerialNumber);
	bool searchProductSelectionValidation(int& selection);
	Product* indexOfCheckoutProductValidation(int& index, Product** cart, int numOfProductsInCart, Product** chosenProducts, int numOfChosenProducts);
	bool isSellerExists(const User& seller, User** sellers, int numOfSellers);
	void dateValidation(int& day, int& month, int& year);
	bool areValidUsers(User** users, int numOfUsers, int& indexUser1, int& indexUser2);
};

#endif // __VALIDATIONS_