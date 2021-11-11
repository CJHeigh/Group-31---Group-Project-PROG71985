//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// Main.c launches and exits the project, aswell as read/write

#include "Main.h" // This script's header file
#include "TxtDatabase.h" // For reading the database
#include "WalletManager.h" // For launching the menu

void main()
{
	// On start, read from the txt file and put it into memory
	ReadFromTxt();

	// Then print the start menu
	PrintMenu();
}

void Quit()
{
	// Writes memory to txt file on quit
	WriteToTxt();
}