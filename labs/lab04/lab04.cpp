/***********************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #4	 : Loops
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 27, 2019	
 **************************************************************************/
#include <iostream>
using namespace std;
/***********************************************************************
 *
 * LOOPS
 *
 *--------------------------------------------------------------------------
 * This program is broken down into three parts:
 *	1: User inputs a word and the program can tell you if there is
 *	   a "e" or "x"
 *      2: User inputs a word and the 'e', 'i', 'x', is replaced with
 *         '3', 'l', '*', respectively.
 *      3: User inputs a sentence and it can tell you the index of the
 *	   '.' and the starting index of the word 'stop'. 
 *--------------------------------------------------------------------------
 * INPUT:
 *	word: string user input
 *	sentence: string user input
 *
 * OUTPUT:
 *	prints transformed words and appropriate indexes
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/
int main ()
{
	// variables
	int ex, i;            // variable for choosing execise
	int count_e = 0;      // tracking 'e'	
	int count_x = 0;      // tracking 'x'
	int dot_idx;          // tracking '.' index
	int count_dot = 0;    // tracking '.'
	int track_stop = 0;   // tracking 'stop'
	int track_idx = 0;    // tracking 'stop' index
	int length;           // variable for word size
	string word;	      // user input 
	string sentence;      // user input

	// INPUT -- gets user input for exercise number
	cout << "Which exercise: ";
	cout << endl;
	cin >> ex;

	// Excercise 1
	if (ex == 1)
	{
		// INPUT -- gets word from user
		cout << "Enter a word: " << endl;
		cin >> word;
		
		// PROCESSING -- iterates through and finds 'e' or 'x'
		for (i = 0; i < word.size(); i++)
		{
			if (word.at(i) == 'e' && count_e == 0)	
			{ 
				count_e++;
			}	

			else if (word.at(i) == 'x' && count_x == 0)	
			{ 
				count_x++;
			}	
		}	

		// OUTPUT -- outputs whether 'e' and 'x' are in the user 
		//           input
		if (count_e > 0)
		{
			cout << "Your word " 
			     << word << " contains the character 'e'";
			cout << endl;
		}
		if (count_x > 0)
		{
			cout << "Your word " 
			     << word << " contains the character 'x'";
			cout << endl;
		}
	}

	// Excercise 2
	else if (ex == 2)
	{
		// INPUT -- gets word from user
		cout << "Enter a word: ";
		cin >> word;
		cout << "\n";
		
		// PROCESSING/OUTPUT -- replaces letters with another
		//                      character
		length = word.size();
		cout << "Your word transformed is ";
		
		for (i=0; i < length; i++)
		{
		    if (word.at(i) =='e')
			cout << '3';
		    else if (word.at(i) =='i')
			cout << '1';
		    else if (word.at(i) =='x')
			cout << "*";
		    else
			cout << word.at(i) ;
		}
		cout << "\n";
	}

	// Excercise 3
	else if (ex == 3)
	{
		// INPUT -- gets word from user
		cout << "Enter a sentence: "; 
		cout << endl;
		cin >> sentence;
		
		// PROCESSING -- tracks and find relevent indices
		for (i = 0; i < sentence.size(); i++)
		{
			if (sentence.at(i) == '.')
			{
				dot_idx = i;
				count_dot++;
			}	
			if (sentence.at(i) == 's')
			{	
				track_idx = i;
				if (sentence.at(i + 1) == 't' &&
				    sentence.at(i + 2) == 'o' &&
				    sentence.at(i + 3) == 'p')
					track_stop = 1;
			}
		}

		// OUTPUT -- prints confirmation of the presence of 
		// 	     a "." in the sentence and if so, provides
		//	     the index.
		if (count_dot > 0) {
			cout << "The character '.' is located at index " 
			     << dot_idx << endl;
		}
		else {
			cout << "Your sentence does not contain the "
			     <<	"character '.'" << endl;
		}

		if (track_stop == 1) {
			cout << "The word \"stop\" is located at index " 
			     << track_idx << endl;
		}

		else  {
			cout << "Your sentence does not contain the word "
			     << "\"stop\"" << endl;
		}
	}	
}	

