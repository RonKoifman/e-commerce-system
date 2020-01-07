#include "ShopSystem.h"
#include "Validations.h"

void cleanBuffer()
{
	char ch;

	do
	{
		ch = getchar();
	} while (ch != EOF && ch != '\n');
}

bool getInput(char* str, int& len, const int maxLen)
{
	int i = 0;
	char ch = ' ';

	// Get input from buffer
	while (i < maxLen - 1 && ch != '\n')
	{
		ch = getchar();
		if (ch != '\n')
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	len = i;

	// Invalid string length or an empty string
	if (len == maxLen - 1 || len == 0)
	{
		if (len > 0)
		{
			cleanBuffer();
		}
		return false;
	}

	return true; // Valid length
}

bool cinTypeCheck()
{
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false; // The input does not match the expected type
	}

	return true; // Valid type
}

bool checkLettersAndDigits(const char* str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z')))
		{
			cout << "Invalid character found: '" << str[i] << "'" << endl;
			return false;
		}
		i++;
	}
	return true;
}

bool checkLettersDigitsAndSpace(const char* str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
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
				cout << "Invalid character found: '" << str[i] << "'" << endl;
				return false;
			}
		}
		i++;
	}

	return true;
}

bool checkSpecialCharacters(const char* str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] < '!') || (str[i] > '~'))  // All characters from '!' to '~'y' are allowed (excluding whitespaces and few extra chars)
		{
			cout << "Invalid character found: '" << str[i] << "'" << ". Try again!" << endl;
			return false;
		}
		i++;
	}
	return true;
}

bool checkLetters(const char* str)
{
	int i = 0;

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
				cout << "Invalid character found: '" << str[i] << "'" << endl;
				return false;
			}
		}
		i++;
	}

	return true;
}

void usernameValidation(char* username, User** users, int numOfUsers)
{
	bool isValid = false;
	int len = 0;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Username (maximum 20 characters, letters and digits only): ";

		if (getInput(username, len, MAX_CHARACTERS))
		{
			if (checkLettersAndDigits(username))
			{
				isValid = checkUniqueUsername(username, users, numOfUsers);
			}
			else
			{
				cout << "Use only a-z, A-Z, 0-9 characters. Try again!" << endl;
			}
		}
		else
		{
			cout << "Invalid username length. Try again!" << endl;
		}
	}
}

void passwordValidation(char* password)
{
	bool isValid = false;
	int len = 0;

	while (!isValid)
	{
		cout << "Password (between 6-20 characters): ";

		if (getInput(password, len, MAX_CHARACTERS))
		{
			if (strlen(password) >= MIN_CHARACTERS_PASSWORD) 
			{
				if (checkSpecialCharacters(password))
				{
					isValid = true;
				}
			}
			else
			{
				cout << "Password is too short. Try again!" << endl;
			}
		}
		else
		{
			cout << "Invalid password length. Try again!" << endl;
		}
	}
}

void countryValidation(char* country)
{
	bool isValid = false;
	int len = 0;

	while (!isValid)
	{
		cout << "Country (maximum 20 characters, letters and space only): ";

		if (getInput(country, len, MAX_CHARACTERS))
		{
			if (checkLetters(country))
			{
				isValid = true;
			}
			else
			{
				cout << "Use only a-z, A-Z or space. Try again!" << endl;
			}
		}
		else
		{
			cout << "Invalid country name length. Try again!" << endl;
		}
	}
}

void cityValidation(char* city)
{
	bool isValid = false;
	int len = 0;

	while (!isValid)
	{
		cout << "City (maximum 20 characters, letters and space only): ";

		if (getInput(city, len, MAX_CHARACTERS))
		{
			if (checkLetters(city))
			{
				isValid = true;
			}
			else
			{
				cout << "Use only a-z, A-Z or space. Try again!" << endl;
			}
		}
		else
		{
			cout << "Invalid city name length. Try again!" << endl;
		}
	}
}

void streetValidation(char* street)
{
	bool isValid = false;
	int len = 0;

	while (!isValid)
	{
		cout << "Street (maximum 20 characters, letters and space only): ";

		if (getInput(street, len, MAX_CHARACTERS))
		{
			if (checkLetters(street))
			{
				isValid = true;
			}
			else
			{
				cout << "Use only a-z, A-Z or space. Try again!" << endl;
			}
		}
		else
		{
			cout << "Invalid street name length. Try again!" << endl;
		}
	}
}

void buildingNumberValidation(int& buildingNumber)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Building number: ";
		cin >> buildingNumber;

		if (cinTypeCheck() && buildingNumber > 0)
		{
			isValid = true;
		}
		else
		{
			cout << "Invalid building number. Try again!" << endl;
		}
	}
}

bool checkUniqueUsername(char* username, User** users, int numOfUsers)
{
	for (int i = 0; i < numOfUsers; i++) // Search through all users
	{
		if (strcmp(users[i]->getUsername(), username) == 0) // Username taken
		{
			cout << "Username taken! Please choose a different username." << endl;
			return false;
		}
	}

	return true;
}

void productNameValidation(char* productName, User* user)
{
	Seller* seller = dynamic_cast<Seller*>(user);
	bool isValid = false;
	int len = 0;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Product name (maximum 30 characters, letters digits and space only): ";

		if (getInput(productName, len, MAX_PRODUCT_NAME_LENGTH))
		{
			if (checkLettersDigitsAndSpace(productName))
			{
				if (!isProductExists(productName, seller->getProducts(), seller->getNumOfProducts()))
				{
					isValid = true;
				}
				else
				{
					cout << "You already added this product. Please add a different one." << endl;
				}
			}
			else
			{
				cout << "Product name is not valid. Try again!" << endl;
			}
		}
		else
		{
			cout << "Invalid product name length. Try again!" << endl;
		}
	}
}

bool isProductExists(char* productName, Product** products, int numOfProducts)
{
	for (int i = 0; i < numOfProducts; i++)
	{
		if (strcmp(productName, products[i]->getName()) == 0) // Product already exists
		{
			return true;
		}
	}

	return false;
}

void priceValidation(float& price)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Price: ";
		cin >> price;

		if (cinTypeCheck() && price >= 0)
		{
			isValid = true;
		}
		else
		{
			cout << "Invalid price. Try again!" << endl;
		}
	}
}

void categoryValidation(int& category)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Category (choose from the following: 1-Clothing, 2-Kids, 3-Electricity, 4-Office): ";
		cin >> category;

		if (cinTypeCheck() && (1 <= category && category <= 4))
		{
			isValid = true;
		}
		else
		{
			cout << "Invalid category. Try again!" << endl;
		}
	}
}

bool searchProductSelectionValidation(int& selection)
{
	cout << "Press 1 to show all products in the shop." << endl;
	cout << "Press 2 to search a product by name." << endl;
	cout << "Your selection: ";

	cin >> selection;
	cout << endl;

	if (cinTypeCheck() && (selection == ShopSystem::AllProducts || selection == ShopSystem::SpecificProductName))
	{
		return true;
	}
	else
	{
		cout << "Invalid selection!\n" << endl;
		return false;
	}
}

bool searchProductNameValidation(char* productName)
{
	int len = 0;

	// Get a name of a product to search
	cout << "Product to search: ";
	return getInput(productName, len, MAX_PRODUCT_NAME_LENGTH);
}

bool addProductToCartValidation(unsigned int& productID, const int numOfAllProducts)
{
	cout << "Please provide the serial number of wanted product to add to cart: ";
	cin >> productID;

	// Check valid type and valid range of the serial number
	if (cinTypeCheck() && (productID <= Product::uniqueID - 1 && productID >= Product::uniqueID - numOfAllProducts))
	{
		return true;
	}
	else
	{
		cout << "Serial number not found. Please search for an existing product and try again!\n" << endl;
		return false;
	}
}

Product* indexOfCheckoutProductValidation(int& index, Product** cart, int numOfProductsInCart, Product** chosenProducts, int numOfChosenProducts)
{
	bool isValidIndex = false;
	Product* product = nullptr;

	while (!isValidIndex)
	{
		cout << "Chosen product index: ";
		cin >> index;

		if (!cinTypeCheck() || !(1 <= index && index <= numOfProductsInCart))
		{
			if (index == -1)
			{
				return nullptr;
			}
			else
			{
				cout << "Invalid index. Try again!" << endl;
			}
		}
		else
		{
			product = cart[index - 1];
			if (!isProductExists(product->getName(), chosenProducts, numOfChosenProducts))
			{
				isValidIndex = true;
			}
			else
			{
				cout << "You already added this product." << endl;
			}
		}
	}

	return product;
}

bool isSellerExists(User* seller, User** sellers, int numOfSellers)
{
	for (int i = 0; i < numOfSellers; i++)
	{
		if (sellers[i] == seller)
		{
			return true;
		}
	}

	return false;
}

void dateValidation(int& day, int& month, int& year)
{
	cout << "Please enter the day: ";
	cin >> day;
	while (!cinTypeCheck() || !(1 <= day && day <= 31))
	{
		cout << "Invalid day. Try again!" << endl;
		cout << "Please enter the day: ";
		cin >> day;
	}
	
	cout << "Please enter the month: ";
	cin >> month;
	while (!cinTypeCheck() || !(1 <= month && month <= 12))
	{
		cout << "Invalid month. Try again!" << endl;
		cout << "Please enter the month: ";
		cin >> month;
	}

	cout << "Please enter the year: ";
	cin >> year;
	while (!cinTypeCheck() || !(2000 <= year && year <= 2020))
	{
		cout << "Invalid year. Pied Piper Shop only exists since year 2000 and will be closed in the year 2020 due to cash overflow. Try again!" << endl;
		cout << "Please enter the year: ";
		cin >> year;
	}
}