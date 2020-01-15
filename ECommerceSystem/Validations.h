#ifndef __VALIDATIONS_H
#define __VALIDATIONS_H

// Consts declaration
const int MAX_CHARACTERS = 22;
const int MAX_PRODUCT_NAME_LENGTH = 32;
const int MIN_CHARACTERS_PASSWORD = 6;
const int MAX_FEEDBACK_LENGTH = 92;
const int MAX_CATEGORIES = 4;
const int CURRENT_YEAR = 2020;

class Validations
{
public:
	void cleanBuffer();
	bool getInput(char* str, const int maxLen);
	bool cinTypeCheck();
	void usernameValidation(char* username, User** users, int numOfUsers);
	bool checkUniqueUsername(const char* username, User** users, int numOfUsers);
	void passwordValidation(char* password);
	bool checkLettersAndDigits(const char* str);
	bool checkSpecialCharacters(const char* str);
	bool checkLettersAndSpace(const char* str);
	bool checkLettersDigitsAndSpace(const char* str);
	void countryValidation(char* country);
	void cityValidation(char* city);
	void streetValidation(char* street);
	void buildingNumberValidation(int& buildingNumber);
	void productNameValidation(char* productName, User* user);
	bool isProductNameExists(const char* productName, Product** products, int numOfProducts);
	void priceValidation(float& price);
	void categoryValidation(int& category);
	bool productSerialNumberValidation(unsigned int& productID, int numOfAllProducts);
	bool isProductExists(int productSerialNumber, Product** products, int numOfProducts);
	bool isProductBelongsToUser(User* user, int productSerialNumber);
	bool searchProductSelectionValidation(int& selection);
	Product* indexOfCheckoutProductValidation(int& index, Product** cart, int numOfProductsInCart, Product** chosenProducts, int numOfChosenProducts);
	bool isSellerExists(User* seller, User** sellers, int numOfSellers);
	void dateValidation(int& day, int& month, int& year);
	bool areValidUsers(User** users, int numOfUsers, int& indexUser1, int& indexUser2);
};

#endif // __VALIDATIONS_