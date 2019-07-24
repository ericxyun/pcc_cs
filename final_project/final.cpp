#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string letters = "ABCDEFGHIJ";
	cout << setw(25) << setfill(' ') << right << "Your Board";
	cout << setw(25) << setfill(' ') << " ";
	cout << setw(25) << setfill(' ') << right << "Enemy Board";
	cout << endl;
	cout << "     ";
	
	for (int i = 0; i < 2; i++)
	{
		for (int j =0; j < 10; j++)
		{
			cout << j + 1 << "   ";
		}
		cout << "\t";
		cout << "     ";
	}
	cout << endl;

	for (int i = 0; i < letters.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "   ";
			cout << string(41, '-');
			cout << "\t";
		}
		cout << endl;
		for (int j = 0; j < 2; j++)
		{
			cout << letters[i];
			cout << "  ";
			for (int k = 0; k <= 10; k++)
			{
				cout << "|   ";
			}
			cout << "\t";
		}
		cout << endl;
	}
	cout << "   ";
	cout << string(41, '-');
	cout << "\t";

}



