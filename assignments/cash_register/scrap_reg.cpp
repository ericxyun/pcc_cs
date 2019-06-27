/*************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #1	 : Part 1
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 *************************************************************************/
#include <iostream>
#include <iomanip>
/**************************************************************************
*
*
* CASH REGISTER
*
*--------------------------------------------------------------------------
* This program will calculate the amount of each coins needed as change for
* 	an item purchased	
*
*--------------------------------------------------------------------------
* INPUT:
*	purchased: Floating point of cost of item.
*	recieved: Floating point amount paid.
*
* OUPUT:
*	change: Floating point recieved minus purchased.
*	dollars: Number of dollar bills needed as change.
*	quarters: Number of quarters needed as change.
*	dimes: Number of dimes needed as change.
*	nickels: Number of nickels needed as change.
*	pennies	: Number of pennies needed as change.
*	
**************************************************************************/
using namespace std;

// function to calculate change and number of coins needed.
int calc_change(double change)
{
	// variables
	int dollars = 0;
	int cents = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies= 0;

	// PROCESSING
	dollars = static_cast<int>(change);			// the the dollar amount
	cents = (change - dollars) * 100;
	cout << "Change: " << cents << endl;
	while (cents >= 25)
	{
		cents = cents - 25;
		quarters ++;
	}
	while (cents >= 10)
	{
		cents = cents - 10;
		dimes ++;
	}
	while (cents >= 5)
	{
		cents = cents - 5;
		nickels ++;
	}
	while (cents >= 1)
	{
		cents = cents - 1;
		pennies ++;
	}
	
	// OUTPUT -- prints the coins needed.
	cout << endl;
	cout << "dollars "  << dollars  << endl;
	cout << "quarters " << quarters << endl; 
	cout << "dimes "    << dimes    << endl;
	cout << "nickels "  << nickels  << endl;
	cout << "pennies "  << pennies  << endl;

	return 0;
}

int main()
{
	// variables
	fixed;
	setprecision(2);
	double purchase, received, change;
	int dollars = 0;
	int cents = 0;
	cout.precision(2);

        // output the class heading
        // cout << "***************************************************************************\n";
        // cout << "   Programmed by  : Eric Yun"      << endl;
        // cout << "   Student ID     : 00830157"      << endl;
        // cout << "   CS-002         : MTRF - 7a-10p" << endl;
        // cout << "   Assignment     : Cash Register" << endl;
	// cout << "***************************************************************************\n";

	// INPUT -- get the purchsed amount and the amount received
	cout << "Enter purchase amount: ";
	cin >> purchase;
	cout << endl;
	cout << "Enter amount received: ";
	cin >> received;
	cout << endl;

	// PROCESSING -- calculate the change from the two inputs
	change = received - purchase;

	// OUTPUT -- prints totals change the number of each coins needed to make up the change.
	if (change >= 0)	// conditional for normal inputs
	{
		cout << "Total Change: $" << change << endl;
		calc_change(change);
	}
	else			// condition if received is less than purchase
	{
		change = change * -1;
		cout << "You owe: $" << change << endl;
		calc_change(change);
	}
	
	return 0;
}
