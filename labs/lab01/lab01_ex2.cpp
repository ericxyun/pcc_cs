/***********************************************************************
	AUTHOR	 : Eric Yun
 	Lab #1	 : Part 2
 	CLASS	 : CS 002
 	SECTION  : MTRF: 7:00a - 12p
 	Due Date : June 20, 2019	
 *************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
*
*
* SUM AND AVERAGE
*
*--------------------------------------------------------------------------
* This program will take 6 inputs from the user and calculate the sum and 
*	and the average.
*
*--------------------------------------------------------------------------
* INPUT:
*	num[1-6]: floats received as input.
*
* OUPUT:
*	sum: sum of num[1-6]
*	average: average of sum
**************************************************************************/
int main()
{
	// variables
	float n1, n2, n3, n4, n5, n6, sum;
	float average;

        // output the class heading
        // cout << "***************************************************************************\n";
        // cout << "   Programmed by  : Eric Yun"      << endl;
        // cout << "   Student ID     : 00830157"      << endl;
        // cout << "   CS-002         : MTRF - 7a-10p" << endl;
        // cout << "   Lab #1         : Part 1"       << endl;
        // cout << "***************************************************************************\n";kk

	// INPUT -- get the six floats from the user
	cout << "Enter six fp numbers on a single line, separated by spaces: " <<endl;
	cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;

	// PROCESSING -- calculate the sum and the average
	sum = n1 + n2 + n3 + n4 + n5 + n6;
	average = sum / 6;

	// OUTPUT -- print out the sum and the average
	cout << "Sum of " 
	     << n1
             << " + "
	     << n2
             << " + "
	     << n3
             << " + "
	     << n4
             << " + "
	     << n5
             << " + "
	     << n6
	     << " = "
             << sum << endl;
	cout << "Average = " << average << endl;
}

