
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #5	 : Manipulators and File IO
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
/**************************************************************************
 *
 * MANIPULATORS and FILE IO
 *
 *--------------------------------------------------------------------------
 * This program will take ".txt" files as inputs and perform various 
 *     calculations based on the lines of the file
 *     
 *--------------------------------------------------------------------------
 * INPUT:
 *	txt file
 *
 * OUTPUT:
 *	Rectangle: area, perimeter
 *	Circle: area, circumference
 *	Name: interest balance at end of month
 *	Character: character after the current
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

int main()
{
	// variables 
	char str[255];       // defining characters
	string rectangle;    // input stream
	string circle;		 // input stream
	string name;		 // input stream
	string balance; 	 // input stream
	string character;    // input stream
	int count; 			 // counting the number of lines

	// INPUT - read in file from directory
	count = 0;
	ifstream file("inData.txt");
	while(file) 
	{
		count++;
		file.getline(str, 255);
		if (count == 1)
			rectangle = str;
		else if (count == 2)
			circle = str;
		else if (count == 3)
			name = str;
		else if (count == 4)
			balance = str;
		else if (count == 5)
			character = str;
	}
	cout << fixed << setprecision(2);

	
	// RECTANGLE
	double length;		// first input of line
	double width;		// second input of line
	double area; 		// calculated area
	double perimeter;   // calculated perimeter


	// PROCESSING
	stringstream stream(rectangle);
	stream >> length >> width;
	area = length * width;
	perimeter = 2 * length + 2 * width;

	// OUTPUT
	cout << "Rectangle:" << endl;
	cout << "Length = " << length;
	cout << ", width = " << width;
	cout << ", area = " << area;
	cout << ", perimeter = " << perimeter << endl;
	cout << endl;

	// CIRCLE
	double radius;				// first input of line
	double circumference;       // calculated from radius

	// PROCESSING
	stringstream s_circle(circle);
	s_circle >> radius;
	area = 3.14159 * radius * radius;
	circumference = 2 * 3.14159 * radius;

	// OUTPUT
	cout << "Circle:" << endl;
	cout << "Radius = " << radius
	     << ", area = " << area
		 << ", circumference = " << circumference
		 << endl << endl;

	// NAME
	string f_name;		// input from line
	string l_name;		// input from line
	int age;  			// input from line
	double b_balance;   // input from line
	double interest;	// input from line
	double balance_end; // calculated from b_balance and interest

	// PROCESSING 
	stringstream s_name(name);
	stringstream s_balance(balance);
	s_name >> f_name >> l_name >> age;
	s_balance >> b_balance >> interest;
	balance_end = b_balance + b_balance * (0.01/12 * interest);

	// OUPUT
	cout << "Name: " << f_name << " " << l_name;
	cout << ", age: " << age << endl;
	cout << "Beginning balance = $" << b_balance;
	cout << ", interest rate = " << interest << endl;
	cout << "Balance at the end of the month = $"
		 << balance_end << endl;
	cout << endl;

	// CHARACTER
	char ch;
	char next_ch;
	next_ch = static_cast<char>(ch + 1);

	// PROCESSING
	stringstream s_char(character);
	s_char >> ch;

	// OUTPUT
	cout << "The character that comes after " << ch;
	cout << " in the ASCII set is " << static_cast<char>(ch + 1);
	cout << endl;
	
	ofstream fout("test.txt");
}
