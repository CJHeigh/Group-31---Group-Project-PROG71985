//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// Wallet.h is responsible for all the libraries used in Wallet.c

#include "Main.h"
#pragma once

typedef struct
{
	char* walletID; // Random letters and numbers
	char* walletUsername;
	char* walletEmailAddress;
	float btcAmount; // Bitcoin
	float ethAmount; // Ethereum
	float adaAmount; // Cardano

} Wallet;

Wallet walletDatabase[DATABASE_SIZE];

void AddWallet();
void DeleteWallet();
void UpdateWallet();