/*************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #1	 : Part 1
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 *************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
*
*
* SUM, PRODDUCT, QUOTIENT, MODULO
*
*--------------------------------------------------------------------------
* This program will take two input from the user and output the calcuated  
*	sum , product, quotient, and modulo.
*
*--------------------------------------------------------------------------
* INPUT:
*	num1: First integer received as input.
*	num2: Second integer received as input.
*
* OUPUT:
*	sum: sum of num1 and num2
*	product: product of num1 and num2
*	quotient: resulting quotient from dividing num1 by num2
*	modulo: resulting modulo from dividing num1 by num2	
**************************************************************************/

int main()
{
	
	// variables
	int num1, num2;                       // user input
	int sum, product, quotient, modulo;   // output

        // output the class heading
        // cout << "***************************************************************************\n";
        // cout << "   Programmed by  : Eric Yun"      << endl;
        // cout << "   Student ID     : 00830157"      << endl;
        // cout << "   CS-002         : MTRF - 7a-10p" << endl;
        // cout << "   Lab #1         : Part 1"       << endl;
        // cout << "***************************************************************************\n";

	// INPUT -- get the two integers from the user
	cout << "Enter the first integer: " << endl;
	cin >> num1;
	cout << "Enter the second integer: " << endl;
	cin >> num2;

	// PROCESSING -- calculates sum, product, quotient, modulo		
	sum = num1 + num2;
	product = num1 * num2;
	quotient = num1 / num2;
	modulo = num1 % num2;	

	// OUTPUT -- prints the equation and calculation
	cout << num1 << " + " << num2 << " = " << sum << endl;
	cout << num1 << " * " << num2 << " = " << product << endl;
	cout << num1 << " / " << num2 << " = " << quotient << endl;
	cout << num1 << " % " << num2 << " = " << modulo << endl;
	
	return 0;
}
