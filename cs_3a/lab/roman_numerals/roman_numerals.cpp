/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #	 : Roman Numerals
 *	CLASS	 : CS 3A
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
using namespace std;

/**************************************************************************
 *
 * ROMAN NUMERALS 
 *
 *--------------------------------------------------------------------------
 * This program will convert roman numerals into decimal digits and vice 
 * 		versa
 *--------------------------------------------------------------------------
 * INPUT:
 * 		menu_selection: select conversion type	
 * 		n             : user digit input
 *		str           : user string input
 * OUTPUT:
 * 		digit_result: resulting roman numeral conversion
 * 		roman_result: resulting digit conversion
 *
 ***************************************************************************/

// FUNCTION Prototypes
/**************************************************************************
 * roman_digit
 * 		This converts will take the user input digit and convert it into
 * 		roman numerals
 *
 ***************************************************************************/
string roman_digit(int n,			// user input
		           string one,		// roman number containing 1
				   string five, 	// roman number containing 5
				   string ten);		// roman number containing 10


/**************************************************************************
 * convert_digit
 * 		This function will take a single digit from the user input and 
 * 		convert it into a roman numeral digit
 *
 ***************************************************************************/
string convert_digit(int n,						// digit from input
				     string &roman_ones,		// roman ones digit
				     string &roman_tens,		// roman tens digit
				     string &roman_hundreds,	// roman hundreds digit
				     string &roman_thousands);	// roman thousands digit

/**************************************************************************
 * digit_roman 
 * 		This function will take in a user input string as a parameter and 
 * 		will convert it into decimal digits.
 *
 ***************************************************************************/
int digit_roman(string str);	// user input string

/**************************************************************************
 * convert_roman
 * 		This function will take in a single character from the user input
 * 		string and convert return a converted decimal digit.
 *
 ***************************************************************************/
int convert_roman(char c);		// character from user input string

int main()
{
	char menu_selection;		// input for conversion type
	int input_int;				// integer input
	int count;					// counter
	int digit_result;			// result for roman to digit
	string roman_result;		// result for digit to roman
	string input_str;			// user input string
	string roman_ones;			// roman ones digit
	string roman_tens;			// roman tens digit
	string roman_hundreds;		// roman hundreds digit
	string roman_thousands;		// roman thousands digit

	// INPUT - select conversion type	
	do 
	{
		cout << "a. Decimal to Roman" << endl;
		cout << "b. Roman to Decimal" << endl;
		cout << "Pick one: " << endl;
		cin >> menu_selection;
		cout << endl;
	}

	while ((menu_selection != 'a') && (menu_selection != 'b'));

	// PROCESSING - Decimal to roman conversion
	if (menu_selection == 'a')
	{
		cout << "Input an integer less than 4000: " << endl;
		cin >> input_int;
		roman_result = convert_digit(input_int,
				                     roman_ones,
									 roman_tens,
									 roman_hundreds,
									 roman_thousands);
		cout << roman_result << endl;
	}

	// PROCESSING - Roman to decimal conversion
	else if (menu_selection == 'b')
	{
		cout << "Input a roman digit: ";
		cin >> input_str;
		digit_result = digit_roman(input_str);
		cout << digit_result << endl;

	}

	
}


/************************************************************************
 * 
 * FUNCTION convert_roman
 * 	
 *-----------------------------------------------------------------------
 * This function will take in a single character from the user input
 * 		string and convert return a converted decimal digit.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Converts the inputed character into an integer
 *
*************************************************************************/
int convert_roman(char c)	// single character from user input string
{
    if (c == 'I') 
        return 1; 
    else if (c == 'V') 
        return 5; 
    else if (c == 'X') 
        return 10; 
    else if (c == 'L') 
        return 50; 
    else if (c == 'C') 
        return 100; 
    else if (c == 'D') 
        return 500; 
    else if (c == 'M') 
        return 1000; 
	return -1;
}

/************************************************************************
 * 
 * FUNCTION digit_roman
 * 	
 *-----------------------------------------------------------------------
 * This function will take in a user input string as a parameter and 
 * 		will convert it into decimal digits.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 *		Returns the converted decimal integer 		
 *
*************************************************************************/
int digit_roman(string str)
{
	int result;		// converted digit
	int current;	// current digit in for loop
	int next;		// subsequent digit in for loop

	result = 0;

	for (int i = 0; i < str.length(); i++)
	{
		current = convert_roman(str[i]);
		if (i + 1 < str.length())
		{
			next = convert_roman(str[i+1]);
			if (current >= next)
			{
				result = result + current;
			}
			else
			{
				result = result + next - current;
				i++;
			}
		}
		else
		{
			result = result + current;
		}
	}
	return result;
}

/************************************************************************
 * 
 * FUNCTION convert_digit
 * 	
 *-----------------------------------------------------------------------
 * This function will take a single digit from the user input and 
 * 		convert it into a roman numeral digit
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Converts the inputed decimal digit and returns a string
 *
*************************************************************************/
string convert_digit(int n,						// digit from input
				     string &roman_ones,		// roman ones digit
				     string &roman_tens,		// roman tens digit
				     string &roman_hundreds,	// roman hundreds digit
				     string &roman_thousands)	// roman thousands digit
	int count;
	string roman_number;
	count = 0;
	while (n > 0)
	{
		if (count == 0)
		{
			roman_ones = roman_digit(n % 10, "I", "V", "X");
			roman_number = roman_ones;
		}
		else if (count == 1)
		{
			roman_tens = roman_digit(n % 10, "X", "L", "C");
			roman_number = roman_tens + roman_ones;
		}
		else if (count == 2)
		{
			roman_hundreds = roman_digit(n % 10, "C", "D", "M");
			roman_number = roman_hundreds + roman_tens + roman_ones;
		}
		else
		{
			roman_thousands = roman_digit(n % 10, "M", "M", "M");
			roman_number = roman_thousands + 
				           roman_hundreds + 
						   roman_tens + 
						   roman_ones;
		}
		n = n / 10;
		count++;
	}
	return roman_number;

}

/************************************************************************
 * 
 * FUNCTION roman_digit
 * 	
 *-----------------------------------------------------------------------
 * This converts will take the user input digit and convert it into
 * 		roman numerals
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		None
 *
 * POST-CONDITIONS
 * 		Returns a roman numeral string
 *
*************************************************************************/
string roman_digit(int n,			// user input
		           string one,		// roman number containing 1
				   string five, 	// roman number containing 5
				   string ten)		// roman number containing 10
{

	string roman_letter;
	if ((n < 4) && (n > 0))
	{
		roman_letter = one;
		for (int i = 0; i < n - 1; i++)
		{
			roman_letter += one;
		}
	}

	else if (n == 4)
		roman_letter = one + five;

	else if (n == 5)
		roman_letter = five;

	else if ((n > 5) && (n < 9))
	{
		roman_letter = five;
		for (int i = 0; i < n-5; i++)
			roman_letter += one;
	}

	else if (n == 9)
	{
		roman_letter = one + ten;
	}
	return roman_letter;
		

}


