#ifndef __VALIDATIONS_H
#define __VALIDATIONS_H

void cleanBuffer();
bool cinTypeCheck();
void usernameValidation(char* username);
bool isStringLengthValid(const char* str, unsigned int& length);
bool areCharactersValid(const char* str);
void passwordValidation(char* password);
void getInput(char* str);

#endif // __VALIDATIONS_H
