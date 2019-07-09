/************************************************************************
* AUTHOR       : Eric Yun
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

/************************************************************************
 * setupUnsolved
 *      This function receives the user input phrase as an input and 
 *      	converts then letters into '-'
*************************************************************************/
string setupUnsolved(string phrase);

/************************************************************************
 * updateUnsolved
 *     This function recieves the phrase, unsolved string from the 
 *         setupUnsolved function, and the user input guess and returns 
 *         an update version th:e of dashed phrase that has been replaced
 *         by the correct guesses.
*************************************************************************/
string updateUnsolved(string phrase, string unsolved, char guess);

/************************************************************************
 * getGuess
 *     This function gets a single character guess from the user and 
 *         outputs that input
*************************************************************************/
char getGuess(string prevGuesses);

/************************************************************************
 * correctLetter
 *      This function takes in the phrase and guess from the user input
 * 			and return a Boolean value. 0 if guess is not in phrase and 
 * 			1 otherwise.
 *         
*************************************************************************/
bool correctLetter(string phrase, char guess);

/************************************************************************
 * unsolvedLeft
 * 		This function takes in the unsolved dashes and counts the number 
 * 			of dashes and returns an integer. This is to be used to know 
 * 			when all letters are correctly guessed.
 *
*************************************************************************/
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

        if (!correctLetter(phrase, guess))
            guessLeft -= 1;
        // cout << "Phrase: " + unsolved;
        // cout << endl;
        cout << "Guessed so far: " << prevGuesses << endl;
        cout << "Wrong guesses left: " << guessLeft << endl;
        cout << unsolved << endl;
        cout << endl;

            
    }

    // OUTPUT - when the player loses
    if (guessLeft == 0)
        cout << "You lost!" << endl;

    // OUTPUT - when the player wins
    else
        cout << "Congratulations!! You won!" << endl;
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

    // PROCESSING - checks for alpha and creates '-' phrase
    //      replaces with '-' if isaplha() is true
    for (int i = 0; i < phrase.size(); i++)
    {
        if (isalpha(phrase.at(i)))
            unsolved += '-';
        else
            unsolved += phrase.at(i);
    }
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
    // PROCESSING - replaces '-' with correct guess
    for (int i = 0; i < phrase.size(); i++) 
    {
        if (tolower(guess) == tolower(phrase.at(i)))
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
    while (!alpha || duplicateFound != -1 || !islower(guess))
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

    // PROCESSING - checks to see if guess is in phrase
    //     will convert both guess and phrase letter to lower before 
    //     comparing.
    for (int i = 0; i < phrase.size(); i++)
        phrase.at(i) = tolower(phrase.at(i));
    if (phrase.find(tolower(guess)) == -1)
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

    // initialize '-' counter
    count = 0;

    // PROCESSING - goes through letter and count '-'
    for (int i = 0; i < unsolved.size(); i++)
        if (unsolved.at(i) == '-')
            count += 1;
    return count;
}

