/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #9	 : Functions with Pass by Reference Parameters
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
* FUNCTIONS WITH PASS BY REFERENCE PARAMETERS
*
*________________________________________________________________________
* This program has two parts: 
*      1: Reads in a file and calculates the minimum, maximum, and mean.
*      2: Checks to see if a file is opened successfully and then proceeds
*             with the first part of the fuction
*________________________________________________________________________
* INPUTS:
*     ex:       user input to choose the exercise number
*     file:     name of the file in the directory
*
* OUTPUTS:
*     min:      calculated minimum from the list of integers 
*     max:      calculated maximum from the list of integers 
*     mean:     calculated mean from the list of integers 
*     min:    
*     
*________________________________________________________________________
*************************************************************************/

/**************************************************************************
* minMaxMean 
*     This function recieves one of three string options: min, max, mean.
*         and returns, the min, max, and mean, respectively, given a file 
*         with a list of integers
**************************************************************************/
void minMaxMean(float& min, float& max, float& mean);

/**************************************************************************
* checkFile 
*     This function takes in the file name and  provides the function of
*         returning a Boolean value depending on whether a file has 
*         successfully opened or not.
**************************************************************************/
bool checkFile(string filename, float& min, float& max, float& mean);

int main()
{
    // variables
	int ex;		      // variable to store exercise number
	float min; 	      // pass by reference minimum
	float max; 	      // pass by reference maxmimum
	float mean; 	  // pass by reference average

    // INPUT -- gets user input for exercise number
	cout << "Which exercise? ";
	cin >> ex;
    cout << endl;

	if (ex == 1)
	{
		// minMaxMean - using min, max, mean as pass by reference.
		// 		changing the value of min, max, mean
		minMaxMean(min, max, mean);

        // OUTPUT - outputs the min, max, and mean
        cout << "The min is: " << min << endl;
        cout << "The max is: " << max << endl;
        cout << fixed << showpoint;
        cout << setprecision(1);
        cout << "The average is: " << mean << endl;
	}

	else if (ex == 2)
	{
		string filename;      // INPUT - stores the file name.

		// INPUT - get the name of the file from user
		cout << "Enter the name of the file: ";
		cin >> filename;
		cout << endl;

        // checkFile - checks to see if file is successfully opened
        if (checkFile(filename, min, max, mean))
        {
            // OUTPUT - outpus the min, max and mean
            cout << "The max number is: " << max << endl;
            cout << "The min number is: " << min << endl;
            cout << fixed << showpoint;
            cout << setprecision(1);
            cout << "The average is: " << mean << endl;
        }
        else
            cout << "Cannot open the file!" << endl;
	}

}
/************************************************************************
 * 
 * FUNCTION minMaxMean
 * 	
 *-----------------------------------------------------------------------
 * This function recieves one of three string options: min, max, 
 *     mean and returns, the min, max, and mean, respectively, given 
 *     a file with a list of integers
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *     The following need previously defined values:
 *         calcType: string option for calculation
 *             Options:
 *                 - min: calculates the min
 *                 - max: calculates the max
 *                 - mean: calculates the mean
 *
 * POST-CONDITIONS
 *     This function will return the values of either the minimum, 
 *         maximum, or mean, depending on the parameter selection
*************************************************************************/
void minMaxMean(float& min, float& max, float& mean)
{
    float current;                    // the current value in the list
	float count;                 	  // counts the number of lines
	int sum;                          // accumulates the sum
	string line;                      // the string value of the list
    ifstream file("numbers.dat");     // opening the file


	// initializing variables for mean
	count = 0;
	sum = 0;

	while (getline(file, line))
	{
		istringstream iss(line);
		iss >> current;
	// PROCESSING - calculates the minimum
		if (current < min)
			min = current;
	// PROCESSING - calculates the maximum
		if (current > max)
			max = current;
	// PROCESSING - accumulates the sum and calculates the mean
		sum += current;
		count++;
	}
	mean = sum / count;

}
/************************************************************************
 * 
 * FUNCTION checkFile
 * 	
 *-----------------------------------------------------------------------
 * This function does not recieve any input but provides the function of
 *     returning a Boolean value depending on whether a file has 
 *     successfully opened or not.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *     filename: user input file name.
 *
 * POST-CONDITIONS
 *     This function will output a Boolean value:
 *          1: file is opened successfully
 *          2: fill opening is not successful.
 *
*************************************************************************/
bool checkFile(string filename, float& min, float& max, float& mean)
{
    float current;              // the current value in the list
	float count;                // counts the number of lines
	float sum;                  // accumulates the sum
	string line;                // the string value of the list
    ifstream file(filename);    // opening the file

	// PROCESSING - check if file has opened successfully
    if (file.is_open())
    {
		// initializing variables for mean
		count = 0;
		sum = 0;

		while (getline(file, line))
		{
			istringstream iss(line);
			iss >> current;
		// PROCESSING - calculates the minimum
			if (current < min)
				min = current;
		// PROCESSING - calculates the maximum
			if (current > max)
				max = current;
		// PROCESSING - accumulates the sum and calculates the mean
			sum += current;
			count++;
		}
		mean = sum / count;
        return 1;
    }
    else
        return 0;
}
