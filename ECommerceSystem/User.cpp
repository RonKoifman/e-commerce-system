#include "Feedback.h"
#include "User.h"

User::User(const string& username, const string& password, const Address& address)
	: username(username), password(password), address(address)
{
}

User::User(ifstream& inFile)
	: address(Address(inFile))
{
	const int MAX_CHARACTERS_TO_READ = 1000;
	char tempStr[MAX_CHARACTERS_TO_READ + 1];
	int length;

	// Username
	inFile.read((char*)&length, sizeof(length));
	inFile.read((char*)&tempStr, length);
	tempStr[length] = '\0';
	username = tempStr;

	// Password
	inFile.read((char*)&length, sizeof(length));
	inFile.read((char*)&tempStr, length);
	tempStr[length] = '\0';
	password = tempStr;
}

User::~User()
{
	for (Product* product : productsForSale)
	{
		delete product;
	}

	for (Feedback* feedback : feedbacks)
	{
		delete feedback;
	}

	for (Checkout* order : orders)
	{
		delete order;
	}
}

void User::save(ofstream& outFile) const
{
	int length;

	// Address
	address.save(outFile);

	// Username
	length = username.length();
	outFile.write((const char*)&length, sizeof(length));
	outFile.write((const char*)username.c_str(), length);

	// Password
	length = password.length();
	outFile.write((const char*)&length, sizeof(length));
	outFile.write((const char*)password.c_str(), length);
}

void User::setUsername(const string& username)
{
	this->username = username;
}

void User::setPassword(const string& password)
{
	this->password = password;
}

void User::setAddress(const Address& address)
{
	this->address = address;
}

const string& User::getUsername() const
{
	return username;
}

const string& User::getPassword() const
{
	return password;
}

const Address& User::getAddress() const
{
	return address;
}

const vector<Product*>& User::getCart() const
{
	return cart;
}

const vector<Checkout*>& User::getOrders() const
{
	return orders;
}

const vector<Feedback*>& User::getFeedbacks() const
{
	return feedbacks;
}

const vector<Product*>& User::getProductsForSale() const
{
	return productsForSale;
}

void User::addFeedback(Feedback& newFeedback)
{
	feedbacks.push_back(&newFeedback);
}

void User::addProductForSale(Product& newProduct)
{
	productsForSale.push_back(&newProduct);
}

void User::addProductToCart(Product& chosenProduct)
{
	cart.push_back(&chosenProduct);
}

void User::addOrder(Checkout& newOrder)
{
	orders.push_back(&newOrder);
}

void User::initCart()
{
	cart.clear();
}

const string& User::ordersToString() const
{
	unsigned int numOfOrders = orders.size();
	string& ordersStr = *new string();

	if (numOfOrders == 0)
	{
		ordersStr.append("No orders yet.\n\n");
	}
	else
	{
		ordersStr.append("Your orders:\n\n");
		for (unsigned int i = 0; i < numOfOrders; i++)
		{
			ordersStr.append(to_string(i + 1)).append(". \t");
			ordersStr.append(orders[i]->productsNamesToString());
			ordersStr.append("\tPrice: $").append(to_string(orders[i]->getTotalPrice())).append("\n");
			ordersStr.append(orders[i]->sellersNamesToString()).append("\n");
		}
	}

	return ordersStr;
}

const string& User::productsForSaleToString() const
{
	unsigned int numOfProducts = productsForSale.size();
	string& productsStr = *new string();

	if (numOfProducts == 0)
	{
		productsStr.append("none.\n\n");
	}
	else
	{
		for (unsigned int i = 0; i < numOfProducts; i++)
		{
			productsStr.append(to_string(i + 1)).append(". ").append(productsForSale[i]->toString()).append("\n\n");
		}
	}

	return productsStr;
}

const string& User::feedbacksToString() const
{
	unsigned int numOfFeedbacks = feedbacks.size();
	string& feedbacksStr = *new string();

	if (numOfFeedbacks == 0)
	{
		feedbacksStr.append("none.\n\n");
	}
	else
	{
		for (unsigned int i = 0; i < numOfFeedbacks; i++)
		{
			feedbacksStr.append(to_string(i + 1)).append(". ").append(feedbacks[i]->toString()).append("\n\n");
		}
	}

	return feedbacksStr;
}

const string& User::cartToString() const
{
	unsigned int numOfProductsInCart = cart.size();
	string& cartStr = *new string();

	if (numOfProductsInCart == 0)
	{
		cartStr.append("No products in the cart.\n\n");
	}
	else
	{
		cartStr.append("Your cart:\n\n");
		for (unsigned int i = 0; i < numOfProductsInCart; i++)
		{
			cartStr.append(to_string(i + 1)).append(".").append(cart[i]->toString()).append("\n\n");
		}
	}

	return cartStr;
}

const string& User::toString() const
{
	string& userStr = *new string();

	userStr.append("Username: ").append(username).append("\n\n");
	userStr.append("Address: ").append(address.toString()).append("\n\n");
	userStr.append("Products for sale: ").append("\n").append(productsForSaleToString());
	userStr.append("Feedbacks: ").append("\n").append(feedbacksToString());

	return userStr;
}