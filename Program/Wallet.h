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
	char* walletUsername; // For retrieving the account
	char* walletPassword; // For entering the account
	float btcAmount; // Bitcoin

} Wallet;

Wallet walletDatabase[DATABASE_SIZE];

void AddWallet(Wallet walletToAdd, char* usernameToAdd, char* passwordToAdd, float btcToAdd);
void DeleteWallet(Wallet walletToDelete);
void UpdateWallet(Wallet walletToUpdate, char* usernameToUpdateTo, char* passwordToUpdateTo, float btcToUpdateTo);