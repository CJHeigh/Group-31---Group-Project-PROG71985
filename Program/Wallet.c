//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// Wallet.c stores the basic functions of a crypto wallet

#include "Wallet.h" // This script's header file

Wallet* AddWallet(int walletIDToAdd, char usernameToAdd[BUFFER_SIZE], char passwordToAdd[BUFFER_SIZE], float btcToAdd)
{
	Wallet temp;
	temp.walletOccupied = true;

	Wallet* walletToReturn = malloc(&temp, sizeof(temp)+1);
	walletToReturn->walletID = walletIDToAdd;
	strcpy(walletToReturn->walletUsername, usernameToAdd);
	strcpy(walletToReturn->walletPassword, passwordToAdd);
	walletToReturn->btcAmount = btcToAdd;

	return walletToReturn;
}

Wallet* DeleteWallet()
{
	Wallet temp;
	temp.walletOccupied = false;

	Wallet* walletToReturn = malloc(&temp, sizeof(temp) + 1);
	*walletToReturn->walletUsername = NULL;
	*walletToReturn->walletPassword = NULL;
	walletToReturn->btcAmount = 0;

	return walletToReturn;
}

Wallet* UpdateWallet(Wallet* walletToUpdate, char usernameToUpdateTo[BUFFER_SIZE], char passwordToUpdateTo[BUFFER_SIZE], float btcToUpdateTo)
{
	Wallet* walletToReturn = malloc(walletToUpdate, sizeof(walletToUpdate)+1);

	if (usernameToUpdateTo != NULL)
	{
		strcpy(walletToUpdate->walletUsername, usernameToUpdateTo);
		printf("Username has successfully change to '%s'.", usernameToUpdateTo);
	}

	if (passwordToUpdateTo != NULL)
	{
		strcpy(walletToUpdate->walletPassword, passwordToUpdateTo);
		printf("Password has successfully change to '%s'.", passwordToUpdateTo);
	}

	if (btcToUpdateTo >= 0)
	{
		walletToUpdate->btcAmount = btcToUpdateTo;
		printf("BTC has been updated to %f.", btcToUpdateTo);
	}

	return walletToReturn;
}