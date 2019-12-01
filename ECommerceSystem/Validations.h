#ifndef __VALIDATIONS_H
#define __VALIDATIONS_H

void cleanBuffer();
bool cinTypeCheck();
void usernameValidation(char* username);
bool isStringLengthValid(const char* str, unsigned int& length);
bool areUsernameCharactersValid(const char* str);
bool arePasswordCharactersValid(const char* str);
bool areAddressCharactersValid(const char* str);
bool isInt(const char* str);
void passwordValidation(char* password);
void countryValidation(char *country);
void cityValidation(char *city);
void streetValidation(char *street);
void buildingNumberValidation(unsigned int& buildingNumber);


#endif // __VALIDATIONS_H
