//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// Wallet.c stores the basic functions of a crypto wallet

#include "Wallet.h" // This script's header file

void AddWallet(Wallet walletToAdd, char* usernameToAdd, char* passwordToAdd, float btcToAdd)
{
	walletToAdd.walletOccupied = true;
	walletToAdd.walletUsername = usernameToAdd;
	walletToAdd.walletPassword = passwordToAdd;
	walletToAdd.btcAmount = btcToAdd;
	printf("A wallet has been added with the username '%s' and password of '%s'. It contains %f BTC.", usernameToAdd, passwordToAdd, btcToAdd);
}

void DeleteWallet(Wallet walletToDelete)
{
	printf("Wallet that belongs to '%s' has been destroyed. %f BTC has been returned to the blockchain.", walletToDelete.walletUsername, walletToDelete.btcAmount);

	walletToDelete.walletOccupied = false;
	walletToDelete.walletUsername = NULL;
	walletToDelete.walletPassword = NULL;
	walletToDelete.btcAmount = 0;
}

void UpdateWallet(Wallet walletToUpdate, char* usernameToUpdateTo, char* passwordToUpdateTo, float btcToUpdateTo)
{
	if (usernameToUpdateTo != NULL)
	{
		walletToUpdate.walletUsername = usernameToUpdateTo;
		printf("Username has successfully change to '%s'.", usernameToUpdateTo);
	}

	if (passwordToUpdateTo != NULL)
	{
		walletToUpdate.walletPassword = passwordToUpdateTo;
		printf("Password has successfully change to '%s'.", passwordToUpdateTo);
	}

	if (btcToUpdateTo >= 0)
	{
		walletToUpdate.btcAmount = btcToUpdateTo;
		printf("BTC has been updated to %f.", btcToUpdateTo);
	}
}