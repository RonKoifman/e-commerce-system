#ifndef __VALIDATIONS_H
#define __VALIDATIONS_H

class ShopSystem;

#include "OutResources.h"
#include "ShopSystem.h"
#include "Product.h"

void cleanBuffer();
bool getInput(char* str, int& len, const int maxLen);
bool cinTypeCheck();
void usernameValidation(char* username, const ShopSystem& shop);
void passwordValidation(char* password);
bool checkLettersAndDigits(const char* str);
bool checkSpecialCharacters(const char* str);
bool checkLetters(const char* str);
bool checkLettersDigitsAndSpace(const char* str);
void countryValidation(char* country);
void cityValidation(char *city);
void streetValidation(char *street);
void buildingNumberValidation(int& buildingNumber);
bool uniqueUsername(char* username, const ShopSystem& shop);
void productNameValidation(char* productName, Seller& seller);
bool isProductExists(char* productName, Product** products, int numOfProductsInCart);
void priceValidation(float& price);
void categoryValidation(int& category);
void searchProductSelectionValidation(int& selection);
void searchProductNameValidation(char* productName);
bool addProductToCartValidation(unsigned int& productID, const int numOfAllProducts);
Product* indexOfCheckoutProductValidation(int& index, Product** cart, int numOfProductsInCart, Product** chosenProducts, int numOfChosenProducts);
bool isSellerExists(Seller* seller, Seller** sellers, int numOfSellers);
<<<<<<< HEAD
void dateValidation(int& day, int& month, int& year);
=======
bool dateValidation(int day, int month, int year);
>>>>>>> 0fd21c783a2960f3cb4b019d6a5e9e2acc3fa3f2

#endif // __VALIDATIONS_