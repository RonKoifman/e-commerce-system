#include "OutResources.h"
#include "Validations.h"

void cleanBuffer()
{
	char ch;

	do
	{
		ch = getchar();
	} while (ch != EOF && ch != '\n');
}

void getInput(char* str)
{
	unsigned int i = 0;
	char ch = ' ';

	// Get input from buffer
	while (i < MAX_CHARACTERS - 1 && ch != '\n')
	{
		ch = getchar();
		if (ch != '\n')
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';

	// Invalid string length
	if (i == MAX_CHARACTERS - 1)
	{
		cleanBuffer();
		str[0] = '\0'; // Initialize string to empty string
	}
}

bool cinTypeCheck()
{
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false; // The input does not match the expected type
	}

	return true;
}

bool isStringLengthValid(char* str, unsigned int& len)
{
	getInput(str);
	len = strlen(str);
	return (0 < len && len < MAX_CHARACTERS - 1);
}

bool areCharactersValid(char* str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z')))
		{
			return false;
		}
		i++;
	}

	return true;
}

void usernameValidation(char* username)
{
	bool isValid = false;
	unsigned int len = 0;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Username (maximum 20 characters, letters and numbers only): ";

		if (isStringLengthValid(username, len))
		{
			if (areCharactersValid(username))
			{
				isValid = true;
			}
			else
			{
				cout << "Use only a-z, A-Z, 0-9 characters. Try again!" << endl;
			}
		}
		else
		{
			cout << "Username is too long. Try again!" << endl;
		}
	}
}

void passwordValidation(char* password)
{
	bool isValid = false;
	unsigned int len = 0;

	while (!isValid)
	{
		cout << "Password (between 6-20 characters): ";
		cin.getline(password, MAX_CHARACTERS);

		if (isStringLengthValid(password, len))
		{
			if (len >= 6)
			{
				isValid = true;
			}
			else
			{
				cout << "Password is too short. Try again!" << endl;
			}
		}
		else
		{
			cout << "Password is too long. Try again!" << endl;
		}
	}
}