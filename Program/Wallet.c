//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// Wallet.c stores the basic functions of a crypto wallet

#include "Wallet.h" // This script's header file

Wallet AddWallet(int walletIDToAdd, char usernameToAdd[BUFFER_SIZE], char passwordToAdd[BUFFER_SIZE], float btcToAdd)
{
	Wallet walletToReturn;

	walletToReturn.walletID = walletIDToAdd;
	walletToReturn.walletOccupied = true;
	strcpy(walletToReturn.walletUsername, usernameToAdd);
	strcpy(walletToReturn.walletPassword, passwordToAdd);
	walletToReturn.btcAmount = btcToAdd;

	return walletToReturn;
}

void DeleteWallet(Wallet walletToDelete)
{
	walletToDelete.walletOccupied = false;
	*walletToDelete.walletUsername = '\0'; // Changed from NULL to '\0' to remove warning C4047
	*walletToDelete.walletPassword = '\0'; // Same as line above
	walletToDelete.btcAmount = 0;
}

Wallet UpdateWallet(Wallet walletToUpdate, char usernameToUpdateTo[BUFFER_SIZE], char passwordToUpdateTo[BUFFER_SIZE], float btcToUpdateTo)
{
	if (usernameToUpdateTo != NULL)
	{
		strcpy(walletToUpdate.walletUsername, usernameToUpdateTo);
		printf("Username has successfully change to '%s'.", usernameToUpdateTo);
	}

	if (passwordToUpdateTo != NULL)
	{
		strcpy(walletToUpdate.walletPassword, passwordToUpdateTo);
		printf("Password has successfully change to '%s'.", passwordToUpdateTo);
	}

	if (btcToUpdateTo >= 0)
	{
		walletToUpdate.btcAmount = btcToUpdateTo;
		printf("BTC has been updated to %f.", btcToUpdateTo);
	}

	return walletToUpdate;
}