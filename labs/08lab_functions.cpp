/************************************************************************
* AUTHOR       : Eric Yun
* ASSIGNMENT 6 : Hangman
* CLASS        : CS002
* SECTION      : MTRF 7am-12pm 
* DUE DATE     : July 7, 2019
*************************************************************************/
#include <iostream>
#include <cmath>
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
using namespace std;

// isPrime function prototype

int SumDigits(int digits);
bool isPrime(int num);

int main()
{
	int ex;
	int digits;
	cout << "Which exercise? ";
	cin >> ex;
	cout << endl;

	if (ex == 1)
	{
		do
		{
		cout << "Please enter an integer (0 to quit): ";
		cout << endl;
		cin >> digits;
		SumDigits(digits);
		cout << endl;
		} 
		while (digits != 0);
	}
	else if (ex==2)
	{
		int num1;
		int num2;
		cout << "Please input two positive numbers: ";
		cout << endl;
		cin >> num1 >> num2;
		cout << "The prime numbers between "
			 << num1 << " and " << num2 << " are: " << endl;
		int count = 0;

		for (int i = num1; i <= num2; i++)
		{
				if (isPrime(i))
				{
					cout << i << "\t";
					count++;
				}
				if (count == 8)
				{
					cout << "\n";
					count = 0;
				}
		}
		cout << endl;
	}


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
int SumDigits(int digits)
{

	int n;
	int count;
	int num;
	int sum;
	int digitsCopy;
	n = digits;

	count = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
		++count;
	}

	sum = 0;
	digitsCopy = digits;
	if  (digits != 0)
	{
		if (digits < 0)
			digits = digits * -1;

		for (int i = count - 1; i >= 0; i--)
		{
			num = digits / pow(10, i);
			num = num % 10;
			sum += num;
		}
		cout << "The sum of the digits of " << digitsCopy 
			 << " is " << sum;
	}
	else
		cout << "Goodbye ";

	return num;
}

bool isPrime(int num)
{
	bool isprime;
	isprime = true;
	if (num != 2 && num % 2 == 0)
	{
		isprime = false;
		return isprime;
	}
	else
	{
		for (int i = 3; i < num/2; i+=2)
		{
			if (num % i == 0)
			{
				isprime = false;
				return isprime;
			}
		}

		return isprime;
	}
}	
