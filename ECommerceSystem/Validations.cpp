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
	len = (unsigned int)strlen(str);
	return (len < MAX_CHARACTERS - 1);
}

bool areUsernameCharactersValid(const char* str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z')))
		{
			cout << "Bad character found: '" << str[i] << "'" << endl;
			return false;
		}
		i++;
	}
	return true;
}

bool arePasswordCharactersValid(const char* str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] <  '!') || (str[i] > '~'))  // All character from ! to ~ are allowed (excluding whitespaces and few extra chars)
		{
			cout << "Bad character found: '" << str[i] << "'" << ". Try again!" <<  endl;
			return false;
		}
		i++;
	}
	return true;
}

bool areAddressCharactersValid(const char* str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
		{
			if (str[i] == ' ')
			{
				if ((str[i] == ' ' && str[i + 1] == '\0') || str[0] == ' ' || (str[i] == ' ' && str[i + 1] == ' '))
				{
					cout << "Wrong spacing. ";
					return false;
				}

			}
			else
			{
				cout << "Bad character found: '" << str[i] << "'" << endl;
				return false;
			}
		}
		
		i++;
	}

	return true;
}

void usernameValidation(char* username, const ShopSystem& shop)
{
	bool isValid = false;
	unsigned int len = 0;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Username (maximum 20 characters, letters and numbers only): ";

		if (isStringLengthValid(username, len))
		{
			if (areUsernameCharactersValid(username))
				isValid = true;
			else
				cout << "Use only a-z, A-Z, 0-9 characters. Try again!" << endl;
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

		if (isStringLengthValid(password, len))
		{
			if (len >= 6) {
				if (arePasswordCharactersValid(password))
					isValid = true;
			}
			else
				cout << "Password is too short. Try again!" << endl;
		}
		else
		{
			cout << "Password is too long. Try again!" << endl;
		}
	}
}

void countryValidation(char* country) 
{
	bool isValid = false;
	unsigned int len = 0;

	while (!isValid)
	{
		cout << "Country name(maximum 20 characters, letters only): ";

		if (isStringLengthValid(country, len))
		{
			if (areAddressCharactersValid(country))
				isValid = true;
			else
				cout << "Use only a-z, A-Z or space. Try again!" << endl;
		}
		else
		{
			cout << "Country name is too long. Try again!" << endl;
		}
	}
}

void cityValidation(char *city)
{
	bool isValid = false;
	unsigned int len = 0;

	while (!isValid)
	{
		cout << "City name(maximum 20 characters, letters only): ";

		if (isStringLengthValid(city, len))
		{
			if (areAddressCharactersValid(city))
				isValid = true;
			else
				cout << "Use only a-z, A-Z or space. Try again!" << endl;
		}
		else
		{
			cout << "City name is too long. Try again!" << endl;
		}
	}
}

void streetValidation(char *street)
{
	bool isValid = false;
	unsigned int len = 0;

	while (!isValid)
	{
		cout << "Street name(maximum 20 characters, letters only): ";

		if (isStringLengthValid(street, len))
		{
			if (areAddressCharactersValid(street))
				isValid = true;
			else
				cout << "Use only a-z, A-Z or space. Try again!" << endl;
		}
		else
		{
			cout << "Street name is too long. Try again!" << endl;
		}
	}
}

void buildingNumberValidation(unsigned int& buildingNumber)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Building number: ";
		cin >> buildingNumber;

		if (cinTypeCheck())
		{
			isValid = true;
		}
		else
		{
			cout << "Bad building number, use only 0-9 characters. Try again!" << endl;
		}
	}
}

bool ShopSystem::isUniqueUsernameSeller(char* username, const ShopSystem& shop)
{
	for (unsigned int i = 0; i < shop.getNumOfSellers(); i++)
	{
		if (strcmp(shop.sellers[i]->getUsername(), username) == 0) // Username taken
		{
			return false;
		}
	}

	return true;
}

bool ShopSystem::isUniqueUsernameCustomer(char* username, const ShopSystem& shop)
{
	for (unsigned int i = 0; i < numOfCustomers; i++)
	{
		if (strcmp(customers[i]->getUsername(), username) == 0) // Username taken
		{
			return false;
		}
	}

	return true;
}
