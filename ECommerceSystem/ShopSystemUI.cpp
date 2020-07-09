#include "ShopSystemUI.h"

bool ShopSystemUI::isEmptyString(string& str) const
{
	for (char character : str)
	{
		if (character != ' ' && character != '\t' && character != '\n')
		{
			return false;
		}
	}

	return true;
}

bool ShopSystemUI::isValidPositiveIntNumber(string& str) const
{
	for (char character : str)
	{
		if (!('0' <= character && character <= '9'))
		{
			return false;
		}
	}

	return true;
}

void ShopSystemUI::getNonEmptyStringFromUser(const char* msgToUser, string& userInput) const
{
	do
	{
		cout << msgToUser;
		getline(cin, userInput);
	} while (isEmptyString(userInput));
}

void ShopSystemUI::getPositiveNumberFromUser(const char* msgToUser, float& userInput) const
{
	string userInputStr;
	bool isValidNumber = false;

	while (!isValidNumber)
	{
		try
		{
			cout << msgToUser;
			getline(cin, userInputStr);
			userInput = stof(userInputStr);
			if (userInput > 0)
			{
				isValidNumber = true;
				break;
			}
		}
		catch (const exception& ex)
		{
		}

		cout << endl << "Invalid input. Please enter a valid positive float number.\n" << endl;
	}
}

void ShopSystemUI::getPositiveNumberFromUser(const char* msgToUser, int& userInput) const
{
	string userInputStr;
	bool isValidNumber = false;

	while (!isValidNumber)
	{
		try
		{
			cout << msgToUser;
			getline(cin, userInputStr);
			userInput = stoi(userInputStr);
			if (isValidPositiveIntNumber(userInputStr) && userInput > 0)
			{
				isValidNumber = true;
				break;
			}
		}
		catch (const exception& ex)
		{
		}

		cout << endl << "Invalid input. Please enter a valid positive integer number.\n" << endl;
	}
}

void ShopSystemUI::runShopSystem()
{
	bool toExit = false;

	cout << "Welcome to the shop!\n" << endl;
	cout << "Loading..." << endl;
	this_thread::sleep_for(chrono::seconds(2));

	do
	{
		runLoginMenu(toExit);
	} while (!toExit);

	system("cls");
	cout << "Thanks for visiting our shop! See you next time!" << endl;
}

void ShopSystemUI::runLoginMenu(bool& toExit)
{
	int userChoice;

	system("cls");
	cout << menu.loginMenuToString();
	getPositiveNumberFromUser("Your selection: ", userChoice);

	switch ((eLoginOptions)userChoice)
	{
	case Signup:
		signupUser(toExit);
		break;

	case Login:
		loginUser(toExit);
		break;

	case LoginMenuExit:
		toExit = true;
		break;

	default:
		cout << endl << "Please choose from the following options!\n" << endl;
		waitForKeyToContinue();
	}
}

void ShopSystemUI::runMainMenu(User& user, bool& toExit)
{
	bool toLogout = false;
	int userChoice;

	while (!toExit && !toLogout)
	{
		system("cls");
		cout << menu.mainMenuToString();
		getPositiveNumberFromUser("Your selection: ", userChoice);

		switch ((eRegisteredUserOptions)userChoice)
		{
		case AddNewProductForSale:
			addNewProductForSale(user);
			break;
		
		case SearchProducts:
			searchProducts();
			break;

		case AddProductToCart:
			addProductToUserCart(user);
			break;

		case ViewCart:
			viewUserCart(user);
			break;

		case CheckoutAndPlaceOrder:
			checkoutUserAndPlaceOrder(user);
			break;

		case WriteFeedback:
			writeFeedbackToOtherUser(user);
			break;

		case ViewPersonalProducts:
			viewUserProducts(user);
			break;

		case ViewPersonalFeedbacks:
			viewUserFeedbacks(user);
			break;

		case ViewOrders:
			viewUserOrders(user);
			break;

		case ViewAllUsers:
			showAllUsers();
			break;

		case Logout:
			toLogout = true;
			break;

		case MainMenuExit:
			toExit = true;
			break;

		default:
			cout << endl << "Please choose from the following options!\n" << endl;
			waitForKeyToContinue();
		}
	}
}

void ShopSystemUI::getUsernameInputFromUser(const char* msgToUser, string& userInput) const
{
	bool isValidUsername;

	do
	{
		getNonEmptyStringFromUser(msgToUser, userInput);
		isValidUsername = !shopSystem.isUsernameExists(userInput, shopSystem.getUsers());
		if (!isValidUsername)
		{
			cout << endl << "Username already taken! Please choose a different username.\n" << endl;
		}
	} while (!isValidUsername);
}

void ShopSystemUI::getProductNameInputFromUser(const char* msgToUser, string& userInput, User& user) const
{
	bool isValidProductName;

	do
	{
		getNonEmptyStringFromUser(msgToUser, userInput);
		isValidProductName = !shopSystem.isProductNameExists(userInput, user.getProductsForSale());
		if (!isValidProductName)
		{
			cout << endl << "You already added this product. Please add a different one.\n" << endl;
		}
	} while (!isValidProductName);
}

void ShopSystemUI::getCategoryInputFromUser(const char* msgToUser, int& userInput) const
{
	bool isValidCategory;

	do
	{
		getPositiveNumberFromUser(msgToUser, userInput);
		isValidCategory = shopSystem.isValidCategory(userInput);
		if (!isValidCategory)
		{
			cout << endl << "You chose an invalid category. Please try again.\n" << endl;
		}
	} while (!isValidCategory);
}

void ShopSystemUI::loginUser(bool& toExit)
{
	string username, password;

	system("cls");
	cout << "Please login with your credentials.\n" << endl;
	getNonEmptyStringFromUser("Username: ", username);
	getNonEmptyStringFromUser("Password: ", password);
	
	User* user = shopSystem.getUserByCredentials(username, password);
	if (user == nullptr)
	{
		cout << endl << "Wrong details. Login failed!\n" << endl;
		waitForKeyToContinue();
		return;
	}

	cout << endl << "Logged in successfully. Welcome back " << user->getUsername() << "!\n" << endl;
	waitForKeyToContinue();
	runMainMenu(*user, toExit);
}

void ShopSystemUI::signupUser(bool& toExit)
{
	system("cls");
	cout << "Thanks for joining in!" << endl;
	cout << "Please fill in the following fields:\n" << endl;
	User& user = readUserData();

	cout << endl << "Registration completed successfully!\n" << endl;
	shopSystem.addNewUser(user);
	waitForKeyToContinue();
	runMainMenu(user, toExit);
}

void ShopSystemUI::searchProducts() const
{
	int userChoice;
	const char* msgToUser = "Press 1 to show all products in the shop.\nPress 2 to search for a product by name.\n\nYour selection: ";

	system("cls");
	if (shopSystem.getAllProducts().size() == 0)
	{
		cout << "There are no available products at the moment in the shop.\n" << endl;
		waitForKeyToContinue();
		return;
	}

	getPositiveNumberFromUser(msgToUser, userChoice);
	switch ((eSearchProductsOptions)userChoice)
	{
	case AllProducts:
		showAllProducts();
		break;

	case SpecificProductName:
		showProductsByName();
		break;

	default:
		cout << endl << "You entered an invalid option choice.\n" << endl;
	}

	waitForKeyToContinue();
}

void ShopSystemUI::showProductsByName() const
{
	bool areProductsFound = false;
	vector<Product*> allProducts = shopSystem.getAllProducts();
	string productName;
	int numOfMatchingProducts = 0;

	system("cls");
	getNonEmptyStringFromUser("Product to search: ", productName);
	for (Product* product : allProducts)
	{
		if (product->getName().compare(productName) == 0)
		{
			if (!areProductsFound)
			{
				cout << endl << "Products found:\n" << endl;
				areProductsFound = true;
			}

			cout << numOfMatchingProducts + 1 << "." << product->toString() << endl;
			cout << endl;
			numOfMatchingProducts++;
		}
	}

	if (numOfMatchingProducts == 0)
	{
		cout << endl << "No products found. Keep searching!\n" << endl;
	}
}

void ShopSystemUI::addNewProductForSale(User& user)
{
	system("cls");
	cout << "Please fill in the following fields.\n" << endl;
	Product& newProduct = readProductData(user);

	// Add the new product for sale to its user
	user.addProductForSale(newProduct);

	// Add the new product to the general products array
	shopSystem.addProductToStock(newProduct);

	cout << endl << "Product added successfully!\n" << endl;
	waitForKeyToContinue();
}

bool ShopSystemUI::getValidProductIdToSearch(int& productId) const
{
	if (shopSystem.getAllProducts().size() == 0)
	{
		cout << "There are no available products at the moment in the shop.\n" << endl;
		return false;
	}

	getPositiveNumberFromUser("Please provide the serial number of wanted product to add to cart: ", productId);
	if (!shopSystem.isValidProductId(productId))
	{
		cout << endl << "Serial number not found. Please search for an existing product and try again!\n" << endl;
		return false;
	}

	return true;
}

bool ShopSystemUI::getValidOrderIndexForFeedback(User& user, int& orderIndex) const
{
	cout << user.ordersToString();
	getPositiveNumberFromUser("Choose the index of the order you wish to make the feedback about: ", orderIndex);

	if (!(1 <= orderIndex && orderIndex <= user.getOrders().size()))
	{
		cout << endl << "You don't have such order.\n" << endl;
		return false;
	}

	return true;
}

bool ShopSystemUI::getValidProductIndexForFeedback(Order& selectedOrder, int& productIndex) const
{
	system("cls");
	cout << selectedOrder.toString();
	getPositiveNumberFromUser("Pick the index of the product to write its seller the feedback: ", productIndex);
	
	if (!(1 <= productIndex && productIndex<= selectedOrder.getChosenProducts().size()))
	{
		cout << endl << "You don't have such product in this order.\n" << endl;
		return false;
	}

	return true;
}

void ShopSystemUI::getFeedbackFromUserAndAddToSeller(Product& chosenProduct, User& customer) const
{
	User& seller = chosenProduct.getSeller();
	string feedbackText;

	system("cls");
	getNonEmptyStringFromUser("Please write your feedback here:\n", feedbackText);

	seller.addFeedback(*new Feedback(customer, chosenProduct, readDate(), feedbackText));
	cout << endl << "Your feedback to " << seller.getUsername() << " added successfully!\n" << endl;
}

void ShopSystemUI::showAllUsers() const
{
	vector<User*> allUsers = shopSystem.getUsers();

	system("cls");
	if (allUsers.size() == 0)
	{
		cout << "There are no regisetered users in the shop yet.\n" << endl;
		waitForKeyToContinue();
		return;
	}

	cout << "Shop's users:" << endl;
	cout << "----------------------------------------------------\n" << endl;
	for (User* user : allUsers)
	{
		cout << user->toString();
		cout << "----------------------------------------------------\n" << endl;
	}

	waitForKeyToContinue();
}

void ShopSystemUI::showAllProducts() const
{
	vector<Product*> allProducts = shopSystem.getAllProducts();
	unsigned int numOfAllProducts = allProducts.size();

	system("cls");
	if (numOfAllProducts == 0)
	{
		cout << "There are no products in the shop yet.\n" << endl;
		waitForKeyToContinue();
		return;
	}
	
	cout << "Shop's products:\n" << endl;
	for (unsigned int i = 0; i < numOfAllProducts; i++)
	{
		cout << i + 1 << ".\n" << allProducts[i]->toString() << endl;
	}

	cout << endl;
}

void ShopSystemUI::waitForKeyToContinue() const
{
	cout << "Press any key to continue." << endl;
	getchar();
}

void ShopSystemUI::viewUserCart(User& user) const
{
	system("cls");
	cout << user.cartToString();
	waitForKeyToContinue();
}

void ShopSystemUI::viewUserOrders(User& user) const
{
	system("cls");
	cout << user.ordersToString();
	waitForKeyToContinue();
}

void ShopSystemUI::viewUserProducts(User& user) const
{
	system("cls");
	cout << "Your products for sale:\n" << endl;
	cout << user.productsForSaleToString();
	waitForKeyToContinue();
}

void ShopSystemUI::viewUserFeedbacks(User& user) const
{
	system("cls");
	cout << "Your feedbacks:\n" << endl;
	cout << user.feedbacksToString();
	waitForKeyToContinue();
}

void ShopSystemUI::addProductToUserCart(User& user) const
{
	int productId = 0;

	system("cls");
	if (!getValidProductIdToSearch(productId))
	{
		waitForKeyToContinue();
		return;
	}

	if (!shopSystem.isProductBelongsToUser(user, productId))
	{
		if (!shopSystem.isProductExistsInUserCart(user, productId))
		{
			Product& chosenProduct = *shopSystem.getProductById(productId, shopSystem.getAllProducts());
			user.addProductToCart(chosenProduct);
			cout << endl << "The product '" << chosenProduct.getName() << "' added to cart successfully!\n" << endl;
		}
		else
		{
			cout << endl << "You already added this product to your cart.\n" << endl;
		}
	}
	else
	{
		cout << endl << "You can't add your own products to your cart.\n" << endl;
	}

	waitForKeyToContinue();
}

void ShopSystemUI::checkoutUserAndPlaceOrder(User& user) const
{
	system("cls");
	if (user.getCart().size() == 0)
	{
		cout << "Please add products to your cart before checkout.\n" << endl;
		waitForKeyToContinue();
		return;
	}
	
	Order& order = createNewOrder(user);
	if (order.getChosenProducts().size() == 0)
	{
		cout << endl << "Order cancelled!\n" << endl;
		delete &order;
	}
	else
	{
		order.updateTotalPrice();
		placeOrder(order);
		user.initCart();
		user.addOrder(order);
	}

	waitForKeyToContinue();
}

Order& ShopSystemUI::createNewOrder(User& user) const
{
	Order& order = *new Order(user);
	bool toContinueOrder = true;
	Product* productToAdd;

	cout << user.cartToString();
	cout << "Please enter one index at a time of chosen product to order." << endl;
	cout << "When you are done, enter -1 to continue to place order.\n" << endl;

	while (toContinueOrder)
	{
		productToAdd = getProductToAddToOrder(user, order);
		if (productToAdd != nullptr)
		{
			order.addProduct(*productToAdd);
			order.addSeller(productToAdd->getSeller());
			cout << endl << "The product '" << productToAdd->getName() << "' added successfully to order.\n" << endl;
		}
		else
		{
			toContinueOrder = false;
		}
	}

	return order;
}

void ShopSystemUI::placeOrder(Order& order) const
{
	bool isPayed = false;
	float payment;
	float totalPayment = 0;
	float totalPrice = order.getTotalPrice();

	system("cls");
	cout << order.toString();
	cout << "The total price of the order is: $" << totalPrice << endl << endl;

	while (!isPayed)
	{
		getPositiveNumberFromUser("Please enter the amount to pay: ", payment);
		totalPayment += payment;
		if (totalPayment < totalPrice)
		{
			cout << endl << "Please add more $" << totalPrice - totalPayment << " to complete the order.\n" << endl;
		}
		else if (totalPayment > totalPrice)
		{
			totalPayment -= payment;
			cout << endl << "Enter the appropriate amount!" << endl;
			cout << "Please add more $" << totalPrice - totalPayment << " to complete the order.\n" << endl;
		}
		else
		{
			cout << endl << "Order completed successfully. Thanks for ordering from our shop!\n" << endl;
			isPayed = true;
		}
	}
}

void ShopSystemUI::writeFeedbackToOtherUser(User& user) const
{
	int orderIndex = -1;
	int productIndex = -1;
	Order* selectedOrder;
	Product* selectedProduct;

	system("cls");
	if (user.getOrders().size() == 0)
	{
		cout << "You have 0 orders made. Make an order so you could leave a feedback.\n" << endl;
		waitForKeyToContinue();
		return;
	}
	
	if (!getValidOrderIndexForFeedback(user, orderIndex))
	{
		waitForKeyToContinue();
		return;
	}

	selectedOrder = user.getOrders()[orderIndex - 1];
	if (!getValidProductIndexForFeedback(*selectedOrder, productIndex))
	{
		waitForKeyToContinue();
		return;
	}

	selectedProduct = selectedOrder->getChosenProducts()[productIndex - 1];
	getFeedbackFromUserAndAddToSeller(*selectedProduct, user);
	waitForKeyToContinue();
}

Product* ShopSystemUI::getProductToAddToOrder(User& user, Order& order) const
{
	unsigned int numOfProductsInCart = user.getCart().size();
	string chosenProductIndexStr;
	int chosenProductIndex;
	Product* chosenProduct = nullptr;
	bool isValidProductIndex = false;

	while (!isValidProductIndex)
	{
		getNonEmptyStringFromUser("Chosen product index: ", chosenProductIndexStr);
		if (chosenProductIndexStr == "-1")
		{
			break;
		}

		if (!isValidPositiveIntNumber(chosenProductIndexStr))
		{
			cout << endl << "Invalid input. Please enter a valid positive integer number.\n" << endl;
			continue;
		}

		chosenProductIndex = stoi(chosenProductIndexStr);
		if (!(1 <= chosenProductIndex && chosenProductIndex <= numOfProductsInCart))
		{
			cout << endl << "You entered an invalid index. Try again!\n" << endl;
			continue;
		}
		
		chosenProduct = user.getCart().at(chosenProductIndex - 1);
		if (shopSystem.isProductExistsInUserOrder(order, chosenProduct->getSerialNumber()))
		{
			cout << endl << "You already added this product.\n" << endl;
			continue;
		}

		isValidProductIndex = true;
	}
	
	return chosenProduct;
}

User& ShopSystemUI::readUserData() const
{
	string username, password, country, city, street;
	int buildingNumber;

	getUsernameInputFromUser("Username: ", username);
	getNonEmptyStringFromUser("Password: ", password);
	getNonEmptyStringFromUser("Country: ", country);
	getNonEmptyStringFromUser("City: ", city);
	getNonEmptyStringFromUser("Street: ", street);
	getPositiveNumberFromUser("Building number: ", buildingNumber);

	return *new User(username, password, Address(country, city, street, buildingNumber));
}

Product& ShopSystemUI::readProductData(User& user) const
{
	string productName;
	float price;
	int category;

	getProductNameInputFromUser("Product name: ", productName, user);
	getPositiveNumberFromUser("Price: ", price);
	getCategoryInputFromUser("Category (choose from the following: 1-Clothing, 2-Kids, 3-Electricity, 4-Office): ", category);

	return *new Product(productName, price, (Product::eCategory)category, user);
}

Date ShopSystemUI::readDate() const
{
	const int CURRENT_YEAR = 2020;
	int day, month, year;
	bool isValidDay, isValidMonth, isValidYear;

	system("cls");
	cout << "Fill in the date details.\n" << endl;

	do
	{
		getPositiveNumberFromUser("Please enter the day: ", day);
		isValidDay = 1 <= day && day <= 31;
		if (!isValidDay)
		{
			cout << endl << "Your entered an invalid day. Try again!\n" << endl;
		}
	} while (!isValidDay);

	do
	{
		getPositiveNumberFromUser("Please enter the month: ", month);
		isValidMonth = 1 <= month && month <= 12;
		if (!isValidMonth)
		{
			cout << endl << "Your entered an invalid month. Try again!\n" << endl;
		}
	} while (!isValidMonth);

	do
	{
		getPositiveNumberFromUser("Please enter the year: ", year);
		isValidYear = year == CURRENT_YEAR;
		if (!isValidYear)
		{
			cout << endl << "Your entered an invalid year. Enter the current year!\n" << endl;
		}
	} while (!isValidYear);

	return Date(day, month, year);
}