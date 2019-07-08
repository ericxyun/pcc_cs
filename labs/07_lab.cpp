
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #7	 : Liters and MPG
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
 *
 * LITERS AND MPG
 *
 *--------------------------------------------------------------------------
 * This program will take in liters and miles as inputs and calculate the 
 *     miles per gallon
 *--------------------------------------------------------------------------
 * INPUT:
 *		liters
 *		miles
 *		liters1: liters for car 1
 *		liters2: liters for car 2 	
 *		miles1:  miles for car 1
 *		miles2:  miles for car 2
 *
 * OUTPUT:
 *		milesPerGallon: calculated mpg for first part
 *		mpg1:           calculated mpg for car 1	
 *		mpg2: 			calculated mpg for car 2
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/
// function calculates mpg
float mpgCalculator(float liters, float miles);

// global variables - first part
float liters;		// user input - liters
float miles;		// user input - miles


int main()
{
	// variables
	char answer;		// user input - answer
	float liters1;		// user input - liters first car
	float liters2;		// user input - liters second car
	float miles1;		// user input - miles first car
	float miles2; 		// user input - miles second car
	float mpg1;			// calculated mpg first car
	float mpg2;			// calculated mpg second car

	do
	{
		// INPUT - gets user input liters and miles
		cout << "Enter the number of liters of gas consumed: ";
		cin >> liters;
		cout << endl;
		cout << "Enter the number of miles traveled: ";
		cin >> miles;
		cout << endl;

		// PROCESSING / OUTPUT
 		// mpgCalculator - outputs the calculated mpg	
		cout << "This car gets " <<  mpgCalculator(liters, miles);
		cout << " miles per gallon." << endl;
		cout << "Calculate again? ";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

	cout << endl;
	cout << endl;

	// INPUT - second set of questions given not 'y'
	cout << "Enter the number of liters consumed for the first car: ";
	cin >> liters1;
	cout << endl;
	cout << "Enter the number of miles traveled for the first car: ";
	cin >> miles1;
	cout << endl;
	cout << "Enter the number of liters consumed for the second car: ";
	cin >> liters2;
	cout << endl;
	cout << "Enter the number of miles traveled for the second car: ";
	cin >> miles2;
	cout << endl;
	cout << endl;
	cout << endl;

	// mpgCalculator - variables for mpg of the two cars
	mpg1 = mpgCalculator(liters1, miles1);
	mpg2 = mpgCalculator(liters2, miles2);

	// OUTPUT
	cout << "The first car gets " << mpg1;
	cout << " miles per gallon." << endl;
	cout << "The second car gets " << mpg2;
	cout << " miles per gallon." << endl;
	
	if (mpg1 > mpg2)
		cout << "The first car has better gas mileage." << endl;
	else
		cout << "The second car has better gas mileage." << endl;
}

// function for calculating mpg
/**************************************************************************
 * 
 * FUNCTION mpgCalculator
 *
 *_________________________________________________________________________
 * This function takes in liters and miles and outputs a floating point
 *     miles per gallon
 *_________________________________________________________________________
 * PRE-CONDITIONS:
 *	The following ned previously defined values:
 *		liters: 
 *		miles
 * POST-CONDITIONS:
 * 	This function will output the calculated miles per gallon.
**************************************************************************/
float mpgCalculator(float liters, float miles)
{
	// variables
	float gallons;			// calculated gallons from litters
	float milesPerGallon;   // calculated miles per gallon

	// PROCESSING
	gallons = liters * 0.264179;
	milesPerGallon = miles / gallons;
	return milesPerGallon;
}
