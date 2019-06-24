/*************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #1	 : Part 3
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 *************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
*
*
* TARGET HEART RATE
*
*--------------------------------------------------------------------------
* This program will take age input from the user and calculate the target
*	heart rate
*
*--------------------------------------------------------------------------
* INPUT:
*	age: integer from user input
*
* OUPUT:
*	lower: lower limit of heart rate range
*	upper: uppoer limite of heart rate range
**************************************************************************/
int main()
{
	// variables
	int age;
	double lower, upper;

	// INPUT -- gets the user's age
	cout << "What is your age: " << endl;
	cin >> age;

	// PROCESSING -- calculates the lower and upper heart rate range
	lower = (220 - age) * 0.6;
	upper = (220 - age) * 0.75;

	// OUTPUT -- prints the lower and upper heart rate range
	cout << "Your target heart rate is between "
	     << lower
	     << " and " 
	     << upper
             << " bpm." << endl;
}
