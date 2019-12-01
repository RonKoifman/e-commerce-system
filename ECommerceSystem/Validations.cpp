#include "OutResources.h"
#include "Validations.h"

void cleanBuffer()
{
	char ch;
	if (cin.fail()) {
		cin.clear();
	}
	int c = int(cin.gcount());
	//cout << "CHAR COUNT: " << c << endl;
	if (c > 0)
		cin.unget();
	if (c == MAX_CHARACTERS - 1 || cin.peek() == int('\n')) {
		do
		{
			cin.get(ch);
		} while (ch != EOF && ch != '\n');
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

bool isStringLengthValid(const char* str, unsigned int& len)
{
	len = (unsigned int)(strlen(str));
	return (len < MAX_CHARACTERS - 1);
}

bool areUsernameCharactersValid(const char* str)
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

bool arePasswordCharactersValid(const char* str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] <  '!') || (str[i] > '~'))  //All character from ! to ~ are allowed (excluding whitespaces and few extra chars).
		{
			cout << "Bad character found: '" << str[i] << "'" <<  endl;
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
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' ')))
		{
			return false;
		}
		i++;
	}

	return true;
}

bool isInt(const char* str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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

		cin.getline(username, MAX_CHARACTERS);
		cleanBuffer();

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

	cleanBuffer();
	while (!isValid)
	{
		cout << "Password (between 6-20 characters): ";
		cin.getline(password, MAX_CHARACTERS);
		cleanBuffer();

		if (isStringLengthValid(password, len))
		{
			if (len >= 6)
				if(arePasswordCharactersValid(password))
					isValid = true;
			else
				cout << "Password is too short. Try again!" << endl;
		}
		else
		{
			cout << "Password is too long. Try again!" << endl;
		}
	}
}

void countryValidation(char *country) 
{
	bool isValid = false;
	unsigned int len = 0;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Country name(maximum 20 characters, letters only): ";
		cin.getline(country, MAX_CHARACTERS);
		cleanBuffer();

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

	cleanBuffer();
	while (!isValid)
	{
		cout << "City name(maximum 20 characters, letters only): ";
		cin.getline(city, MAX_CHARACTERS);
		cleanBuffer();

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

	cleanBuffer();
	while (!isValid)
	{
		cout << "Street name(maximum 20 characters, letters only): ";
		cin.getline(street, MAX_CHARACTERS);
		cleanBuffer();

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
	char number[MAX_CHARACTERS];

	cleanBuffer();
	while (!isValid)
	{
		cout << "Building number: ";
		cin.getline(number, MAX_CHARACTERS);
		cleanBuffer();

		if (isInt(number))
		{
			buildingNumber = atoi(number);
			isValid = true;
		}
		else
		{
			cout << "Wrong building number, use only 0-9 characters. Try again!" << endl;
		}
	}
}