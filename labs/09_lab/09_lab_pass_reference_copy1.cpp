/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #7	 : Liters and MPG
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
/**************************************************************************
 
**************************************************************************/
float minMaxMean(string calcType);
/**************************************************************************
 
**************************************************************************/
bool checkFile();

int main()
{
	int ex;		// variable to store exercise number

	cout << "Which exercise? ";
	cin >> ex;
    cout << endl;

	if (ex == 1)
	{
        cout << "The min is: " << minMaxMean("min") << endl;
        cout << "The max is: " << minMaxMean("max") << endl;
        cout << fixed << showpoint;
        cout << setprecision(1);
        cout << "The average is: " << minMaxMean("mean") << endl;
	}
	else if (ex == 2)
	{
        if (checkFile())
        {
            cout << "The max number is: " << minMaxMean("max") << endl;
            cout << "The min number is: " << minMaxMean("min") << endl;
            cout << fixed << showpoint;
            cout << setprecision(1);
            cout << "The average is: " << minMaxMean("mean") << endl;
        }
        else
            cout << "Cannot open the file!" << endl;
	}

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
float minMaxMean(string calcType)
{
    float current;
	string line;

	// FIRST
    ifstream file("numbers.dat");
	getline(file, line);
	istringstream iss(line);
    float firstNum;
    iss >> firstNum;


    // MIN
    if (calcType == "min")
    {
        float min;
        iss >> min;
        while (getline(file, line))
        {
            stringstream iss(line);
            iss >> current;
            if (current < min)
            {
                min = current;
            }
        }
        return min;
    }

    // MAX
    else if (calcType == "max")
    {
        float max;
        iss >> max;
        while (getline(file, line))
        {
            stringstream iss(line);
            iss >> current;
            if (current > max)
            {
                max = current;
            }

        }
        return max;
    }

    // AVERAGE
    else if (calcType == "mean")
    {
        float count;
        float sum;
        float mean;

        count = 1.0;
        sum = firstNum;

        while (getline(file, line))
        {
            stringstream iss(line);
            iss >> current;
            sum += current;
            count++;
        }
        mean = sum / count;
        return mean;
    }
    else
        return 0;
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
bool checkFile()
{
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;
    cout << endl;

    ifstream file(filename);
    if (file.is_open())
    {
        return 1;
    }
    else
        return 0;


}
