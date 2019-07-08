/************************************************************************
* AUTHOR       : Eric 
* ASSIGNMENT 6 : Hangman
* CLASS        : CS002
* SECTION      : MTRF 7am-12pm 
* DUE DATE     : July 7, 2019
*************************************************************************/
#include <iostream>
using namespace std;
/************************************************************************
* 
* HANGMAN
*
*________________________________________________________________________
* This program simulates the game of hangman
*________________________________________________________________________
* INPUTS:
*     phrase:       phrase to be solved
*     guess:        single character guess
*
* OUTPUTS:
*     unsolved:     correctly guessed so far
*     prevGuesses:  guesses attempted so far
*     guessLeft:    number of guesses left
*________________________________________________________________________
*************************************************************************/

// setupUnsolved function prototype
string setupUnsolved(string phrase);

// updateUnsolved function prototype
string updateUnsolved(string phrase, string unsolved, char guess);

// getGuess function prototype
char getGuess(string prevGuesses);

// correctLetter function prototype
bool correctLetter(string phrase, char guess);

// unsolvedLeft function prototype
int unsolvedLeft(string unsolved);


int main()
{
    char guess;            // INPUT - single character to guess
    int guessLeft;         // number of guesses left
    string phrase;         // INPUT - phrase to be guessed
    string unsolved;       // correctly guess so far
    string prevGuesses;    // accumulating guess attemps

    // INPUT - get the phrase to be guessed
    cout << "Enter phrase: ";
    getline(cin, phrase);
    cout << endl;

    // PROCESSING - print number of dashes equal to amount of letters
    unsolved = setupUnsolved(phrase);
    cout << "Phrase: " + unsolved << endl;
    cout << endl;

    // initilize number of max number of incorrect guesses
    guessLeft = 7;

    // initialize accumulating guess attempts
    prevGuesses = "";

    // PROCESSING - loop for gameplay
    while (guessLeft >= 0 && unsolvedLeft(unsolved) > 0) 
    {
        guess = getGuess(prevGuesses);
        prevGuesses += guess;

        unsolved = updateUnsolved(phrase, unsolved, guess);
        cout << "Phrase: " + unsolved;
        cout << endl;
        cout << "Guessed so far: " << prevGuesses << endl;
        cout << "Wrong guesses left: " << guessLeft << endl;
        cout << endl;

        if (!correctLetter(phrase, guess))
            guessLeft -= 1;
            
    }

    // OUTPUT - when the player loses
    if (guessLeft == 0)
        cout << "You lost!" << endl;

    // OUTPUT - when the player wins
    else
        cout << "Congratulations!!" << endl;
}


/************************************************************************
 *
 * FUNCTION setupUnsolved
 *
 *-----------------------------------------------------------------------
 * 	This function takes the phrase and prints x number of daashes.
 * 	    x = number of letters.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *     The following need previously defined values:
 *         phrase: string user input 
 *
 * POST-CONDITIONS
 *     This function will output dashes equivalent to the number of 
 *         letters in the phrase
*************************************************************************/
string setupUnsolved(string phrase)             // user input
{
    string unsolved;         // variable for dashed output 
    unsolved = string(phrase.size(), '-');
    return unsolved; 
}

/************************************************************************
 * 
 * FUNCTION updateUnsolved
 * 	
 *-----------------------------------------------------------------------
 * 	This function converts the dashed output from setupUnsolved and 
 * 	    replaces the dash with the correctly guessed letters
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *     The following need previously defined values:
 *         phrase:   string user input 
 *         unsolved: output from function setupUnsolved
 *         guess:    user input character
 *
 * POST-CONDITIONS
 *     This fuction will output the result of replaced the dashed phrase
 *          with the correctly guessed letter
*************************************************************************/
string updateUnsolved(string phrase,            // user input
                      string unsolved,          // output from 
                                                // setupUnsolved
                      char guess)               // user input character
{
    for (int i = 0; i < phrase.size(); i++) 
    {
        if (guess == phrase.at(i))
            unsolved.at(i) = phrase.at(i);
    }
    return unsolved;
}

/************************************************************************
 * 
 * FUNCTION getGuess
 * 	
 *-----------------------------------------------------------------------
 * 	This function gets the single character guess from the user 
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *     The following need previously defined values:
 *         prevGuesses: accumulating guess attempts
 *
 * POST-CONDITIONS
 *     This function will output the accumulating guess attempts made
 *         by the user
*************************************************************************/
char getGuess(string prevGuesses)                // guess attempts
{
    char guess;               // user input guess
    int duplicateFound;       // checking for duplicates
    bool alpha;               // checking for alpha characters

    // INPUT - get the user input character
    cout << "Enter a guess: ";
    cin >> guess;
    cout << endl;

    // PROCESSING - check to see if:
    //                  - guess is a alphabet character
    //                  - guess is not already guessed.
    duplicateFound = prevGuesses.find(guess);
    alpha = isalpha(guess);
    while (!alpha || duplicateFound != -1)
    {
        cout << "Invalid guess! Please re-enter a guess: ";
        cin >> guess;
        cout << endl;
        duplicateFound = prevGuesses.find(guess);
        alpha = isalpha(guess);
    }
    return guess;

}
    
/************************************************************************
 * 
 * FUNCTION correctLetter
 * 	
 *-----------------------------------------------------------------------
 * 	This function checks to see if the guessed letter is in the phrase
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *     The following need previously defined values:
 *         phrase:   string user input 
 *         guess:    user input character
 *
 * POST-CONDITIONS
 *     This function will output true or flase depending on whether
 *          the guessed character is in the phrase.
*************************************************************************/
bool correctLetter(string phrase,               // user input string
                   char guess)                  // user guess letter
{
    if (phrase.find(guess) == -1)
        return false;
    else 
        return true;
}

/************************************************************************
 * 
 * FUNCTION unsolvedLeft
 * 	
 *-----------------------------------------------------------------------
 * 	This function counts the number of dashes in the unsolved variable
 * 	    and is used to track whether all letters were guessed correctly.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *     The following need previously defined values:
 *         unsolved: output from function setupUnsolved
 *
 * POST-CONDITIONS
 *      This function will output the number of dash characters in the 
 *          unsolved phrase
*************************************************************************/
int unsolvedLeft(string unsolved)              // output from 
                                               // setupUnsolved
{
    int count;       // track the number of dashed characters
    count = 0;
    for (int i = 0; i < unsolved.size(); i++)
        if (unsolved.at(i) == '-')
            count += 1;
    return count;
}

