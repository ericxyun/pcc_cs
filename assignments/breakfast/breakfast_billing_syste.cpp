
/**************************************************************************
 *	AUTHOR	         : Eric Yun
 *	ASSIGNMENT 11	 : Breakfast Billing System
 *	CLASS	         : CS 002
 *	SECTION          : MTRF: 7:00a - 12p
 *	Due Date         : June 23, 2019	
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// struct to hold menu items
struct MenuItem
{
	string menuItem;	// item name
	double menuPrice;	// item price
};

// struct to hold customer selections
struct customerItem
{
	int quantity;		// item quantity
	string menuItem;	// item name
	double menuPrice;	// item price
};
/**************************************************************************
 *
 * BREAKFAST BILLING SYSTEM
 *
 *--------------------------------------------------------------------------
 * This program will present a menu of items a customer can order and will
 * 		keep track of the customer's order and output the final price for
 * 		all the selections.
 *--------------------------------------------------------------------------
 * INPUT:
 * 		filename : menu with items and price
 * 		selection: item number
 * 		quantity : number of items from the selection
 *
 * OUTPUT:
 * 		menu
 * 		selections and their quantities
 * 		total cost including tax
 *
 ***************************************************************************/

// FUNCTION Prototypes
/**************************************************************************
 * showMenu
 * 		This function will read in a vector containing the menu items from 
 * 		an external file and will output the results
 ***************************************************************************/
void showMenu(vector<MenuItem> m);	// vector to hold menu items and price

/**************************************************************************
 * getData
 * 		This function will read in the external file and will write the 
 * 		the contents to a vector
 ***************************************************************************/
void getData(vector<MenuItem> &m, 	// vector to hold menu items and price
		     string filename);		// INPUT - file name

/**************************************************************************
 * printCheck
 * 		This function will calculate the total cost after all selections 
 * 		and will output the results
 ***************************************************************************/
void printCheck(vector<customerItem> &c);	// vector to hold customer
											// selections
	
int main()
{
	// variables
	vector<MenuItem> m;			// holds the menu items and price
	vector<customerItem> c;		// holds the customer selection
	string filename;			// INPUT - file name
	int selection;				// INPUT - item number selection
	int quantity;				// INPUT - number of items of selection

	// INPUT - enter file name
	cout << fixed << setprecision(2);
	cout << "Enter filename: \n" << endl;
	cin >> filename;

	// PROCESSING - copy file content to vector
	getData(m, filename);

	// OUTPUT - print contents of file
	showMenu(m);

	// INPUT - get item number and quantity
	do
	{
		cout << "Enter 0 when you finish your order.\n";
		cout << endl;
		cout << "Enter the item number: \n";
		cin >> selection;
		if (selection != 0)
		{
			cout << "How many would you like to order? \n";
			cin >> quantity;
			cout << endl;
			cout << endl;

			c.push_back({quantity, 
						m[selection - 1].menuItem,
						quantity * (m[selection - 1].menuPrice)});


			showMenu(m);
		}
	} 
	while(selection != 0);

	// OUTPUT - print final result
	printCheck(c);
}

/************************************************************************
 * 
 * FUNCTION showMenu
 * 	
 *-----------------------------------------------------------------------
 * This function will read in a vector containing the menu items from 
 * 		an external file and will output the results
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		prints contents from vector
 *
*************************************************************************/
void showMenu(vector<MenuItem> m) 	// vector to hold contents from file
{
	// OUTPUT - prints contents from vector holding menu item info
	cout << "Welcome to Johnny's Restaurant\n";
	cout << endl;
	cout << setw(18) << setfill(' ') << right << "Menu\n" ;
	cout << endl;
	for (int i = 0; i < m.size(); i++)
	{
		cout << i+1 << ". " 
			 << left << setw(20) << setfill(' ')
			 << m[i].menuItem 
			 << "$ " << m[i].menuPrice << endl;
	}
	cout << endl;
}

/************************************************************************
 * 
 * FUNCTION getData
 * 	
 *-----------------------------------------------------------------------
 * This function will read in the external file and will write the 
 * 		the contents to a vector
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		fills in vector menu items and price
 *
*************************************************************************/
void getData(vector<MenuItem> &m,		// vector to hold contents from file
		     string filename)			// INTPUT - file name
{
	//variables 
	MenuItem menu;		    // from menu item struct
	ifstream infile;	    // reading in file name
	infile.open(filename); 	//read file

	// PROCESSING - read file and write to vector
	while (!infile.eof())
	{
		getline(infile, menu.menuItem, '$');
		infile >> menu.menuPrice;
		infile.ignore(1000, '\n');
		m.push_back({menu.menuItem, menu.menuPrice});
	}
}

/************************************************************************
 * 
 * FUNCTION printCheck
 * 	
 *-----------------------------------------------------------------------
 * This function will calculate the total cost after all selections 
 * 		and will output the results
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		prints content from vector holding customer selections
 *
*************************************************************************/
void printCheck(vector<customerItem> &c) 	// vector to hold customer
											// selections
{
	// variables
	double sum = 0;		// total cost minus tax
	double tax;			// tax cost

	// OUTPUT - prints final result from customer vector
	cout << "\n\n";
	cout << "Welcome to Johnny's Restaurant\n";
	cout << endl;
	cout << setw(18) << setfill(' ') << right << "SALE\n" ;
	cout << endl;
	
	for (int i = 0; i < c.size(); i++)
	{
		cout << setw(3)  << setfill(' ') << left  << c[i].quantity 
		     << setw(20) << setfill(' ') << left  <<  c[i].menuItem << "$" 
			 << setw(5)  << setfill(' ') << right << c[i].menuPrice << endl;
		sum += c[i].menuPrice;
	}

	// PROCESSING - calculates tax and total cost
	tax = sum * 0.05;
	cout << "Tax" 
		 << setw(21) << setfill(' ') << right << "$" 
		 << setw(5)  << setfill(' ') << right <<   tax << endl;
	cout << string(29, '-') << endl;
	cout << "Amount Due" 
		 << setw(14) << setfill(' ') << right << "$"  
		 << setw(4)  << setfill(' ') << left << sum + tax << endl;
	cout << endl;
}
