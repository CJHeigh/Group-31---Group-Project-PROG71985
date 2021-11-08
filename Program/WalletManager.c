//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// WalletManager.c is responsible for managing memory data pulled from WalletDatabase.txt

#include "WalletManager.h"
#include "Wallet.h"

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

		printf("To execute a function, type it's corrosponding key:\na) Add a crypto wallet\nb) Delete a crypto wallet\nc) Update a crypto wallet\nd) Display a crypto wallet\ne) Display a range of crypto wallets\nf) Display all wallets\ng) Search for a wallet\nh) Quit\n");

		char input = '.';
		while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f' && input != 'g' && input != 'h')
		{
			// Gets user input until a correct key is inputted
			scanf_s(" %c", &input, 1);
			// Clears the buffer of any potential extra characters. If removed, the buffer will empty at will!
			while (getchar() != '\n');
			// Displays an error message
			if (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f' && input != 'g' && input != 'h')
				printf("Inappropriate input!\n");
		}

		switch (input)
		{
		case 'a':
			AddWallet();
			break;
		case 'b':
			DeleteWallet();
			break;
		case 'c':
			UpdateWallet();
			break;
		case 'd':
			DisplayWallet();
			break;
		case 'e':
			DisplayWalletRange();
			break;
		case 'f':
			DisplayAllWallets();
			break;
		case 'g':
			SearchForWallet();
			break;
		case 'h':
			stopMenu = true;
			Quit();
			break;
		}

		printf("\n");
	}
}

void DisplayWallet()
{

}

void DisplayWalletRange()
{

}

void DisplayAllWallets()
{

}

void SearchForWallet()
{

}