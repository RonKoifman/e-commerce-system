#include "ShopSystem.h"

ShopSystem::ShopSystem(const char* name) // C'tor
	: name(name)
{
	// Initialize data members
	numOfSellers = 0;
	numOfCustomers = 0;
	numOfAllProducts = 0;
	sellers = nullptr;
	customers = nullptr;
	allProducts = nullptr;
}

ShopSystem::~ShopSystem() // D'tor
{
	for (int i = 0; i < numOfSellers; i++)
	{
		delete sellers[i];
	}
	for (int i = 0; i < numOfCustomers; i++)
	{
		delete customers[i];
	}

	delete[] sellers;
	delete[] customers;
	delete[] allProducts; // The products pointers themselves already released at each of their seller d'tor
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
		cout << name << " customers:\n" << endl;
		for (int i = 0; i < numOfCustomers; i++)
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
		cout << name << " sellers:\n" << endl;
		for (int i = 0; i < numOfSellers; i++)
		{
			sellers[i]->show();
			cout << endl;
		}
	}
}

void ShopSystem::showAllProducts() const
{
	if (numOfAllProducts == 0)
	{
		cout << "There are no products in the shop yet.\n" << endl;
	}
	else
	{
		cout << name << " products:\n" << endl;
		for (int i = 0; i < numOfAllProducts; i++)
		{
			cout << i + 1 << "."; allProducts[i]->show();
			cout << endl;
		}
	}
}

bool ShopSystem::showLoginMenu()
{
	int selection;
	char username[MAX_CHARACTERS], password[MAX_CHARACTERS];

	printLoginMenu();
	cin >> selection;
	cout << endl;

	if (!cinTypeCheck())
	{
		cout << "Please choose from one of the following options!\n" << endl;
		return true; // cin failed - wrong input type. Go back to login menu
	}

	switch ((LoginOptions)selection)
	{
	case SignupNewSeller:
	{
		Seller* newSeller = readSellerData();
		addSeller(newSeller);
		cout << "Registration completed successfully!\n" << endl;
		if (!showSellerMenu(*newSeller)) // Repeatedly show seller menu until he asks to exit
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
		if (!showCustomerMenu(*newCustomer)) // Repeatedly show customer menu until he asks to exit
		{
			return false; // Exit from the application
		}
		break;
	}
	case LoginSeller:
	{
		Seller* seller = loginSeller(username, password);
		if (seller) // Seller found
		{
			cout << "Welcome back " << seller->getUsername() << "!\n" << endl;
			if (!showSellerMenu(*seller)) // Repeatedly show seller menu until he asks to exit
			{
				return false; // Exit from the application
			}
		}
		break;
	}
	case LoginCustomer:
	{
		Customer* customer = loginCustomer(username, password);
		if (customer) // Customer found
		{
			cout << "Welcome back " << customer->getUsername() << "!\n" << endl;
			if (!showCustomerMenu(*customer)) // Repeatedly show customer menu until he asks to exit
			{
				return false; // Exit from the application
			}
		}
		break;
	}
	case Exit:
		return false; // Exit from the application
	default: // Invalid option
		cout << "Please choose from one of the following options!\n" << endl;
	}

	return true; // Go back to login menu
}

bool ShopSystem::showSellerMenu(Seller& seller)
{
	int selection, numOfRequestedProducts = 0;
	Product** requestedProducts = nullptr;

	printSellerMenu();
	cin >> selection;
	cout << endl;

	if (!cinTypeCheck()) // cin failed - ask again for valid type
	{
		cout << "Please choose from one of the following options!\n" << endl;
	}
	else // Valid type
	{
		switch ((SellerOptions)selection)
		{
		case AddNewProductToSeller:
		{
			Product* newProduct = readProductData(&seller);
			addProductToProductsArray(newProduct, seller.getProductsByPointer(), seller.getNumOfProducts()); // Add the new product to its seller
			addProductToProductsArray(newProduct, &allProducts, numOfAllProducts); // Add the new product to the general products array
			break;
		}
		case SellerSearchProduct:
		{
			searchProducts(&requestedProducts, numOfRequestedProducts);
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
			return true; // Logout seller
		}
		case SellerExit:
			return false; // Exit from the application
		default:
			cout << "Please choose from one of the following options!\n" << endl;
		}
	}

	return showSellerMenu(seller); // Repeatedly show menu
}

bool ShopSystem::showCustomerMenu(Customer& customer)
{
	int selection, numOfRequestedProducts = 0;
	Product** requestedProducts = nullptr;

	printCustomerMenu();
	cin >> selection;
	cout << endl;

	if (!cinTypeCheck()) // cin failed - ask again for valid type
	{
		cout << "Please choose from one of the following options!\n" << endl;
	}
	else
	{
		switch ((CustomerOptions)selection)
		{
		case CustomerSearchProduct:
		{
			searchProducts(&requestedProducts, numOfRequestedProducts);
			break;
		}
		case AddNewProductToCart:
		{
			// add product to cart
			break;
		}
		case Checkout:
		{
			// checkout 
			// inside checkout - definition of place order...
			break;
		}
		case WriteFeedback:
		{
			// write feedback
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
			return true; // Logout customer
		}
		case CustomerExit:
			return false; // Exit from the application
		default:
			cout << "Please choose from one of the following options!\n" << endl;
		}
	}

	return showCustomerMenu(customer); // Repeatedly show menu
}

Seller* ShopSystem::readSellerData()
{
	char username[MAX_CHARACTERS], password[MAX_CHARACTERS];
	char country[MAX_CHARACTERS], city[MAX_CHARACTERS], street[MAX_CHARACTERS];
	int buildingNumber;

	cout << "Thanks for joining in, new seller! You are on the way of getting rich!" << endl;
	cout << "We are using an universal and decentralized authentication." << endl;
	cout << "Please fill in the following fields:\n" << endl;

	usernameValidation(username, *this);
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
	int i;

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
	int buildingNumber;

	cout << "Thanks for joining in, new customer! Let's get you a good deal!" << endl;
	cout << "We are using an universal and decentralized authentication." << endl;
	cout << "Please fill in the following fields:\n" << endl;

	usernameValidation(username, *this);
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
	int i;

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
	int category;

	cout << "Please fill in the following fields.\n" << endl;
	productNameValidation(productName);
	priceValidation(price);
	categoryValidation(category);
	
	cout << endl << "Product added successfully!\n" << endl;
	return new Product(productName, price, category, seller);
}

Seller* ShopSystem::loginSeller(char* username, char* password)
{
	bool isValidUsername, isValidPassword;
	int len = 0;

	cout << "Please Login with your credentials.\n" << endl;
	cleanBuffer();
	cout << "Username: ";
	isValidUsername = getInput(username, len);
	cout << "Password: ";
	isValidPassword = getInput(password, len);

	if (!(isValidUsername && isValidPassword)) // One of the inputs not valid
	{
		cout << "Wrong details. Login failed!\n" << endl;
		return nullptr; // Invalid input - login failed
	}

	// Check if the entered username and password match to some seller
	for (int i = 0; i < numOfSellers; i++)
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
	bool isValidUsername, isValidPassword;
	int len = 0;

	cout << "Please Login with your credentials.\n" << endl;
	cleanBuffer();
	cout << "Username: ";
	isValidUsername = getInput(username, len);
	cout << "Password: ";
	isValidPassword = getInput(password, len);

	if (!(isValidUsername && isValidPassword)) // One of the inputs not valid
	{
		cout << "Wrong details. Login failed!\n" << endl;
		return nullptr; // Customer not found
	}

	// Check if the entered username and password match to some customer
	for (int i = 0; i < numOfCustomers; i++)
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

Seller** ShopSystem::getSellers() const
{
	return sellers;
}

Customer** ShopSystem::getCustomers() const
{
	return customers;
}

int ShopSystem::getNumOfSellers() const
{
	return numOfSellers;
}

int ShopSystem::getNumOfCustomers() const
{
	return numOfCustomers;
}

Product** ShopSystem::getAllProducts() const
{
	return allProducts;
}

int ShopSystem::getNumOfAllProducts() const
{
	return numOfAllProducts;
}

void ShopSystem::addProductToProductsArray(Product* newProduct, Product*** products, int& numOfProducts)
{
	int i;

	Product** temp = new Product*[numOfProducts + 1]; // Create bigger array to add the new product

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfProducts; i++)
	{
		temp[i] = (*products)[i];
	}
	temp[i] = newProduct; // Add the new product
	numOfProducts++;

	delete[] *products; // Free the current array
	*products = temp; // Update products array to temp
}

void ShopSystem::searchProducts(Product*** requestedProducts, int& numOfRequestedProducts)
{
	char nameOfProduct[MAX_CHARACTERS];
	int selection, len = 0;

	searchProductSelectionValidation(selection); // Selection validation

	if ((SearchProductOptions)selection == AllProducts)
	{
		showAllProducts(); // Show all the products in the shop
	}
	else // SpecificProductName
	{
		cleanBuffer();
		do // Get a name of a product to search
		{
			cout << "Product to search: ";
		} while (!getInput(nameOfProduct, len));

		for (int i = 0; i < numOfAllProducts; i++)
		{
			if (strcmp(nameOfProduct, allProducts[i]->getName()) == 0) // Match
			{
				addProductToProductsArray(allProducts[i], requestedProducts, numOfRequestedProducts);
			}
		}

		showRequestedProducts(*requestedProducts, numOfRequestedProducts);
		delete[] *requestedProducts; // Free the requested products array
	}
}

void ShopSystem::showRequestedProducts(Product** requestedProducts, int numOfRequestedProducts) const
{
	cout << numOfRequestedProducts << " products found.\n" << endl;

	for (int i = 0; i < numOfRequestedProducts; i++) // Print matching products
	{
		cout << i + 1 << "."; requestedProducts[i]->show();
		cout << endl;
	}
}