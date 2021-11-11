//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// WalletManager.c is responsible for managing memory data pulled from WalletDatabase.txt

#include "WalletManager.h" // This script's header file
#include "Wallet.h" // For accessing wallet information

bool printWelcome = true;
bool stopMenu = false;

void PrintMenu()
{
	// Keeps reprinting the menu until Quit() is executed
	while (!stopMenu)
	{
		if (printWelcome)
		{
			printf("*******************************\n*          WELCOME TO         *\n*  CRYPTO WALLET DATABASE V1  *\n*        PATENT PENDING       *\n*******************************\n\n");
			printWelcome = false;
		}

		printf("To execute a function, type it's corrosponding key:\na) Add a crypto wallet\nb) Delete a crypto wallet\nc) Display/Update a crypto wallet\nd)Display a range of crypto wallets\nd) Display all crypto wallets\nf) Quit\n");

		char input = '.';
		while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f')
		{
			// Gets user input until a correct key is inputted
			scanf_s(" %c", &input, 1);
			// Clears the buffer of any potential extra characters. If removed, the buffer will empty at will!
			while (getchar() != '\n');
			// Displays an error message
			if (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f')
				printf("Inappropriate input!\n");
		}

		switch (input)
		{
		case 'a':
			// Ask the user for a username and password. Ask if they also want to store btc. If not, return a negative float for AddWallet(btcToAdd).
			// Then find the nearest index to store the wallet and execute AddWallet
			AddWallet();
			break;
		case 'b':
			// Get a wallet ID. Check if it exists or not. If it does, ask the user for the username and password to the wallet in order to execute the DeleteWallet function.
			DeleteWallet();
			break;
		case 'c':
			DisplayWallet();
			break;
		case 'd':
			DisplayWalletRange();
			break;
		case 'e':
			DisplayAllWallets();
			break;
		case 'f':
			stopMenu = true;
			Quit();
			break;
		}

		printf("\n");
	}
}

void DisplayWallet()
{
	// Get a wallet ID and display it's ID, username, and btc amount 

	// Ask the user if they would like to update the current wallet. // If they say yes, ask for the password corrosponding to the username.
	
	// If they match, ask if they would like to update their username, password, and btc amount. If any of the three variables doesn't need to be changed, return it as null when calling UpdateWallet() EXCEPT for btc amount. For btc amount, return a negative float.
	UpdateWallet();
}

void DisplayWalletRange()
{
	// Get two wallet ID's and print the wallet ID's, usernames, and btc amounts between them
}

void DisplayAllWallets()
{
	// Display and print all wallet ID's, usernames, and btc amounts
}