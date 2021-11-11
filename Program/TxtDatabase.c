//////////////////////////
//      PROG71985       //
//      GROUP 31		//
//////////////////////////

// TxtDatabase.c is responsible for reading and writing to TxtDatabase.txt

#include "TxtDatabase.h" // This script's header file
#include "Wallet.h" // For writing to the wallet

void ReadFromTxt()
{
	// Opens the disk wallet database to add new lines to it (if needed)
	FILE* txtDatabaseToWrite = fopen(DATABASE_NAME, "a+");
	if (txtDatabaseToWrite == NULL)
	{
		printf("Invalid wallet database file '%s'. Exiting program...", DATABASE_NAME);
		exit(0);
	}

	int currentChar = 0;
	int linesInFile = 1;
	// Count lines in the txt file
	while ((currentChar = fgetc(txtDatabaseToWrite)) != EOF)
		if (currentChar == '\n')
			linesInFile++;

	int linesToAdd = DATABASE_SIZE - linesInFile;
	// Add any missing lines
	while (linesToAdd > 0)
	{
		fprintf(txtDatabaseToWrite, "\n");
		linesToAdd--;
	}

	// Closes for editing and opens for reading
	fclose(txtDatabaseToWrite);
	FILE* txtDatabaseToRead = fopen(DATABASE_NAME, "r");

	// For each index in the memory database,
	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		int lineNumber = 0;
		char currentLine[BUFFER_SIZE];

		// Search every line in the txt database
		while (!feof(txtDatabaseToRead))
		{
			// If the line number is equal to the index of the database,
			if (i == lineNumber)
			{
				fgets(currentLine, sizeof(currentLine), txtDatabaseToRead);
				// Retrieve data from the current line if the current line is not purely equal to a new line or end of file
				if (strcmp(currentLine, "\n") != 0 && strcmp(currentLine, "\0") != 0) //&& currentLine != "")
				{
					char walletUsername[BUFFER_SIZE] = "";
					char walletPassword[BUFFER_SIZE] = "";
					char btcAmount[BUFFER_SIZE] = "";

					int semiColonsPassed = 0;
					for (int s = 0; s < sizeof(currentLine); s++)
					{
						if (semiColonsPassed == 0)
							strncat(walletUsername, &currentLine[s], 1);
						else if (semiColonsPassed == 1)
							strncat(walletPassword, &currentLine[s], 1);
						else if (semiColonsPassed == 2)
							strncat(btcAmount, &currentLine[s], 1);
					}

					walletDatabase[i].walletUsername = walletUsername;
					walletDatabase[i].walletPassword = walletPassword;
					walletDatabase[i].btcAmount = atof(btcAmount);
					walletDatabase[i].walletOccupied = true;
				}
				else
				{
					walletDatabase[i].walletOccupied = false;
				}

				walletDatabase[i].walletID = i + 1;
				//currentLine = "";

				break;
			}

			lineNumber++;
		}
	}

	fclose(txtDatabaseToRead);
}

void WriteToTxt()
{
	// Attempts to open txt database to put memory data into
	FILE* txtDatabaseToWrite = fopen(DATABASE_NAME, "w");
	// If it doesn't exist anymore, exit the program
	if (txtDatabaseToWrite == NULL)
	{
		printf("Wallet database file '%s' is no longer valid. Exiting program...", DATABASE_NAME);
		exit(0);
	}

	// Assigns the current room name to txt file
	for (int i = 0; i < DATABASE_SIZE; i++)
	{
		if (walletDatabase[i].walletOccupied)
		{
			fprintf(txtDatabaseToWrite, "%s;%s;%f", walletDatabase[i].walletUsername, walletDatabase[i].walletPassword, walletDatabase[i].btcAmount);

			if (i < DATABASE_SIZE - 1)
				fprintf(txtDatabaseToWrite, "\n");
		}
		// If the line doesn't exist, add one
		else
		{
			if (i < DATABASE_SIZE - 1)
				fprintf(txtDatabaseToWrite, "\n");
		}
	}

	fclose(txtDatabaseToWrite);
}