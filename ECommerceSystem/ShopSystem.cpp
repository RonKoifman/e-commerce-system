#include "ShopSystem.h"

ShopSystem::ShopSystem(const char* name) // C'tor
	: name(name)
{
	// Initialize data members
	numOfSellers = 0;
	numOfCustomers = 0;
	sellers = nullptr;
	customers = nullptr;
}

ShopSystem::~ShopSystem() // D'tor
{
	for (unsigned int i = 0; i < numOfSellers; i++)
	{
		delete sellers[i];
	}
	for (unsigned int i = 0; i < numOfCustomers; i++)
	{
		delete customers[i];
	}

	delete[] sellers;
	delete[] customers;
}

const char* ShopSystem::getName() const
{
	return name;
}

void ShopSystem::showCustomers() const
{
	if (numOfCustomers == 0)
	{
		cout << "There are no registered customers yet.\n" << endl;
	}
	else
	{
		cout << name << " customers:" << endl;
		for (unsigned int i = 0; i < numOfCustomers; i++)
		{
			customers[i]->show();
			cout << endl;
		}
	}
}

void ShopSystem::showSellers() const
{
	if (numOfSellers == 0)
	{
		cout << "There are no registered sellers yet.\n" << endl;
	}
	else
	{
		cout << name << " sellers:" << endl;
		for (unsigned int i = 0; i < numOfSellers; i++)
		{
			sellers[i]->show();
			cout << endl;
		}
	}
}

bool ShopSystem::showLoginMenu()
{
	int selection;

	cout << "Press 1 to create a new seller account." << endl;
	cout << "Press 2 to create a new customer account." << endl;
	cout << "Press 3 to login as a seller." << endl;
	cout << "Press 4 to login as a customer." << endl;
	cout << "Press 5 to exit." << endl;

	cout << "Your selection: ";
	cin >> selection;
	cout << endl;
	if (!cinTypeCheck())
	{
		cout << "Please choose from one of the following options!" << endl;
		return true; // cin failed - ask again for valid type
	}

	switch ((LoginOptions)selection)
	{
	case SignupNewSeller:
	{
		Seller* newSeller = readSellerData();
		addSeller(newSeller);
		cout << "Registration completed successfully!\n" << endl;
		if (!showSellerMenu(*newSeller))
		{
			return false; // Exit from the application
		}
		break;
	}
	case SignupNewCustomer:
	{
		Customer* newCustomer = readCustomerData();
		addCustomer(newCustomer);
		cout << "Registration completed successfully!\n" << endl;
		if (!showCustomerMenu(*newCustomer))
		{
			return false; // Exit from the application
		}
		break;
	}
	case LoginSeller:
	{
		char username[MAX_CHARACTERS], password[MAX_CHARACTERS];
		usernameValidation(username);
		passwordValidation(password);
		Seller* seller = loginSeller(username, password);
		if (seller) // Seller found
		{
			if (!showSellerMenu(*seller))
			{
				return false; // Exit from the application
			}
		}
		break;
	}
	case LoginCustomer:
	{
		char username[MAX_CHARACTERS], password[MAX_CHARACTERS];
		usernameValidation(username);
		passwordValidation(password);
		Customer* customer = loginCustomer(username, password);
		if (customer) // Customer found
		{
			if (!showCustomerMenu(*customer))
			{
				return false; // Exit from the application
			}
		}
		break;
	}
	case Exit:
	{
		return false; // Exit from the application
	}
	default:
		cout << "Please choose from one of the following options!" << endl;
	}

	return true;
}

bool ShopSystem::showSellerMenu(Seller& seller)
{
	char selection;

	cout << "Press 1 to add a new product to your account." << endl;
	cout << "Press 2 to search for a product." << endl;
	cout << "Press 3 to view all the customers in the shop." << endl;
	cout << "Press 4 to view all the sellers in the shop." << endl;
	cout << "Press 5 to logout." << endl;
	cout << "Press 6 to exit." << endl;

	cout << "Your selection: ";
	cin >> selection;
	cout << endl;

	switch ((SellerOptions)selection)
	{
	case AddNewProductToSeller: 
	{
		Product* newProduct = readProductData(&seller);
		seller.addProduct(newProduct);
		break;
	}
	case SellerSearchProduct: 
	{
	// TODO: look for a product
		break;
	}
	case SellerViewCustomers: 
	{
		showCustomers();
		break;
	}
	case SellerViewSellers:
	{
		showSellers();
		break;
	}
	case SellerLogOut: 
	{
		cout << "Bye bye " << seller.getUsername() << "... We hope to see you again soon!\n" << endl;
		return true;
	}
	case SellerExit:
		return false; // Exit from the application
	default: 
		cout << "Please choose from one of the following options!" << endl;
	}

	return showSellerMenu(seller);
}

bool ShopSystem::showCustomerMenu(Customer& customer)
{
	char selection;

	cout << "Press 1 to search for a product." << endl;
	cout << "Press 2 to add product to your cart." << endl;
	cout << "Press 3 to checkout." << endl;
	cout << "Press 4 to write a feedback to a seller." << endl;
	cout << "Press 5 to view all the customers in the shop." << endl;
	cout << "Press 6 to view all the sellers in the shop." << endl;
	cout << "Press 7 to logout." << endl;
	cout << "Press 8 to exit." << endl;

	cout << "Your selection: ";
	cin >> selection;
	cout << endl;

	switch ((CustomerOptions)selection)
	{
	case CustomerSearchProduct:
	{
		// look for new product
		break;
	}
	case AddNewProductToCart:
	{
		// add product to cart
		break; 
	}
	case Checkout: 
	{
		// inside checkout - definition of place order...
		// checkout 
		break;
	}
	case WriteFeedback:
	{
		// write Feedback
		break;
	}
	case CustomerViewCustomers:
	{
		showCustomers();
		break;
	}
	case CustomerViewSellers:
	{
		showSellers();
		break;
	}
	case CustomerLogOut:
	{
		cout << "Bye bye " << customer.getUsername() << "... We hope to see you again soon!\n" << endl;
		return true;
	}
	case CustomerExit: 
		return false; // Exit from the application
	default:
		cout << "Please choose from one of the following options!" << endl;
	}

	return showCustomerMenu(customer);
}

Seller* ShopSystem::readSellerData()
{
	char username[MAX_CHARACTERS], password[MAX_CHARACTERS];
	char country[MAX_CHARACTERS], city[MAX_CHARACTERS], street[MAX_CHARACTERS];
	unsigned int buildingNumber;

	cout << "Thanks for joining in, new seller! You are on the way of getting rich!" << endl;
	cout << "We are using an universal and decentralized authentication." << endl;
	cout << "Please fill in the following fields:" << endl;

	// Validate unique username, characters legnth and etc...
	usernameValidation(username);
	passwordValidation(password);
	countryValidation(country);
	cityValidation(city);
	streetValidation(street);
	buildingNumberValidation(buildingNumber);
	cout << endl;

	Address address(country, city, street, buildingNumber);
	return new Seller(username, password, address);
}

void ShopSystem::addSeller(Seller* seller)
{
	unsigned int i;

	Seller** temp = new Seller*[numOfSellers + 1]; // Create bigger array to add the new seller

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfSellers; i++)
	{
		temp[i] = sellers[i];
	}
	temp[i] = seller; // Add the new seller
	numOfSellers++;

	delete[] sellers; // Free the current array
	sellers = temp; // Update sellers array to temp
}

Customer* ShopSystem::readCustomerData()
{
	char username[MAX_CHARACTERS], password[MAX_CHARACTERS];
	char country[MAX_CHARACTERS], city[MAX_CHARACTERS], street[MAX_CHARACTERS];
	unsigned int buildingNumber;

	cout << "Thanks for joining in, new customer! Let's get you a good deal!" << endl;
	cout << "We are using an universal and decentralized authentication." << endl;
	cout << "Please fill in the following fields:" << endl;

	// Validate unique username, characters legnth and etc...
	usernameValidation(username);
	passwordValidation(password);
	countryValidation(country);
	cityValidation(city);
	streetValidation(street);
	buildingNumberValidation(buildingNumber);
	cout << endl;

	Address address(country, city, street, buildingNumber);
	return new Customer(username, password, address);
}

void ShopSystem::addCustomer(Customer* customer)
{
	unsigned int i;

	Customer** temp = new Customer*[numOfCustomers + 1]; // Create bigger array to add the new customer

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfCustomers; i++)
	{
		temp[i] = customers[i];
	}
	temp[i] = customer; // Add the new customer
	numOfCustomers++;

	delete[] customers; // Free the current array
	customers = temp; // Update customers array to temp
}

Product* ShopSystem::readProductData(Seller* seller)
{
	char productName[MAX_CHARACTERS];
	float price;
	char category;

	// Validate characters legnth and etc...
	cout << "Please fill in the following fields." << endl;
	cout << "Product name: ";
	cleanBuffer();
	cin.getline(productName, MAX_CHARACTERS);
	cout << "Price: ";
	cin >> price;
	cout << "Category (choose from the following: 1-Clothing, 2-Kids, 3-Electricity, 4-Office): ";  //TODO make validation
	cleanBuffer();
	cin.get(category);
	cout << endl;

	return new Product(productName, price, category, seller);
}

Seller* ShopSystem::loginSeller(char* username, char* password)
{
	for (unsigned int i = 0; i < numOfSellers; i++)
	{
		if (strcmp(sellers[i]->getUsername(), username) == 0)
		{
			if (strcmp(sellers[i]->getPassword(), password) == 0)
			{
				cout << "Logged in successfully!\n" << endl;
				return sellers[i]; // Seller found
			}
		}
	}

	cout << "Wrong details. Login failed!\n" << endl;
	return nullptr; // Seller not found - login failed
}

Customer* ShopSystem::loginCustomer(char* username, char* password)
{
	for (unsigned int i = 0; i < numOfCustomers; i++)
	{
		if (strcmp(customers[i]->getUsername(), username) == 0)
		{
			if (strcmp(customers[i]->getPassword(), password) == 0)
			{
				cout << "Logged in successfully!\n" << endl;
				return customers[i]; // Customer found
			}
		}
	}

	cout << "Wrong details. Login failed!\n" << endl;
	return nullptr; // Customer not found - login failed
}