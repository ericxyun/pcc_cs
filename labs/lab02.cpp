/*************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #2	 : ISBN Checksum	
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 21, 2019	
 *************************************************************************/
#include <iostream>
using namespace std;
/**************************************************************************
*
*
* ISBN CHECKSUM
*
*--------------------------------------------------------------------------
* This program will take the first nine digits of a user's ISBN and will
*	generate a checksum number
*
*--------------------------------------------------------------------------
* INPUT:
*	num[1-9]: First nine digits of user's ISBN
*
* OUPUT:
*	checksum: calculated checksum using the user input
**************************************************************************/
int main()
{
	int ex;
	cout << "Which exercise? ";
	cin >> ex;
	cout << endl;
	if (ex==1)
	{
		// variables
		int isbn;
		int n1, n2, n3, n4, n5, n6, n7, n8, n9, wsum, checksum;
		
		// INPUT -- gets 9 user inputs
		cout << "Please enter the first 9 digits of the ISBN: " << endl;
		cin >> isbn;
		n1 = isbn / 100000000 % 10;	// first digit
		n2 = isbn / 10000000  % 10;	// second digit
		n3 = isbn / 1000000   % 10;	// third digit
		n4 = isbn / 100000    % 10;	// fourth digit
		n5 = isbn / 10000     % 10;	// fifth digit
		n6 = isbn / 1000      % 10; 	// sixth digit
		n7 = isbn / 100       % 10;	// seventh digit
		n8 = isbn / 10        % 10;	// eigth digit
		n9 = isbn / 1	      % 10;	// ninth digit

		// PROCESSING -- calculates the weighted sum and checksum
		wsum = 1*n1 + 2*n2 + 3*n3 + 4*n4 + 5*n5 + 6*n6 + 7*n7 + 8*n8 + 9*n9;
		checksum = wsum % 11;

		// OUTPUT -- prints the checksum
		cout << "Checksum: " << checksum << endl;
		
	}
	else if (ex==2)
	{
		// variables
		char letter;
		
		// INPUT -- get a character input from the user
		cout << "Enter a character: " << endl;
		cin >> letter;

		// OUTPUT -- outputs the decimal version of the input
		cout << letter << " is letter " << letter - 'a' + 1 << endl;
		
	}
}
	
