#ifndef __VALIDATIONS_H
#define __VALIDATIONS_H

class ShopSystem;

#include "OutResources.h"
#include "ShopSystem.h"


void cleanBuffer();
void getInput(char* str);
bool cinTypeCheck();
void usernameValidation(char* username, const ShopSystem& shop);
bool isStringLengthValid(const char* str, unsigned int& length);
bool areUsernameCharactersValid(const char* str);
bool arePasswordCharactersValid(const char* str);
bool areAddressCharactersValid(const char* str);
void passwordValidation(char* password);
void countryValidation(char* country);
void cityValidation(char *city);
void streetValidation(char *street);
void buildingNumberValidation(unsigned int& buildingNumber);
bool isUniqueUsernameSeller(char* username, const ShopSystem& shop);
bool isUniqueUsernameCustomer(char* username, const ShopSystem& shop);

#endif // __VALIDATIONS_
