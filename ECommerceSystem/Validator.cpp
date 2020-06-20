#include "ShopSystem.h"
#include "Validator.h"

void Validator::cleanBuffer()
{
	char ch;

	do
	{
		ch = getchar();
	} while (ch != EOF && ch != '\n');
}

bool Validator::getInput(string& str, const int maxLen)
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

bool Validator::cinTypeCheck()
{
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false; // The input does not match the expected type
	}

	return true; // Valid type
}

bool Validator::checkLettersAndDigits(const string& str)
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

bool Validator::checkLettersDigitsAndSpace(const string& str)
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

bool Validator::checkSpecialCharacters(const string& str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] < '!') || (str[i] > '~')) // All characters from '!' to '~'y' are allowed (excluding whitespaces and few extra chars)
		{
			cout << "Invalid character found: '" << str[i] << "'" << ". Try again!" << endl;
			return false;
		}

		i++;
	}

	return true;
}

bool Validator::checkLettersAndSpace(const string& str)
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

void Validator::usernameValidation(string& username, const vector<User*>& users)
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

void Validator::passwordValidation(string& password)
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

void Validator::countryValidation(string& country)
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

void Validator::cityValidation(string& city)
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

void Validator::streetValidation(string& street)
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

void Validator::buildingNumberValidation(int& buildingNumber)
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

bool Validator::checkUniqueUsername(const string& username, const vector<User*>& users)
{
	unsigned int numOfUsers = users.size();

	for (unsigned int i = 0; i < numOfUsers; i++) // Search through all users
	{
		if (users[i]->getUsername().compare(username) == 0) // Username taken
		{
			cout << "Username taken! Please choose a different username." << endl;
			return false;
		}
	}

	return true;
}

void Validator::productNameValidation(string& productName, User& user)
{
	bool isValid = false;
	Seller* seller = dynamic_cast<Seller*>(&user);
	if (seller == nullptr)
	{
		return;
	}

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

bool Validator::isProductExists(int productSerialNumber, const vector<Product*>& products)
{
	unsigned int numOfProducts = products.size();

	for (unsigned int i = 0; i < numOfProducts; i++)
	{
		if (productSerialNumber == products[i]->getSerialNumber())
		{
			return true; // Product already exists
		}
	}

	return false;
}

bool Validator::isProductNameExists(const string& productName, const vector<Product*>& products)
{
	unsigned int numOfProducts = products.size();

	for (unsigned int i = 0; i < numOfProducts; i++)
	{
		if (products[i]->getName().compare(productName) == 0)
		{
			return true; // Product name already exists
		}
	}

	return false;
}

bool Validator::isProductBelongsToUser(User& user, int productSerialNumber)
{
	SellerCustomer* sc = dynamic_cast<SellerCustomer*>(&user);
	if (sc == nullptr)
	{
		return false;
	}

	return isProductExists(productSerialNumber, sc->getProducts());
}

void Validator::priceValidation(float& price)
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

void Validator::categoryValidation(int& category)
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

bool Validator::searchProductSelectionValidation(int& selection)
{
	cout << "Press 1 to show all products in the shop." << endl;
	cout << "Press 2 to search a product by name." << endl;
	cout << "Your selection: ";

	cin >> selection;
	cout << endl;

	if (cinTypeCheck() && (selection == ShopSystem::SearchProductOptions::AllProducts || selection == ShopSystem::SearchProductOptions::SpecificProductName))
	{
		return true;
	}
	else
	{
		cout << "Invalid selection!\n" << endl;
		return false;
	}
}

bool Validator::productSerialNumberValidation(unsigned int& productID, const int numOfAllProducts)
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

Product* Validator::indexOfCheckoutProductValidation(unsigned int& index, const vector<Product*>& cart, const vector<Product*>& chosenProducts)
{
	bool isValidIndex = false;
	Product* product = nullptr;
	unsigned int numOfProductsInCart = cart.size();

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

bool Validator::isSellerExists(const User& seller, const vector<User*>& sellers)
{
	unsigned int numOfSellers = sellers.size();

	for (unsigned int i = 0; i < numOfSellers; i++)
	{
		if (sellers[i]->getUsername().compare(seller.getUsername()) == 0)
		{
			return true; // Seller already exists
		}
	}

	return false;
}

void Validator::dateValidation(int& day, int& month, int& year)
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

bool Validator::areValidUsers(const vector<User*>& users, int& indexUser1, int& indexUser2)
{
	string username1, username2;
	int usersFound = 0;
	bool isUsername1Valid, isUsername2Valid;
	unsigned int numOfUsers = users.size();

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

	for (unsigned int i = 0; i < numOfUsers && usersFound < 2; i++)
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