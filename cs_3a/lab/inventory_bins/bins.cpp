
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #	 : 
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
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
struct Parts
{
	string description;
	int quantity;
};

int numItems(const Parts bins[]);
int numItems(const Parts bins[])
{
	int count = 0;

	for (int i = 0; i < 30; i++)
		if (!bins[i].description.empty())
			count++;
	return count;
}

void displayInventory(const Parts bins[]);
void displayInventory(const Parts bins[])
{
	// PROCESSING - print results
	for (int i = 0; i < 30; i++)
	{
		if (!bins[i].description.empty())
		{
			cout << setw(16);
			setfill(" ");
			cout << left;
			cout << bins[i].description;
			cout << setw(7);
			setfill(" ");
			cout << right;
			cout << bins[i].quantity << endl;
		}
	}
	cout << endl;
}

void addParts(Parts bins[], 
		      string part_description,
			  int part_quantity);

void addParts(Parts bins[], 
		      string part_description,
			  int part_quantity)
{
	int numParts;	
	int size;

	// add after the last item;
	size = numItems(bins) + 1;

	bins[size].description = part_description;
	bins[size].quantity = part_quantity;
	displayInventory(bins);
}

bool inBin(Parts bins[], string &bin_selection);
bool inBin(Parts bins[], string &bin_selection)
{
	int size;

	size = numItems(bins);

	for (int i = 0; i < size; i++)
	{
		if (bin_selection == bins[i].description)
			return 1;
	}

	cout << "That item is not in the inventory." << endl;
	cout << endl;
	return 0;
}




void removeParts(Parts bins[], string &bin_selection);
void removeParts(Parts bins[], string &bin_selection)
{
	int size;
	bool inBin = 0;
	int numParts;
	int idx;


	// count number of items in bin
	size = numItems(bins);	

	for (int i = 0; i < size; i++)
	{
		if (bin_selection == bins[i].description)
		{
			inBin = 1;
			idx = i;
		}
	}

	if (inBin)
	{
		cout << "Number of parts to remove: ";
		cin >> numParts;
		cout << endl;
		bins[idx].quantity -= numParts;

	}

	else
	{
		cout << "That item is not in the bin." << endl;
		cout << endl;
	}
	displayInventory(bins);
}

void addItem(Parts bins[], string &bin_selection);
void addItem(Parts bins[], string &bin_selection)
{
	int size;
	bool inBin;
	int idx;
	int numParts;

	size = numItems(bins);	

	for (int i = 0; i < size; i++)
	{
		if (!bins[i].description.empty())
		{
			if (bin_selection == bins[i].description)
			{
				inBin = 1;
				idx = i;
			}
		}
	}

	if (inBin)
	{
		cout << "Number of parts to add: ";
		cin >> numParts;
		cout << endl;
		bins[idx].quantity += numParts;

	}

	else
	{
		cout << "That item is not in the bin." << endl;
		cout << endl;
	}
	displayInventory(bins);


}


void displayMenu(char selection);
void displayMenu(char selection)
{
	cout << "Menu:" << endl;

	if (selection == 's')
	{
		cout << "Add parts (a)" << endl;
		cout << "Remove parts (r)" << endl;
	}

	else 
	{
		cout << "Add a new item (a)" << endl;
		cout << "Select a bin (s)" << endl;
		cout << "Quit (q)" << endl;
	}
}

int main()
{
	Parts bins[30];
	string line;
	ifstream infile;
	char selection;
	string bin_selection;
	char s_selection;
	string part_description;
	int part_quantity;
	string filename;


	int count = 0;
	int i = 0;
	int j = 0;

	cout << "Enter name of inventory file: ";
	getline(cin, filename);
	cout << endl;

	// infile.open("inventory.txt");
	infile.open(filename);

	// PROCESSING - initialize array
	while (getline(infile, line))
	{
		if (count % 2 == 0)
		{
			bins[i].description = line;
			i++;
		}
		else
		{
			istringstream convert(line);
			convert >> bins[j].quantity;
			// bins[j].quantity = stoi(line);
			j++;
		}
		count++;
	}

	displayInventory(bins);
	do 
	{
		displayMenu(selection);
		cout << endl;
		cout << "Selection: ";
		// cin.get(selection);
		cin >> selection;
		cout << endl;

		while ((selection != 'a') && (selection != 's') && (selection != 'q'))
		{
			cout << endl;
			displayMenu(selection);
			cout << endl;
			cout << "Selection: ";
			// cin.get(selection);
			cin >> selection;
			cout << endl;
		}


		// while ((selection != 's') && (selection != 'a') && selection != 'q')
		// {
		// 	cin.ignore();	// needed this before using cin.get for some reason
		// 	cout << "Please make a valid selection: " ;
		// 	cin.get(selection);
		// }
	
		// Select a bin
		if (selection == 's')
		{
			cout << "Bin Selection: ";
			cin.ignore(1000, '\n');
			getline(cin, bin_selection);
			cout << endl;
			cout << endl;

			if (inBin(bins, bin_selection))
			{
				displayMenu('s');
				cout << endl;
				cout << "Selection: ";
				cin >> selection;
				// cin.get(selection);
				cout << endl;
				
			    while ((selection != 'r') && (selection != 'a'))
				{
					cout << endl;
					displayMenu('s');
					cout << endl;
					cout << "Selection: ";
					cin >> selection;
					cout << endl;
				}


				// Remove item
				if (selection == 'r')
				{
					removeParts(bins, bin_selection);
				}

				// Add item
				else if (selection == 'a')
				{
					addItem(bins, bin_selection);

				}
			}
		}
		// Add item
		else if (selection == 'a')
		{
			cout << endl;
			cin.ignore(1000, '\n');
			cout << "Enter Part Description: ";
			getline(cin, part_description);
			cout << endl;
			
			cout << "Number of Parts in the Bin: ";
			cin >> part_quantity;
			cout << endl;
			cout << endl;
			addParts(bins, part_description, part_quantity);
				

		}
		else
			continue;
	
	}
	while (selection != 'q');
	cout << "Good Bye!!!" << endl;
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
