//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// Wallet.h is responsible for all the libraries used in Wallet.c

#include "Main.h" // Basic includes, variables, defines, and functions
#pragma once

typedef struct
{
	int walletID; // To seperate from other wallets
	bool walletOccupied; // To check whether this wallet ID is occupied
	char walletUsername[BUFFER_SIZE]; // For retrieving the account
	char walletPassword[BUFFER_SIZE]; // For entering the account
	float btcAmount; // Bitcoin

} Wallet;

Wallet walletDatabase[DATABASE_SIZE];

Wallet AddWallet(int walletIDToAdd, char usernameToAdd[BUFFER_SIZE], char passwordToAdd[BUFFER_SIZE], float btcToAdd);
Wallet DeleteWallet(Wallet walletToDelete);
Wallet UpdateWallet(Wallet walletToUpdate, char usernameToUpdateTo[BUFFER_SIZE], char passwordToUpdateTo[BUFFER_SIZE], float btcToUpdateTo);

void addWalletFromMenu(Wallet* walletDatabase);
void DisplayAllWallets(Wallet* walletDatabase);
void displayOccupiedWalletsAlphabeticalByUsername(Wallet* walletDatabase);