
/**************************************************************************
 *	AUTHOR	         : Eric Yun
 *	ASSIGNMENT #	 : 
 *	CLASS	         : CS 002
 *	SECTION          : MTRF: 7:00a - 12p
 *	Due Date         : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
struct MenuItem
{
	string menuItem;
	double menuPrice;
};

struct customerItem
{
	int quantity;
	string menuItem;
	double menuPrice;
};
/**************************************************************************
 *
 * TITLE
 *
 *--------------------------------------------------------------------------
 * Program Description
 *--------------------------------------------------------------------------
 * INPUT:
 *
 * OUTPUT:
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

// FUNCTION Prototypes
/**************************************************************************
 * functionName
 * 		First line of description
 * 		Second line of description
 ***************************************************************************/
void showMenu(vector<MenuItem> m);
void getData(vector<MenuItem> &m, string filename);
void printCheck(vector<customerItem> &c);
	
int main()
{
	vector<MenuItem> m;
	vector<customerItem> c;
	string filename;

	cout << fixed << setprecision(2);
	cout << "Enter filename: \n" << endl;
	cin >> filename;
	getData(m, filename);
	showMenu(m);

	int selection;
	int quantity;
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

	printCheck(c);

	

}
/************************************************************************
 * 
 * FUNCTION functionName
 * 	
 *-----------------------------------------------------------------------
 * Function description
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
*************************************************************************/
void showMenu(vector<MenuItem> m)
{
	cout << "Welcome to Johnny's Restaurant\n";
	cout << endl;
	cout << setw(18) << setfill(' ')  << "Menu\n";
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

void getData(vector<MenuItem> &m, string filename)
{
	MenuItem menu;
	ifstream infile;
	string str;
	infile.open(filename);

//	while (getline(infile, str))
//	{
//		menu.menuItem = str.substr(0, str.find('$'));
//		menu.menuPrice = atof((str.substr(str.find('$') + 1,
//				               str.size())).c_str());
//		m.push_back({menu.menuItem, menu.menuPrice});
//		count++;
//	}

	while (!infile.eof())
	{
		getline(infile, menu.menuItem, '$');
		infile >> menu.menuPrice;
		infile.ignore(1000, '\n');
		m.push_back({menu.menuItem, menu.menuPrice});
	}
}

void printCheck(vector<customerItem> &c)
{
	double sum = 0;
	double tax;
	cout << "SALE\n";
	cout << endl;
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i].quantity << " "
		     << c[i].menuItem << " "
		     << "$" << c[i].menuPrice << endl;
		sum += c[i].menuPrice;
	}
	tax = sum * 0.05;
	cout << "Tax $"  <<  tax << endl;
	cout << "Amount Due $"  << sum + tax << endl;
}
