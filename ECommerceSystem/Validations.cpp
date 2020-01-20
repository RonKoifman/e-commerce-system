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

bool Validations::getInput(string& str, const int maxLen)
{
	getline(cin, str);
	int len = str.length();

	// Invalid string length or an empty string
	if (len > maxLen || len == 0)
	{
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

bool Validations::checkLettersAndDigits(const string& str)
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

bool Validations::checkLettersDigitsAndSpace(const string& str)
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

bool Validations::checkSpecialCharacters(const string& str)
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

bool Validations::checkLettersAndSpace(const string& str)
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

void Validations::usernameValidation(string& username, const vector<User*>& users)
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
				isValid = checkUniqueUsername(username, users);
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

void Validations::passwordValidation(string& password)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Password (between 6-20 characters): ";

		if (getInput(password, MAX_CHARACTERS))
		{
			if (password.length() >= MIN_CHARACTERS_PASSWORD) 
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

void Validations::countryValidation(string& country)
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

void Validations::cityValidation(string& city)
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

void Validations::streetValidation(string& street)
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

bool Validations::checkUniqueUsername(const string& username, const vector<User*>& users)
{
	for (unsigned int i = 0; i < users.size(); i++) // Search through all users
	{
		if (users[i]->getUsername().compare(username) == 0) // Username taken
		{
			cout << "Username taken! Please choose a different username." << endl;
			return false;
		}
	}

	return true;
}

void Validations::productNameValidation(string& productName, User& user)
{
	Seller* seller = dynamic_cast<Seller*>(&user); if (!seller) return;
	bool isValid = false;

	cleanBuffer();
	while (!isValid)
	{
		cout << "Product name (maximum 30 characters, letters digits and space only): ";

		if (getInput(productName, MAX_PRODUCT_NAME_LENGTH))
		{
			if (checkLettersDigitsAndSpace(productName))
			{
				if (!isProductNameExists(productName, seller->getProducts()))
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

bool Validations::isProductExists(int productSerialNumber, const vector<Product*>& products)
{
	for (unsigned int i = 0; i < products.size(); i++)
	{
		if (productSerialNumber == products[i]->getSerialNumber())
		{
			return true; // Product already exists
		}
	}

	return false;
}

bool Validations::isProductNameExists(const string& productName, const vector<Product*>& products)
{
	for (unsigned int i = 0; i < products.size(); i++)
	{
		if (products[i]->getName().compare(productName) == 0)
		{
			return true; // Product name already exists
		}
	}

	return false;
}

bool Validations::isProductBelongsToUser(User& user, int productSerialNumber)
{
	SellerCustomer* sc = dynamic_cast<SellerCustomer*>(&user); if (!sc) return false;

	return isProductExists(productSerialNumber, sc->getProducts());
}

void Validations::priceValidation(float& price)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << "Price: ";
		cin >> price;

		if (cinTypeCheck() && price > 0)
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

Product* Validations::indexOfCheckoutProductValidation(unsigned int& index, const vector<Product*>& cart, const vector<Product*>& chosenProducts)
{
	bool isValidIndex = false;
	Product* product = nullptr;

	while (!isValidIndex)
	{
		cout << "Chosen product index: ";
		cin >> index;

		if (!cinTypeCheck() || !(1 <= index && index <= cart.size()))
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
			if (!isProductExists(product->getSerialNumber(), chosenProducts))
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

bool Validations::isSellerExists(const User& seller, const vector<User*>& sellers)
{
	for (unsigned int i = 0; i < sellers.size(); i++)
	{
		if (sellers[i]->getUsername().compare(seller.getUsername()) == 0)
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
		cout << "Invalid year. Enter the current year and try again!" << endl;
		cout << "Please enter the year: ";
		cin >> year;
	}
}

bool Validations::areValidUsers(const vector<User*>& users, int& indexUser1, int& indexUser2)
{
	string username1, username2;
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

	for (unsigned int i = 0; i < users.size() && usersFound < 2; i++)
	{
		if (users[i]->getUsername().compare(username1) == 0)
		{
			indexUser1 = i;
			usersFound++;
		}
		if (users[i]->getUsername().compare(username2) == 0)
		{
			indexUser2 = i;
			usersFound++;
		}
	}

	// Check that both different users are found and their type is either customer or seller-customer
	return (usersFound == 2 && indexUser1 != indexUser2 && dynamic_cast<Customer*>(users[indexUser1]) && dynamic_cast<Customer*>(users[indexUser2]));
}