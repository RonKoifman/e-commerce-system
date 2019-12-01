#include "ShopSystem.h"

int main()
{
	ShopSystem shop("Pied Piper Shop");
	bool toContinue = true;

	cout << "Welcome to " << shop.getName() << ". The shop of the new Internet!\n" << endl;
	while (toContinue)
	{
		toContinue = shop.showLoginMenu();
	}

	cout << "Thanks for visiting our shop! See you next time!" << endl;
}