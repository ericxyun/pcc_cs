#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int minimum();
int firstNum();

int main()
{
	int ex;		// variable to store exercise number
	int numFirst;
	int num;
	cout << "Which exercise? ";
	cin >> ex;

	if (ex == 1)
	{
		minimum();	
	}
	else if (ex == 2)
	{
		//
	}

}

int firstNum()
{
}
int minimum()
{
	// FIRST
	string line;
	ifstream file("numbers.dat");
	getline(file, line);
	istringstream iss(line);
	int min;
	iss >> min;

	while (getline(file, line))
	{
		int current;
		stringstream iss(line);
		iss >> current;
		if (current < min)
		{
			min = current;
			cout << min << endl;
		}

	}
	return min;
	

}
