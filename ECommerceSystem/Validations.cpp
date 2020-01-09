#include "ShopSystem.h"
#include "Validations.h"

void Validations::cleanBuffer()
{
	char ch;

	do
	{
		ch = getchar();
	} while (ch != EOF && ch != '\n');
}

bool Validations::getInput(char* str, const int maxLen)
{
	int len = 0;
	char ch = ' ';

	// Get input from buffer
	while (len < maxLen - 1 && ch != '\n')
	{
		ch = getchar();
		if (ch != '\n')
		{
			str[len++] = ch;
		}
	}
	str[len] = '\0';

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

bool Validations::cinTypeCheck()
{
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false; // The input does not match the expected type
	}

	return true; // Valid type
}

bool Validations::checkLettersAndDigits(const char* str)
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

bool Validations::checkLettersDigitsAndSpace(const char* str)
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

bool Validations::checkSpecialCharacters(const char* str)
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

bool Validations::checkLettersAndSpace(const char* str)
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

void Validations::usernameValidation(char* username, User** users, int numOfUsers)
{
	bool isValid = false;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Username (maximum 20 characters, letters and digits only): ";

		if (getInput(username, MAX_CHARACTERS))
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

void Validations::passwordValidation(char* password)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Password (between 6-20 characters): ";

		if (getInput(password, MAX_CHARACTERS))
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

void Validations::countryValidation(char* country)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Country (maximum 20 characters, letters and space only): ";

		if (getInput(country, MAX_CHARACTERS))
		{
			if (checkLettersAndSpace(country))
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

void Validations::cityValidation(char* city)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "City (maximum 20 characters, letters and space only): ";

		if (getInput(city, MAX_CHARACTERS))
		{
			if (checkLettersAndSpace(city))
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

void Validations::streetValidation(char* street)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Street (maximum 20 characters, letters and space only): ";

		if (getInput(street, MAX_CHARACTERS))
		{
			if (checkLettersAndSpace(street))
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

void Validations::buildingNumberValidation(int& buildingNumber)
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

bool Validations::checkUniqueUsername(const char* username, User** users, int numOfUsers)
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

void Validations::productNameValidation(char* productName, User* user)
{
	Seller* seller = dynamic_cast<Seller*>(user); if (!seller) return;
	bool isValid = false;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Product name (maximum 30 characters, letters digits and space only): ";

		if (getInput(productName, MAX_PRODUCT_NAME_LENGTH))
		{
			if (checkLettersDigitsAndSpace(productName))
			{
				if (!isProductNameExists(productName, seller->getProducts(), seller->getNumOfProducts()))
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

bool Validations::isProductExists(int productSerialNumber, Product** products, int numOfProducts)
{
	for (int i = 0; i < numOfProducts; i++)
	{
		if (productSerialNumber == products[i]->getSerialNumber())
		{
			return true; // Product already exists
		}
	}

	return false;
}

bool Validations::isProductNameExists(const char* productName, Product** products, int numOfProducts)
{
	for (int i = 0; i < numOfProducts; i++)
	{
		if (strcmp(productName, products[i]->getName()) == 0)
		{
			return true; // Product name already exists
		}
	}

	return false;
}

bool Validations::isProductBelongsToUser(User* user, int productSerialNumber)
{
	SellerCustomer* sc = dynamic_cast<SellerCustomer*>(user); if (!sc) return false;
	Product** userProducts = sc->getProducts();
	int numOfProducts = sc->getNumOfProducts();

	for (int i = 0; i < numOfProducts; i++)
	{
		if (userProducts[i]->getSerialNumber() == productSerialNumber)
		{
			return true; // Product belongs to the user
		}
	}

	return false;
}

void Validations::priceValidation(float& price)
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

void Validations::categoryValidation(int& category)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Category (choose from the following: 1-Clothing, 2-Kids, 3-Electricity, 4-Office): ";
		cin >> category;

		if (cinTypeCheck() && (1 <= category && category <= MAX_CATEGORIES))
		{
			isValid = true;
		}
		else
		{
			cout << "Invalid category. Try again!" << endl;
		}
	}
}

bool Validations::searchProductSelectionValidation(int& selection)
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

bool Validations::productSerialNumberValidation(unsigned int& productID, const int numOfAllProducts)
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

Product* Validations::indexOfCheckoutProductValidation(int& index, Product** cart, int numOfProductsInCart, Product** chosenProducts, int numOfChosenProducts)
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
			if (!isProductExists(product->getSerialNumber(), chosenProducts, numOfChosenProducts))
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

bool Validations::isSellerExists(const User* seller, User** sellers, int numOfSellers)
{
	for (int i = 0; i < numOfSellers; i++)
	{
		if (sellers[i] == seller)
		{
			return true; // Seller already exists
		}
	}

	return false;
}

void Validations::dateValidation(int& day, int& month, int& year)
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
	while (!cinTypeCheck() || year != CURRENT_YEAR)
	{
		cout << "Invalid year. Try again!" << endl;
		cout << "Please enter the year: ";
		cin >> year;
	}
}

bool Validations::areValidUsers(User** users, int numOfUsers, int& indexUser1, int& indexUser2)
{
	char username1[MAX_CHARACTERS], username2[MAX_CHARACTERS];
	int usersFound = 0;
	bool isUsername1Valid, isUsername2Valid;

	cleanBuffer();
	cout << "Please enter the first username of a customer or a seller-customer for comparison:" << endl;
	isUsername1Valid = getInput(username1, MAX_CHARACTERS);
	cout << "Please enter the second username of a customer or a seller-customer for comparison:" << endl;
	isUsername2Valid = getInput(username2, MAX_CHARACTERS);
	cout << endl;

	// Check for valid input length
	if (!(isUsername1Valid && isUsername2Valid))
	{
		return false;
	}

	for (int i = 0; i < numOfUsers && usersFound < 2; i++)
	{
		if (strcmp(username1, users[i]->getUsername()) == 0)
		{
			indexUser1 = i;
			usersFound++;
		}
		if (strcmp(username2, users[i]->getUsername()) == 0)
		{
			indexUser2 = i;
			usersFound++;
		}
	}

	// Check that both different users are found and their type is either customer or seller-customer
	return (usersFound == 2 && indexUser1 != indexUser2 && dynamic_cast<Customer*>(users[indexUser1]) && dynamic_cast<Customer*>(users[indexUser2]));
}