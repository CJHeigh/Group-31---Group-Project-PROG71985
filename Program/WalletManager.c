//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// WalletManager.c is responsible for managing memory data pulled from WalletDatabase.txt

#include "WalletManager.h" // This script's header file
#include "Wallet.h" // For accessing wallet information

void PrintWelcome()
{
	printf("*******************************\n*          WELCOME TO         *\n*  CRYPTO WALLET DATABASE V1  *\n*        PATENT PENDING       *\n*******************************\n\n");
}

void PrintMenu()
{
	// Keeps reprinting the menu until Quit() is executed
	while (1)
	{
		printf("To execute a function, type it's corrosponding key:\na) Add a crypto wallet\nb) Delete a crypto wallet\nc) Display/Update a crypto wallet\nd) Display a range of crypto wallets\ne) Display all crypto wallets\nf) Display wallets alphabetically\ng) Quit\n");

		char input = '.';
		while (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f' && input != 'g')
		{
			// Gets user input until a correct key is inputted
			scanf_s(" %c", &input, 1);
			// Clears the buffer of any potential extra characters. If removed, the buffer will empty at will!
			while (getchar() != '\n');
			// Displays an error message
			if (input != 'a' && input != 'b' && input != 'c' && input != 'd' && input != 'e' && input != 'f' && input != 'g')
				printf("Inappropriate input!\n");
		}

		switch (input)
		{
		case 'a':
			// Ask the user for a username and password. Ask if they also want to store btc. If not, return a negative float for AddWallet(btcToAdd).
			// Then find the nearest index to store the wallet and execute AddWallet
			addWalletFromMenu(walletDatabase);
			break;
		case 'b':
			// Get a wallet ID. Check if it exists or not. If it does, ask the user for the username and password to the wallet in order to execute the DeleteWallet function.
			DeleteWalletMenu();
			break;
		case 'c':
			DisplayWallet();
			break;
		case 'd':
			DisplayWalletRange();
			break;
		case 'e':
			DisplayAllWallets(walletDatabase);
			break;
		case 'f':
			displayOccupiedWalletsAlphabeticalByUsername(walletDatabase);
			break;
		case 'g':
			Quit();
			break;
		}

		printf("\n");
	}
}

void DisplayWallet()
{
	// I tried to be very verbose with my print statments they can be toned down once the function works properly.

	// Get a wallet ID and display it's ID, username, and btc amount // COMPLETED NOT TESTED

	// Ask the user if they would like to update the current wallet. // If they say yes, ask for the password corrosponding to the username. // COMPLETED NOT TESTED
	
	// If they match, ask if they would like to update their username, password, and btc amount. If any of the three variables doesn't need to be changed, return it as null when calling UpdateWallet() EXCEPT for btc amount. For btc amount, return a negative float.
	//UpdateWallet(); // COMPLETED NOT TESTED

	int userWalletID = 0;
	bool userInputInvalid = true;

	do
	{
		printf("%d", walletDatabase[0].walletID);
		printf("Enter the crypto wallet ID you wish to access -> ");
		scanf_s("%d", &userWalletID);

		// Wallet ID is not equal to index!
		userWalletID--;

		if (userWalletID < 0 || userWalletID >= DATABASE_SIZE)
		{
			printf("Wallet ID entered is invalid\n");
		}
		else
		{
			printf("Wallet ID entered is valid\n");
			userInputInvalid = false;
		}
	} while (userInputInvalid);

	if (walletDatabase[userWalletID].walletOccupied)
	{
		printf("Wallet ID -> %d\nUsername -> %s\n Bitcoin amount -> %f\n", walletDatabase[userWalletID].walletID, walletDatabase[userWalletID].walletUsername, walletDatabase[userWalletID].btcAmount);
	}
	else
	{
		printf("Wallet is unoccupied\n");
		return;
	}

	userInputInvalid = true;
	char userAnswer;
	char userPass[BUFFER_SIZE] = { 0 };

	do
	{
		printf("Would you like to update this current wallet? y or n -> ");
		scanf_s(" %c", &userAnswer, 1);

		if (userAnswer == 'y' || userAnswer == 'n')
		{
			if (userAnswer == 'n')
			{
				printf("Exciting wallet\n");
				return;
			}
			userInputInvalid = false;
		}
		else
		{
			printf("Character entered is invalid\n");
		}
	} while (userInputInvalid);

	userInputInvalid = true;

	do
	{
		printf("Enter Password for wallet #%d\nUsername -> %s\nPassword -> ", walletDatabase[userWalletID].walletID, walletDatabase[userWalletID].walletUsername);
		scanf_s("%s", userPass, BUFFER_SIZE);

		if (strcmp(userPass, walletDatabase[userWalletID].walletPassword) == 0)
		{
			float BTCamount = -1;
			char userChange[BUFFER_SIZE] = { 0 };
			char passChange[BUFFER_SIZE] = { 0 };

			printf("Would you like to change your Username? y or n -> ");
			scanf_s("%c", &userAnswer, 1);
			
			if (userAnswer == 'y')
			{
				printf("Enter what you would like to change your Username to -> ");
				scanf_s("%s", userChange, BUFFER_SIZE);
			}

			printf("Would you like to change your Password? y or n -> ");
			scanf_s("%c", &userAnswer, 1);

			if (userAnswer == 'y')
			{
				printf("Enter what you would like to change your Password to -> ");
				scanf_s("%s", passChange, BUFFER_SIZE);
			}

			printf("Do you need to change your Bitcoin amount? y or n -> ");
			scanf_s("%c", &userAnswer, 1);

			if (userAnswer == 'y')
			{
				printf("Enter what to change your Bitcoin amount to -> ");
				scanf_s("%f", &BTCamount);
			}

			UpdateWallet(walletDatabase[userWalletID], userChange, passChange, BTCamount);

			printf("Wallet successfuly updated, exceting wallet\n");
			userInputInvalid = false;
		}
		else
		{
			printf("Password entered is invalid\n");
		}
	} while (userInputInvalid);

	return;
}

void DisplayWalletRange() // Get two wallet ID's and print the wallet ID's, usernames, and btc amounts between them
{	
	int firstWalletID;
	//Input first wallet ID
	printf("Please enter the first wallet ID: ");
	scanf_s("%d", &firstWalletID);
	while (getchar() != '\n');

	int lastWalletID;
	//Input second wallet ID
	printf("Please enter the last wallet ID: ");
	scanf_s("%d", &lastWalletID);
	while (getchar() != '\n');

	// If the provided index is invalid...
	if (firstWalletID <= 0 || lastWalletID <= 0 || lastWalletID > DATABASE_SIZE || firstWalletID > lastWalletID)
		printf("Enter a valid wallet ID range!\n");
	// Otherwise,
	else
	{
		// For all elements in the user specified range...
		for (firstWalletID; firstWalletID <= lastWalletID; firstWalletID++)
		{
			printf("Wallet ID %d ", firstWalletID);

			// If the wallet ID is occupied, view it
			if (walletDatabase[firstWalletID - 1].walletOccupied != false && strcmp(walletDatabase[firstWalletID - 1].walletUsername, "") != 0)
				printf("is occupied by user %s and contains %f Bitcoin.\n", walletDatabase[firstWalletID - 1].walletUsername, walletDatabase[firstWalletID - 1].btcAmount);
			// Otherwise, notify the user that it is unoccupied
			else
				printf("is unoccupied.\n");
		}
	}
}

void DisplayAllWallets(Wallet* walletDatabase)
{
	for (int currentWalletID = 0; currentWalletID < DATABASE_SIZE; currentWalletID++)
	{
		if (!walletDatabase[currentWalletID].walletOccupied)
		{
			printf("WalletID: %d is EMPTY\n", currentWalletID + 1);
		}
		else
		{
			printf("WalletID: %d, IN USE, User: %s, Bitcoin Amount: %f\n",
				walletDatabase[currentWalletID].walletID,
				walletDatabase[currentWalletID].walletUsername,
				walletDatabase[currentWalletID].btcAmount);
		}
	}
}

void addWalletFromMenu(Wallet* walletDatabase)
{
	int maxLen = BUFFER_SIZE; // Max user input 
	char* userLetter = malloc(maxLen * sizeof(char)); // For user input

	puts("Enter '0' to return to menu. \n");

	// Display list of empty wallets of selected type
	for (int curWallet = 0; curWallet < BUFFER_SIZE; curWallet++)
	{
		if (walletDatabase[curWallet].walletOccupied == WALLETEMPTY)
		{
			printf("Wallet #%d is available.\n", curWallet);
		}
	}

	// Ask for wallet number to assign
	int userWalletDecision = 0;
	int selectedWalletID = 0;
	do
	{
		puts("Please enter the wallet #ID you would like to assign: \n");
		userWalletDecision = scanf("%s", userLetter);

		// Check for valid input
		if (userLetter == NULL)
			continue;

		// Convert string to integer
		selectedWalletID = atoi(userLetter);
		if (selectedWalletID == 0)
		{
			// Didn't convert to an integer
			printf("Invalid entry.");
			continue;
		}

		if (walletDatabase[selectedWalletID].walletOccupied == WALLETEMPTY)
		{
			printf("Wallet #%d is available and matches selection.\n", selectedWalletID);
			break;
		}

		if (selectedWalletID >= 0)
			break;

		printf("Wallet #%d doesn't match selection.\n", selectedWalletID);
	} while (1);

	// Loop to get username and password
	do
	{
		printf("Please enter the new wallet username: \n");
		userWalletDecision = scanf("%s", walletDatabase[selectedWalletID].walletUsername);
	} while (walletDatabase[selectedWalletID].walletUsername == NULL || userWalletDecision != 1);
	do
	{
		printf("Please enter the new password: \n");
		userWalletDecision = scanf("%s", walletDatabase[selectedWalletID].walletPassword);
	} while (walletDatabase[selectedWalletID].walletPassword == NULL || userWalletDecision != 1);

	// Mark room as assigned
	walletDatabase[selectedWalletID].walletOccupied = WALLETFULL;
	walletDatabase[selectedWalletID].walletID = selectedWalletID;

	// Run addWalletFunction with all the data 

	printf("Successfully added guest.\n\n");
}

void DeleteWalletMenu()
{
	int userID = 0;
	do
	{
		printf("Enter the wallet ID to be deleted: ");
		scanf_s("%d", &userID);
		userID--;
	} while (userID < 0 || userID >= DATABASE_SIZE);
	
	if (walletDatabase[userID].walletOccupied)
	{
		char userPass[BUFFER_SIZE] = { 0 };
		do
		{
			printf("Enter correct credentials for wallet ID %d\nUsername: %s\nPassword: ",
				walletDatabase[userID].walletID, walletDatabase[userID].walletUsername);
			scanf_s("%s", userPass, BUFFER_SIZE);
		} while (strcmp(userPass, walletDatabase[userID].walletPassword) != 0);

		walletDatabase[userID] = DeleteWallet(walletDatabase[userID]);
	}
	else
	{
		printf("Wallet is unoccupied in the database and cannot be deleted.\n");
	}

	return;
}

// Function to show alphabetical list of occupied wallets
// String comparison for qsort
int compareFunction(const char* a, const char* b)
{
	return strcmp(a, b);
}

void displayOccupiedWalletsAlphabeticalByUsername(Wallet* walletDatabase)
{
	// Temporary storage for usernames for sorting
	char lastNames[DATABASE_SIZE][BUFFER_SIZE];
	int currentPosition = 0;

	// Loop through wallets and find occupied ones
	for (int curWallet = 0; curWallet < DATABASE_SIZE; curWallet++)
	{
		// Copy username to temporary sorting array
		if (walletDatabase[curWallet].walletOccupied != WALLETEMPTY)
		{
			// Skip any 'occupied' wallets with empty username
			if (strcmp(walletDatabase[curWallet].walletUsername, " ") == 0)
			{
				continue;
			}
			strcpy(lastNames[currentPosition], walletDatabase[curWallet].walletUsername);
			currentPosition++;
		}
	}
	// No wallets currently occupied, return
	if (currentPosition == 0)
	{
		printf("No occupied wallets found.\n");
		return;
	}

	// Run sorting algorithm
	qsort(lastNames, currentPosition, sizeof(char) * BUFFER_SIZE, compareFunction);

	// Loop through usernames and find them in the original array for alphabetical printing
	for (int curName = 0; curName < DATABASE_SIZE; curName++)
	{
		// Loop through all rooms in original, unsorted list
		for (int curWallet = 0; curWallet < DATABASE_SIZE; curWallet++)
		{
			// Look for matching last names
			if (strcmp(walletDatabase[curWallet].walletUsername, lastNames[curName]) == 0)
			{
				// Print out occupancy data
				printf("WalletID: #%d, Username: %s\n",
					walletDatabase[curWallet].walletID,
					walletDatabase[curWallet].walletUsername);
	
			}
		}
	}
}