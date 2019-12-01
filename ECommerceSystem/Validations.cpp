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

bool areCharactersValid(const char* str)
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

		cin.getline(username, MAX_CHARACTERS);
		cleanBuffer();

		if (isStringLengthValid(username, len))
		{
			if (areCharactersValid(username))
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