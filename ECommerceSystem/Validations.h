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
	static void cleanBuffer();
	static bool getInput(string& str, const int maxLen);
	static bool cinTypeCheck();
	static void usernameValidation(string& username, const vector<User*>& users);
	static bool checkUniqueUsername(const string& username, const vector<User*>& users);
	static void passwordValidation(string& password);
	static bool checkLettersAndDigits(const string& str);
	static bool checkSpecialCharacters(const string& str);
	static bool checkLettersAndSpace(const string& str);
	static bool checkLettersDigitsAndSpace(const string& str);
	static void countryValidation(string& country);
	static void cityValidation(string& city);
	static void streetValidation(string& street);
	static void buildingNumberValidation(int& buildingNumber);
	static void productNameValidation(string& productName, User& user);
	static bool isProductNameExists(const string& productName, const vector<Product*>& products);
	static void priceValidation(float& price);
	static void categoryValidation(int& category);
	static bool productSerialNumberValidation(unsigned int& productID, int numOfAllProducts);
	static bool isProductExists(int productSerialNumber, const vector<Product*>& products);
	static bool isProductBelongsToUser(User& user, int productSerialNumber);
	static bool searchProductSelectionValidation(int& selection);
	static Product* indexOfCheckoutProductValidation(unsigned int& index, const vector<Product*>& cart, const vector<Product*>& chosenProducts);
	static bool isSellerExists(const User& seller, const vector<User*>& sellers);
	static void dateValidation(int& day, int& month, int& year);
	static bool areValidUsers(const vector<User*>& users, int& indexUser1, int& indexUser2);
};

#endif // __VALIDATIONS_H