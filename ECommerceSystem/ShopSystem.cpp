#include "ShopSystem.h"

ShopSystem::ShopSystem() // C'tor
{
	loadUsers("database.dat"); // Load users data if exists
}

ShopSystem::~ShopSystem() // D'tor
{
	unsigned int numOfUsers = users.size();

	saveUsers("database.dat"); // Save users data

	for (unsigned int i = 0; i < numOfUsers; i++)
	{
		delete users[i];
	}
}

void ShopSystem::showSelectedUsers(const string& selectedUsersType) const
{
	bool areFound = false;
	unsigned int numOfUsers = users.size();

	for (unsigned int i = 0; i < numOfUsers; i++)
	{
		if (selectedUsersType.compare(typeid(*users[i]).name() + 6) == 0) // Match
		{
			if (!areFound)
			{
				cout << "Selected users:\n" << endl;
				areFound = true;
			}
			cout << *users[i] << endl;
		}
	}

	if (!areFound) // No users from the selected type were found
	{
		cout << "There are no registered users from this type yet.\n" << endl;
	}
}

const vector<User*>& ShopSystem::getUsers() const
{
	return users;
}

const vector<Product*>& ShopSystem::getAllProducts() const
{
	return allProducts;
}

void ShopSystem::showAllProducts() const
{
	unsigned int numOfAllProducts = allProducts.size();

	if (numOfAllProducts == 0)
	{
		cout << "There are no products in the shop yet.\n" << endl;
	}
	else
	{
		cout << "Shop's products:\n" << endl;
		for (unsigned int i = 0; i < numOfAllProducts; i++)
		{
			cout << i + 1 << "." << *allProducts[i] << endl;
			cout << endl;
		}
	}
}

void ShopSystem::runProgram()
{
	bool toContinue = true;

	cout << "Welcome to the shop!\n" << endl;
	while (toContinue)
	{
		toContinue = mainMenu();
	}

	cout << "Thanks for visiting our shop! See you next time!" << endl;
}

bool ShopSystem::mainMenu()
{
	int selection;

	Menu::printMainMenu();
	cin >> selection;
	cout << endl;

	if (!Validations::cinTypeCheck())
	{
		cout << "Please choose from one of the following options!\n" << endl;
		return true; // cin failed - wrong input type. Go back to login menu
	}

	switch ((ShopSystem::LoginOptions)selection)
	{
	case SignupNewSeller:
	{
		User& newSeller = readUserData(UserAnalyzer::UserType::TypeSeller);
		*this += newSeller; // Add new seller to users array
		if (!sellerMenu(newSeller)) // Repeatedly show seller menu until he asks to exit
		{
			return false; // Exit from the application
		}
		break;
	}
	case SignupNewCustomer:
	{
		User& newCustomer = readUserData(UserAnalyzer::UserType::TypeCustomer);
		*this += newCustomer; // Add new customer to users array
		if (!customerMenu(newCustomer)) // Repeatedly show customer menu until he asks to exit
		{
			return false; // Exit from the application
		}
		break;
	}
	case SignupNewSC:
	{
		User& newSC = readUserData(UserAnalyzer::UserType::TypeSellerCustomer);
		*this += newSC; // Add new seller-customer to users array
		if (!sellerCustomerMenu(newSC)) // Repeatedly show seller-customer menu until he asks to exit
		{
			return false; // Exit from the application
		}
		break;
	}
	case Login:
	{
		User* user = loginUser();
		if (user) // User found
		{
			if (typeid(*user) == typeid(Seller)) // Seller
			{
				if (!sellerMenu(*user)) // Repeatedly show seller menu until he asks to exit
				{
					return false; // Exit from the application
				}
			}
			else if (typeid(*user) == typeid(Customer)) // Customer
			{
				if (!customerMenu(*user)) // Repeatedly show customer menu until he asks to exit
				{
					return false; // Exit from the application
				}
			}
			else // Seller-Customer
			{
				if (!sellerCustomerMenu(*user)) // Repeatedly show seller-customer menu until he asks to exit
				{
					return false; // Exit from the application
				}
			}
		}
		break;
	}
	case ViewCustomers:
	{
		showSelectedUsers("Customer");
		break;
	}
	case ViewSellers:
	{
		showSelectedUsers("Seller");
		break;
	}
	case ViewSC:
	{
		showSelectedUsers("SellerCustomer");
		break;
	}
	case CompareCarts:
	{
		compareUsersCartsAmount();
		break;
	}
	case Exit:
		return false; // Exit from the application
	default: // Invalid option
		cout << "Please choose from one of the following options!\n" << endl;
	}

	return true; // Go back to login menu
}

bool ShopSystem::sellerMenu(User& user)
{
	Seller* seller = dynamic_cast<Seller*>(&user); if (!seller) return false;
	int selection;

	Menu::printSellerMenu();
	cin >> selection;
	cout << endl;

	if (!Validations::cinTypeCheck()) // cin failed - ask again for valid type
	{
		cout << "Please choose from one of the following options!\n" << endl;
	}
	else // Valid type
	{
		switch ((ShopSystem::SellerOptions)selection)
		{
		case AddNewProduct:
		{
			Product& newProduct = readProductData(*seller);
			seller->addProduct(newProduct); // Add the new product to its seller
			this->addProductToStock(newProduct); // Add the new product to the general products array
			break;
		}
		case SellerSearchProduct:
		{
			searchProducts();
			break;
		}
		case ViewProducts:
		{
			seller->showProducts();
			cout << endl;
			break;
		}
		case ViewFeedbacks:
		{
			seller->showFeedbacks();
			cout << endl;
			break;
		}
		case SellerPreviousMenu:
			return true; // Go back to previous menu
		case SellerExit:
			return false; // Exit from the application
		default:
			cout << "Please choose from one of the following options!\n" << endl;
		}
	}

	return sellerMenu(*seller); // Repeatedly show menu
}

bool ShopSystem::customerMenu(User& user)
{
	Customer* customer = dynamic_cast<Customer*>(&user); if (!customer) return false;
	int selection;

	Menu::printCustomerMenu();
	cin >> selection;
	cout << endl;

	if (!Validations::cinTypeCheck()) // cin failed - ask again for valid type
	{
		cout << "Please choose from one of the following options!\n" << endl;
	}
	else
	{
		switch ((ShopSystem::CustomerOptions)selection)
		{
		case CustomerSearchProduct:
		{
			searchProducts();
			break;
		}
		case AddProductToCart:
		{
			addProductToUserCart(*customer);
			break;
		}
		case ViewCart:
		{
			customer->showCart();
			break;
		}
		case CheckoutAndPlaceOrder:
		{
			checkout(*customer);
			break;
		}
		case WriteFeedback:
		{
			writeFeedback(*customer);
			break;
		}
		case CustomerPreviousMenu:
			return true; // Go back to previous menu
		case CustomerExit:
			return false; // Exit from the application
		default:
			cout << "Please choose from one of the following options!\n" << endl;
		}
	}

	return customerMenu(*customer); // Repeatedly show menu
}

bool ShopSystem::sellerCustomerMenu(User& user)
{
	SellerCustomer* sc = dynamic_cast<SellerCustomer*>(&user); if (!sc) return false;
	int selection;

	Menu::printSellerCustomerMenu();
	cin >> selection;
	cout << endl;

	if (!Validations::cinTypeCheck()) // cin failed - ask again for valid type
	{
		cout << "Please choose from one of the following options!\n" << endl;
	}
	else
	{
		switch ((ShopSystem::SellerCustomerOptions)selection)
		{
		case ViewCustomerMenu:
		{
			if (!customerMenu(*sc)) // Repeatedly show customer menu until he asks to exit
			{
				return false; // Exit from the application
			}
			break;
		}
		case ViewSellerMenu:
		{
			if (!sellerMenu(*sc)) // Repeatedly show seller menu until he asks to exit
			{
				return false;
			}
			break;
		}
		case SCPreviousMenu:
			return true; // Go back to previous menu
		case SCExit:
			return false; // Exit from the application
		default:
			cout << "Please choose from one of the following options!\n" << endl;
		}
	}

	return sellerCustomerMenu(*sc); // Repeatedly show menu
}

const ShopSystem& ShopSystem::operator+=(User& user)
{
	users.push_back(&user);
	return *this;
}

void ShopSystem::addProductToStock(Product& newProduct)
{
	allProducts.push_back(&newProduct);
}

User* ShopSystem::loginUser() const
{
	string username, password;
	bool isValidUsername, isValidPassword;
	unsigned int numOfUsers = users.size();

	cout << "Please login with your credentials.\n" << endl;
	Validations::cleanBuffer();
	cout << "Username: ";
	isValidUsername = Validations::getInput(username, MAX_CHARACTERS);
	cout << "Password: ";
	isValidPassword = Validations::getInput(password, MAX_CHARACTERS);

	if (isValidUsername && isValidPassword) // Both inputs are valid
	{
		// Check if the entered username and password match to registered user
		for (unsigned int i = 0; i < numOfUsers; i++)
		{
			if (users[i]->getUsername().compare(username) == 0)
			{
				if (users[i]->getPassword().compare(password) == 0)
				{
					cout << "Logged in successfully!\n" << endl;
					cout << "Welcome back " << users[i]->getUsername() << "!\n" << endl;
					return users[i]; // User found
				}
			}
		}
	}

	cout << endl << "Wrong details. Login failed!\n" << endl;
	return nullptr; // User not found or invalid input - login failed
}

void ShopSystem::searchProducts() const
{
	string productName;
	int selection, numOfMatchingProducts = 0;
	bool areFound = false;
	unsigned int numOfAllProducts = allProducts.size();

	if (numOfAllProducts == 0) // No products in the shop
	{
		cout << "There are no products in the shop yet.\n" << endl;
	}
	else
	{
		if (Validations::searchProductSelectionValidation(selection)) // Selection validation
		{
			if ((ShopSystem::SearchProductOptions)selection == AllProducts)
			{
				showAllProducts(); // Show all the products in the shop
			}
			else // SpecificProductName
			{
				cout << "Product to search: ";
				Validations::cleanBuffer();
				if (Validations::getInput(productName, MAX_PRODUCT_NAME_LENGTH))
				{
					// Search for matching products in the general products array
					for (unsigned int i = 0; i < numOfAllProducts; i++)
					{
						if (allProducts[i]->getName().compare(productName) == 0) // Match
						{
							if (!areFound)
							{
								cout << "Products found:\n" << endl;
								areFound = true;
							}

							cout << numOfMatchingProducts + 1 << "." << *allProducts[i] << endl;
							cout << endl;
							numOfMatchingProducts++;
						}
					}
				}

				if (numOfMatchingProducts == 0) // No matching products found
				{
					cout << "No products found. Keep searching!\n" << endl;
				}
			}
		}
	}
}

void ShopSystem::addProductToUserCart(User& user) const
{
	Customer* customer = dynamic_cast<Customer*>(&user); if (!customer) return;
	unsigned int productID = 0;
	unsigned int numOfAllProducts = allProducts.size();

	if (numOfAllProducts == 0) // No products in the shop
	{
		cout << "There are no available products at the moment in the shop.\n" << endl;
	}
	else
	{
		if (Validations::productSerialNumberValidation(productID, numOfAllProducts)) // Valid product ID
		{
			for (unsigned int i = 0; i < numOfAllProducts; i++)
			{
				if (productID == allProducts[i]->getSerialNumber()) // Match
				{
					if (!Validations::isProductBelongsToUser(user, allProducts[i]->getSerialNumber()))
					{
						if (!Validations::isProductExists(allProducts[i]->getSerialNumber(), customer->getCart()))
						{
							// Add the chosen product to customer's cart
							customer->addProductToCart(*allProducts[i]);
							cout << "The product '" << allProducts[i]->getName() << "' added to cart successfully!\n" << endl;
						}
						else
						{
							cout << "You already added this product to your cart.\n" << endl;
						}
					}
					else
					{
						cout << "You can't add your own products to your cart.\n" << endl;
					}
					return;
				}
			}
		}
	}
}

void ShopSystem::checkout(User& user) const
{
	Customer* customer = dynamic_cast<Customer*>(&user); if (!customer) return;

	if (customer->getCart().size() == 0) // No products in cart
	{
		cout << "Please add products to your cart before checkout.\n" << endl;
	}
	else
	{
		Checkout* order = new Checkout(*customer);

		customer->showCart();
		cout << "Please enter one index at a time of chosen products to order." << endl;
		cout << "When you are done, enter -1 to continue to place order.\n" << endl;
		order->createNewOrder();

		if (order->getChosenProducts().size() == 0) // No products selected
		{
			cout << endl << "Order cancelled!\n" << endl;
			delete order;
		}
		else
		{
			cout << endl << *order;
			placeOrder(*order); // Place order
			customer->initCart(); // Initialize customer cart
			customer->addOrder(*order); // Add the new order to customer orders
		}
	}
}

void ShopSystem::placeOrder(const Checkout& order) const
{
	bool isPayed = false;
	float payment, res = 0, totalPrice = order.getTotalPrice();

	cout << "The total price of the order is: $" << totalPrice << endl;
	while (!isPayed)
	{
		cout << "Please enter the amount to pay: ";
		cin >> payment;

		if (!Validations::cinTypeCheck() || payment <= 0)
		{
			cout << "Invalid amount. Try again!" << endl;
		}
		else
		{
			res += payment;

			if (res < totalPrice)
			{
				cout << "Please add more $" << totalPrice - res << " to complete the order." << endl;
			}
			else if (res > totalPrice)
			{
				res -= payment;
				cout << "Add the appropriate amount! ";
				cout << "Please add more $" << totalPrice - res << " to complete the order." << endl;
			}
			else
			{
				cout << endl << "Order completed successfully!" << endl;
				cout << "Thanks for ordering from our shop!\n" << endl;
				isPayed = true;
			}
		}
	}
}

Date ShopSystem::readDate() const
{
	int day, month, year;

	cout << endl << "Fill in the date details.\n" << endl;
	Validations::dateValidation(day, month, year);
	return Date(day, month, year);
}

void ShopSystem::readTextForFeedback(string& text) const
{
	bool isValid;

	Validations::cleanBuffer();
	do
	{
		cout << endl << "Please write your feedback here (up to 90 characters):" << endl;
		isValid = Validations::getInput(text, MAX_FEEDBACK_LENGTH);
		if (!isValid)
		{
			cout << "Invalid input length. Please write again!" << endl;
		}
	} while (!isValid);
}

void ShopSystem::writeFeedback(User& user) const
{
	Customer* customer = dynamic_cast<Customer*>(&user); if (!customer) return;
	unsigned int index;

	if (customer->getOrders().size() == 0)
	{
		cout << "You have 0 orders made. Make an order so you could leave a feedback.\n" << endl;
	}
	else 
	{
		customer->showOrders();
		cout << endl << "Choose the index of the order you wish to make the feedback about: ";
		cin >> index;
		if (!Validations::cinTypeCheck() || !(1 <= index && index <= customer->getOrders().size()))
		{
			cout << "You don't have such order.\n" << endl;
		}
		else 
		{
			Checkout* selectedOrder = customer->getOrders()[index - 1];

			cout << *selectedOrder;
			cout << "Pick the index of the product to write its seller the feedback: ";
			cin >> index;
			if (!Validations::cinTypeCheck() || !(1 <= index && index <= selectedOrder->getChosenProducts().size()))
			{
				cout << "You don't have such product in this order.\n" << endl;
			}
			else 
			{
				Product* chosenProuct = selectedOrder->getChosenProducts()[index - 1];
				Seller* seller = dynamic_cast<Seller*>(&chosenProuct->getSeller()); if (!seller) return;
				string text;

				readTextForFeedback(text);
				seller->addFeedback(*new Feedback(user, *chosenProuct, readDate(), text)); // Add the feedback to its seller
				cout << endl << "Your feedback to " << chosenProuct->getSeller().getUsername() << " added successfully!\n" << endl;
			}
		}
	}
}

void ShopSystem::compareUsersCartsAmount() const
{
	int indexUser1 = 0, indexUser2 = 0;

	if (users.size() < 2)
	{
		cout << "There are no two users to compare yet.\n" << endl;
	}
	else
	{
		if (Validations::areValidUsers(users, indexUser1, indexUser2))
		{
			Customer* customer1 = dynamic_cast<Customer*>(users[indexUser1]);
			Customer* customer2 = dynamic_cast<Customer*>(users[indexUser2]);

			if (*customer1 > *customer2)
			{
				cout << customer1->getUsername() << "'s cart amount is bigger.\n" << endl;
			}
			else if (*customer2 > *customer1)
			{
				cout << customer2->getUsername() << "'s cart amount is bigger.\n" << endl;
			}
			else // Equal
			{
				cout << "Carts amounts are equal.\n" << endl;
			}
		}
		else
		{
			cout << "Invalid users selection!\n" << endl;
		}
	}
}

void ShopSystem::loadUsers(const char* fileName)
{
	unsigned int numOfUsers = 0;
	ifstream inFile(fileName, ios::binary | ios::in);

	inFile.read((char*)&numOfUsers, sizeof(numOfUsers));
	for (unsigned int i = 0; i < numOfUsers; i++)
	{
		users.push_back(&UserAnalyzer::loadUser(inFile));
	}

	inFile.close();
}

void ShopSystem::saveUsers(const char* fileName)
{
	unsigned int numOfUsers = users.size();
	ofstream outFile(fileName, ios::binary | ios::trunc);

	outFile.write((const char*)&numOfUsers, sizeof(numOfUsers));
	for (unsigned int i = 0; i < numOfUsers; i++)
	{
		users[i]->saveType(outFile);
		users[i]->save(outFile);
	}

	outFile.close();
}

User& ShopSystem::readUserData(UserAnalyzer::UserType type) const
{
	string username, password;
	string country, city, street;
	int buildingNumber;

	cout << "Thanks for joining in!"<< endl;
	cout << "Please fill in the following fields:\n" << endl;

	Validations::usernameValidation(username, users);
	Validations::passwordValidation(password);
	Validations::countryValidation(country);
	Validations::cityValidation(city);
	Validations::streetValidation(street);
	Validations::buildingNumberValidation(buildingNumber);
	cout << endl << "Registration completed successfully!\n" << endl;

	switch (type)
	{
	case UserAnalyzer::UserType::TypeSeller:
		return *new Seller(username, password, Address(country, city, street, buildingNumber));
	case UserAnalyzer::UserType::TypeCustomer:
		return *new Customer(username, password, Address(country, city, street, buildingNumber));
	default:
		return *new SellerCustomer(username, password, Address(country, city, street, buildingNumber));
	}
}

Product& ShopSystem::readProductData(User& user) const
{
	string productName;
	float price;
	int category;

	cout << "Please fill in the following fields.\n" << endl;
	Validations::productNameValidation(productName, user);
	Validations::priceValidation(price);
	Validations::categoryValidation(category);
	cout << endl << "Product added successfully!\n" << endl;

	return *new Product(productName, price, (Product::Category)category, user);
}