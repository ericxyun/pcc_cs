
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab 13	 : Strings
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
 *
 * STRINGS
 *
 *--------------------------------------------------------------------------
 * This program will do one of two things:
 *		1 - Take a string from the user and will split the words where 
 *          there is a uppercase.
 *		2 - This function will take a sentence and replace a word in a 
 *          sentence with another word of the user's choice.
 *--------------------------------------------------------------------------
 * INPUT:
 * 	str: user word (ex 1)
 *  str1: user sentence (ex 2)
 *  str2: user word to replace (ex 2)
 *  str3: replacement word(ex 2)
 *
 * OUTPUT:
 * 	ex1: single word turns in to sentences
 *	ex2: sentences are replaced with another word or words.
 ***************************************************************************/

// FUNCTION Prototypes
/**************************************************************************
 * wordSeparator
 *		This function will take the a string from the user and will split
 *		the words where there is a uppercase.
 ***************************************************************************/
void wordSeparator(string str,       // INPUT - user word
		           string& result);  // storing the result

/**************************************************************************
 * replaceSubString
 *		This function will take a sentence and replace a word in a sentence
 * 		with another word of the user's choice.
 ***************************************************************************/
void replaceSubString(string& str1,  // INPUT - user sentence
		              string str2,	 // INPUT - word to change
					  string str3);  // INPUT - replacement word
int main()
{
	// variable 
	int ex; 		// choosing the exercise number
	string result;  // result for ex 1 
	string str;		// INPUT - ex 1 user input
	string str1;	// INPUT - ex 2 sentence
	string str2;	// INPUT - ex 2 word to replace
	string str3; 	// INPUT - ex 2 replacement word

	// INPUT - choose exercise number 
	cout << "Which exercise?";
	cout << endl;
	cin >> ex;
	cout << endl;

	if (ex == 1)
	{
		// INPUT - get the word from user
		cout << "Enter a sentence (no spaces, 1st letter of each word is"
			 << " uppercase): " << endl;
		cout << endl;
		cin >> str;
		result = "";

		// PROCESSING - convert word
		wordSeparator(str, result);	

		// OUTPUT - outut results
		cout << result << endl;
		cout << endl;
	}
	else if (ex == 2)
	{
		// INPUT - get sentence and words from user
		cin.ignore(1000, '\n');
		cout << "Enter the main string: \n";
		std::getline(cin, str1);
		cout << "Enter the string to replace: \n";
		std::getline(cin, str2);
		cout << "Enter the replacement string: \n";
		std::getline(cin, str3);

		// PROCESSING - replace word or words
		replaceSubString(str1, str2, str3);

		// OUTPUT- output results
		cout << str1;
		cout << endl;
		cout << endl;
	}
}

/************************************************************************
 * 
 * FUNCTION wordSeparator
 * 	
 *-----------------------------------------------------------------------
 * This function will take the a string from the user and will split
 *		the words where there is a uppercase.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *	str: user input
 *  result: pass by reference storing results
 *
 * POST-CONDITIONS
 *	result is assigned to the word to output.
 *
*************************************************************************/
void wordSeparator(string str, string& result) // INPUT - user string
{
	// variables
	int count = 0; // counter to keep track of position

	// PROCESSING - adds space and lowers the capital letter
	for (int i = 0; i < str.length(); i++)
	{
		if (count > 1)	
		{
			if (isupper(str[i]))
			{
				result += ' ';
				result += tolower(str[i]);
				count++;
			}
			else
			{
				result += str[i];
				count++;
			}
		}	
		else
		{
			result +=str[i];
			count++;
		}
	}
}


/************************************************************************
 * 
 * FUNCTION replaceSubString
 * 	
 *-----------------------------------------------------------------------
 * This function will take a sentence and replace a word in a sentence
 * 		with another word of the user's choice.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		str1: user string input with getline
 *		str2: user string input with cin
 *		str3: user string input with cin
 *
 * POST-CONDITIONS
 *		This function will return the newly replaced word
 *
*************************************************************************/
void replaceSubString(string& str1, // INPUT - user sentence
		              string str2,	// INPUT - user word to replace
					  string str3)	// INPUT - word to replace
{
	// variables
	int found;	// boolean to check if found
	// PROCESSING - replaces words with user's choice
	do
	{
		found = str1.find(str2);
		if (found != std::string::npos) 
		{
			str1 = str1.replace(found, str2.length(), str3);
		}
	}
	while (found <= str1.size());

}

