#ifndef __VALIDATIONS_H
#define __VALIDATIONS_H

void cleanBuffer();
bool cinTypeCheck();
void usernameValidation(char* username);
bool isStringLengthValid(char* str, unsigned int& length);
bool areCharactersValid(char* str);
void passwordValidation(char* password);
void getInput(char* str);

#endif // __VALIDATIONS_H