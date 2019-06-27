
/**************************************************************************
 *	AUTHOR	      : Eric Yun
 *	ASSIGNMENT #3 : Mathematics Specifications
 *	CLASS	      : CS 002
 *	SECTION       : MTRF: 7:00a - 12p
 *	Due Date      : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
/**************************************************************************
 *
 * MATHEMATICS SPECIFICATIONS
 *
 *--------------------------------------------------------------------------
 * This program performs various types of mathematical operations given the
 * 	user's inputs
 *--------------------------------------------------------------------------
 * INPUT:
 * 	operation: types of operation
 * 		- addition
 * 		- subtraction
 * 		- division
 * 		- multiplication
 * 		- fabs (floating point absolute value)
 * 		- sqrt
 * 		- quadratic
 * 		- pythagorean
 * 	input_array[4]: takes up to four user inputs as floats
 *
 * OUTPUT:
 * 	num[1-4]: variables to to make calculations
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

// global variables
float num1;
float num2;
float num3;
float num4;
float input_array[4] = {};	//empty array to store user input values
string operation;

// function to get user input accounting for the number of variables needed.
void user_input(int num)
{
	int i = 0;	// initializing the counter

	// storing user input requests in an array
	string get_input[4] = {"Enter your first number: ",
			       "Enter your second number: ",
			       "Enter your third number: ",
			       "Enter your fourth number: "};

	// do-while loop stops at maximum num of variables needed.
	do
	{
		cout << get_input[i];	
		cin >> input_array[i];
		cout << endl;
		i++;
	}
	while (i < num);
}

// function to output error when trying to square root a negative number
void sqrt_error()
{
	cout << "Error: " 
	     << "Cannot take square root of a negative number." << endl;
}

// function to output error when trying to divide by zero
void division_error()
{
	cout << "Error: Cannot divide by zero." << endl;
}

// adds two floats
void addition()
{
	float sum;
	user_input(2);
	num1 = input_array[0];
	num2 = input_array[1];
	sum = num1 + num2;
	cout << "Equation: " << num1 << " + " << num2 << endl;
	cout << endl;
	cout << "Results: " << sum << endl;
}

// subtracts two floats
void subtraction()
{
	float difference;
	user_input(2);
	num1 = input_array[0];
	num2 = input_array[1];
	difference = num1 - num2;
	cout << "Equation: " << num1 << " - " << num2 << endl;
	cout << endl;
	cout << "Results: " << difference << endl;
}

// divides two floats
void division()
{
	float fraction;
	user_input(2);
	num1 = input_array[0];
	num2 = input_array[1];
	cout << "Equation: " << num1 << " / " << num2 << endl;
	cout << endl;
	if (num2 == 0)
		division_error();
	else
	{
		fraction = num1 / num2;
		cout << "Results: "  << fraction << endl;
	}
}

// multiplies two floats
void multiplication()
{
	float product;
	user_input(2);
	num1 = input_array[0];
	num2 = input_array[1];
	product = num1 * num2;
	cout << "Equation: " << num1 << " * " << num2 << endl;
	cout << endl;
	cout << "Results: " << product << endl;
}

// floating point absolution value
void fabs()
{
	float fpab;
	user_input(1);
	num1 = input_array[0];
	fpab = fabs(num1);
	cout << "Equation: " << "fabs(" << num1 << ") " << endl;
	cout << endl;
	cout << "Results: " << fpab << endl;
}

// square root
void sqrt()
{
	float root;
	user_input(1);
	num1 = input_array[0];
	cout << "Equation: " << "sqrt(" << num1 << ")" << endl;
	cout << endl;
	if (num1 < 0)
		sqrt_error();
	else
	{	
		root = sqrt(num1);
		cout << "Results: " << root << endl;
	}	
}

// quadratic function
void quadratic()
{
	float a;
	float b;
	float c;
	float d;

	user_input(3);
	a = input_array[0];
	b = input_array[1];
	c = input_array[2];

	d = (b * b) - (4 * a * c);
	cout << "Equation: "
	     << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
	cout << endl;
	
	if (d < 0)
	{
		sqrt_error();
	}
	else if (a == 0)
	{
		num1 = (-1 * c) / b;
		cout << "Result: " << num1 << endl;
	}
	else
	{
		num1 = ((-1 * b) + sqrt(d)) / (2 * a);
		num2 = ((-1 * b) - sqrt(d)) / (2 * a);	
		cout << "Results: " << num1 << ", " << num2 << endl;
	}
}

// pythagorean theorem
void pythagorean()
{
	float d;
	float hyp;
	user_input(2);
	num1 = input_array[0];
	num2 = input_array[1];
	hyp = sqrt(num1 * num1 + num2 * num2);
	cout << "Equation: sqrt(" << num1 
	     << "^2 + " << num2 << "^2)" << endl;
	cout << endl;
	cout << "Results: " << hyp << endl;
}

int main()
{
	// INPUT -- asks user for type of operation to be performed
	cout << "Please choose an operation: " << endl;
	cin >> operation;

	// PROCESSING AND OUTPUT -- performs respective function
	// 			    based on operation condition
	if (operation == "addition")
		addition();
	else if (operation == "subtraction")
		subtraction();
	else if (operation == "division")
		division();
	else if (operation == "multiplication")
		multiplication();
	else if (operation == "fabs")
		fabs();
	else if (operation == "sqrt")
		sqrt();
	else if (operation == "quadratic")
		quadratic();
	else if (operation == "pythagorean")
		pythagorean();
	else 
		cout << "Error: Operation not supported." << endl;

	return 0;
}




