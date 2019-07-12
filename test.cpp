#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	char symbol;
	cout << "Enter a line of input: \n";
	do
	{
		cin.get(symbol);
		cout << symbol;
	} while (symbol != 'n');
	
}

