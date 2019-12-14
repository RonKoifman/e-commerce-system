#include "Customer.h"
#include "Checkout.h"

Checkout::Checkout(Customer* customer) // C'tor
	: customer(customer), sellers(nullptr), chosenProducts(nullptr), numOfChosenProducts(0), numOfSellers(0), totalPrice(0)
{
}

Checkout::~Checkout() // D'tor
{
	delete[] chosenProducts; // The products pointers themselves will be released at each of their seller d'tor
	delete[] sellers; // The seller pointers themselves will be released at the shop system d'tor
}

Product** Checkout::getChosenProducts() const
{
	return chosenProducts;
}

int Checkout::getNumOfChosenProducts() const
{
	return numOfChosenProducts;
}

float Checkout::getTotalPrice() const
{
	return totalPrice;
}

Seller** Checkout::getSellers() const
{
	return sellers;
}

int Checkout::getNumOfSellers() const
{
	return numOfSellers;
}

Customer* Checkout::getCustomer() const
{
	return customer;
}

void Checkout::show() const
{
	cout << "Chosen products:\n" << endl;
	for (int i = 0; i < numOfChosenProducts; i++)
	{
		cout << i + 1 << "."; chosenProducts[i]->show(); cout << endl;
	}
}

void Checkout::calculateTotalPrice()
{
	for (int i = 0; i < numOfChosenProducts; i++)
	{
		totalPrice += chosenProducts[i]->getPrice();
	}
}

void Checkout::addChosenProduct(Product* newProduct)
{
	int i;

	Product** temp = new Product*[numOfChosenProducts + 1]; // Create bigger array to add the new product

	// Move the pointers from the current array to temp
	for (i = 0; i < numOfChosenProducts; i++)
	{
		temp[i] = chosenProducts[i];
	}
	temp[i] = newProduct; // Add the new product
	numOfChosenProducts++;

	delete[] chosenProducts; // Free the current array
	chosenProducts = temp; // Update products array to temp
}

void Checkout::addSeller(Seller* seller)
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

void Checkout::createNewOrder()
{
	Product* product;
	int index = 0;
	bool toContinue = true;

	customer->showCart();
	cout << "Please enter one index at a time of chosen products to order." << endl;
	cout << "When you are done, enter -1 to continue to place order.\n" << endl;

	while (toContinue)
	{
		product = indexOfCheckoutProductValidation(index, customer->getCart(), customer->getNumOfProductsInCart(), chosenProducts, numOfChosenProducts);
		if (index == -1) // Customer finished to add products to order
		{
			toContinue = false;
		}
		else
		{
			addChosenProduct(product); // Add product to the chosen products array
			Seller* seller = product->getSeller();
			// Only if seller not exists already - add product's seller to the products sellers array
			if (!isSellerExists(seller, sellers, numOfSellers))
			{
				addSeller(seller);
			}
		}
	}
	
	calculateTotalPrice();
}

void Checkout::placeOrder() const
{
	bool isPayed = false;
	float payment, res = 0;

	cout << "The total price of the order is: $" << totalPrice << endl;
	while (!isPayed)
	{
		cout << "Please enter the amount to pay: ";
		cin >> payment;

		if (!cinTypeCheck())
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
				cout << "Add the appropriate amount! ";
				res -= payment;
				cout << "Please add more $" << totalPrice - res << " to complete the order." << endl;
			}
			else
			{
				cout << endl << "Order completed successfully!" << endl;
				isPayed = true;
			}
		}
	}

	cout << "Thanks for ordering from Pied Piper Shop!\n" << endl;
}

void Checkout::showSellers() const
{
	int i;
	cout << "\tSellers names: " << sellers[0]->getUsername();
	for (i = 1; i < numOfSellers; i++) {
		cout << ", " << sellers[i]->getUsername();
	}
	cout << endl;
}

void Checkout::showProductsNames() const
{
	int i;
	cout << "Products names: " << chosenProducts[0]->getName();
	for (i = 1; i < numOfChosenProducts; i++) {
		cout << ", " << chosenProducts[i]->getName();
	}
	cout << endl;
}