
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab 12	 : cStrings
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
/**************************************************************************
 *
 * CSTRINGS
 *
 *--------------------------------------------------------------------------
 *  This program will take in user input as as cstrings and perform various
 *		manipulations and calculations:
 * 		- count the number of vowels
 *		- count the number of consonants
 *		- convert the string to uppercase
 *		- convert the string to lowercase
 * 		- display current state of the string
 *--------------------------------------------------------------------------
 * INPUT:
 *		- userOption: user input character to select choice
 *		- userString: user input string
 *
 * OUTPUT:
 * 		- vowel count
 *		- consonant count
 *		- lowercase converted
 *		- uppercase converted
 *		- display string as is
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

// FUNCTION Prototypes
/**************************************************************************
 * displayOptions
 * 		This function will print the current state of the string
 ***************************************************************************/
void displayOptions();

/**************************************************************************
 * selectOption
 * 		This function will take in the user input character for menu choice
 *		selection
 ***************************************************************************/
char selectOption();

/**************************************************************************
 * countVowels
 * 		This function will count the number of vowels in the string
 ***************************************************************************/
int countVowels(char userString[]);	 // INPUT - user cstring

/**************************************************************************
 * countConsonants
 * 		This function will count the number of consonants in the string	
 ***************************************************************************/
int countConsonants(char userString[]);	 // INPUT - user cstring

/**************************************************************************
 * convertToUpper
 * 		This function will convert the current state of the string to all
 *		uppercase letters
 ***************************************************************************/
void convertToUpper(char userString[]);	 // INPUT - user cstring

/**************************************************************************
 * convertToLower
 * 		This function will convert the current state of the string to all
 *		lowercase letters
 ***************************************************************************/
void convertToLower(char userString[]);	 // INPUT - user cstring

/**************************************************************************
 * displayString
 * 		This function will print the current state of the sting.
 ***************************************************************************/
void displayString(char userString[]);	 // INPUT - user cstring

/**************************************************************************
 * requestString
 * 		This function will ask user for a new input string.
 ***************************************************************************/
void requestString(char userString[]);	 // INPUT - user cstring


int main()
{
	// variables
	char userString[100]; 	// INPUT - user string input
	char userOption;		// INPUT - user character input

	// INPUT - gets the string from the user
	cout << "Input a line of text, up to 100 characters: \n";
	cin.getline(userString, 100);
	displayOptions();
	userOption = selectOption();

	// PROCESSING - performs functions depending on character selection
	while (userOption != 'x')
	{
		// counts vowels
		if (userOption == 'a')
		{
			countVowels(userString);

		}
		
		// counts consonants
		else if (userOption == 'b')
		{
			countConsonants(userString);
		}
		
		// converts to upper
		else if (userOption == 'c')
		{
			convertToUpper(userString);
		}

		// converts to lower
		else if (userOption == 'd')
		{
			convertToLower(userString);
		}
		
		// displays string
		else if (userOption == 'e')
		{
			displayString(userString);
		}

		// gets new string from user
		else if (userOption == 'f')
		{
			cout << "Input a new line of text, up to 100 characters: \n";
			cin.ignore(1000, '\n');
			cin.getline(userString, 100);
		}

		// displays the options
		else if (userOption == 'm')
		{
			displayOptions();
		}

		userOption = selectOption();
	}
}


/************************************************************************
 * 
 * FUNCTION selectOption
 * 	
 *-----------------------------------------------------------------------
 * This function will count the number of vowels in the string
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		userOption: character input
 *
 * POST-CONDITIONS
 *		returns a single character
 *
*************************************************************************/
char selectOption()
{
	char userOption;
	cout << "Enter your menu selection: ";
	cin >> userOption;
	cout << endl;
	return tolower(userOption);
}

/************************************************************************
 * 
 * FUNCTION selectOption
 * 	
 *-----------------------------------------------------------------------
 * This function will count the number of vowels in the string
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		none
 *
 * POST-CONDITIONS
 *		display options to choose from
 *
*************************************************************************/
void displayOptions()
{
	cout << "A)  Count the number of vowels in the string" << endl;
	cout << "B)  Count the number of consonants in the string" << endl;
	cout << "C)  Convert the string to uppercase" << endl;
	cout << "D)  Convert the string to lowercase" << endl;
	cout << "E)  Display the current string" << endl;
	cout << "F)  Enter another string" << endl;
	cout << endl;
	cout << "M)  Display this menu" << endl;
	cout << "X)  Exit the program" << endl;
	cout << endl;
}

/************************************************************************
 * 
 * FUNCTION countVowels
 * 	
 *-----------------------------------------------------------------------
 * This function will count the number of consonants in the string	
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		userString: declared cstring
 *
 * POST-CONDITIONS
 *		returns the total number of vowels in the string
 *
*************************************************************************/
int countVowels(char userString[])	 // INPUT - user cstring
{
	// variables
	int count = 0; 			// counter for cstring
	int vowelCount = 0;		// counter for vowels

	// PROCESSING - converts to lowercase
	while (userString[count] != '\0')
	{
		if ((tolower(userString[count]) == 'a') ||
		    (tolower(userString[count]) == 'e') ||
		    (tolower(userString[count]) == 'i') ||
		    (tolower(userString[count]) == 'o') ||
		    (tolower(userString[count]) == 'u')) 
			vowelCount++;
		count++;
	}
	
	// OUTPUT - prints number of vowels
	cout << "Number of vowels: " << vowelCount << endl;
	cout << endl;
	return vowelCount;
}

/************************************************************************
 * 
 * FUNCTION countConsonants
 * 	
 *-----------------------------------------------------------------------
 * This function will count the number of consonants in the string
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		userString: declared cstring
 *
 * POST-CONDITIONS
 *		returns the total number of consonants in the string
 *
*************************************************************************/
int countConsonants(char userString[])	 // INPUT - user cstring
{
	// variables
	int count = 0; 		// counter for cstring
	int conCount = 0; 	// count for consonant

	// PROCESSING - counts the number of vowels
	while (userString[count] != '\0')
	{
		if ((tolower(userString[count]) != 'a') &&
		    (tolower(userString[count]) != 'e') &&
		    (tolower(userString[count]) != 'i') &&
		    (tolower(userString[count]) != 'o') &&
		    (tolower(userString[count]) != 'u') &&
			isalpha(userString[count]))
			conCount++;
		count++;
	}

	// OUTPUT - prints the number of consonants
	cout << "Number of consonants: " << conCount << endl;
	cout << endl;
	return conCount;
}

/************************************************************************
 * 
 * FUNCTION convertToUpper
 * 	
 *-----------------------------------------------------------------------
 * This function will convert the strings to all uppercase.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		userString: declared userString
 *
 * POST-CONDITIONS
 *		userString is converted to uppercase
 *
*************************************************************************/
void convertToUpper(char userString[])	 // INPUT - user cstring
{
	// initialize counter for cstring
	int count = 0;
	
	// PROCESSING - converts to upper
	while (userString[count] != '\0')
	{
		userString[count] = toupper(userString[count]);
		count++;
	}
}

/************************************************************************
 * 
 * FUNCTION converToLower
 * 	
 *-----------------------------------------------------------------------
 * This function will convert the strings to all lowercase.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		userString: declared cstring
 *
 * POST-CONDITIONS
 *		userString is converted to lowercase
*************************************************************************/
void convertToLower(char userString[])	 // INPUT - user cstring
{
	// initialize counter for cstring
	int count = 0;

	// PROCESSING - converts to lowercase
	while (userString[count] != '\0')
	{
		userString[count] = tolower(userString[count]);
		count++;
	}
}

/************************************************************************
 * 
 * FUNCTION displayString
 * 	
 *-----------------------------------------------------------------------
 * This function will display the current state of the string
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		userString: declared cstring
 *
 * POST-CONDITIONS
 *		prints the current state of userString
 *
*************************************************************************/
void displayString(char userString[])	 // INPUT - user cstring
{
	// initialize counter for cstring
	int count = 0;
	
	// OUTPUT - prints string
	while (userString[count] != '\0')
	{
		cout << userString[count];
		count++;
	}
	cout << endl;
	cout << endl;
}

/************************************************************************
 * 
 * FUNCTION requestString
 * 	
 *-----------------------------------------------------------------------
 * This function will ask user for a new string input
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		userString: declared cstring
 *
 * POST-CONDITIONS
 *		changes userString to value of the new input
 *
*************************************************************************/
void requestString(char userString[])	 // INPUT - user cstring
{
	// INPUT - get the new string from the user
 	cout << "Enter a line of text: ";
 	cin.getline(userString, 100);
 	cout << userString << endl;
}
