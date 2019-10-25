#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int sum(int n)
{
	// base case: n == 1;
	if (n == 1)
		return 1;
	// adds 1 to each
	else
		return n + sum(n-1);

}

int findmin(const int a[], int n)
{
	int min;
	int small;
	// base case: n = 2
	if (n == 2)
	{
		if (a[0] < a[1])
			return a[0];
		else
			return a[1];
	}

	// compares element[index] with element[index - 1]
	else 
	{
		// if (a[n-1] < findmin(a, n-1))
		small = findmin(a, n-1);
		if (a[n-1] < small)
			return a[n-1];
		else 
			return small;
	}
}

int findsum(const int a[], int n)
{
	if (n == 1)	
		return a[0];
	else 
	{
		return a[n-1] + findsum(a, n-1);
	}
}

bool ispalindrome(const char a[], int n)
{

	// even
	if (n == 2)
	{
		if (a[0] == a[1])
			return true;
		return false;
	}
	else if (n == 3)
	{
		if (a[0] == a[2])
			return true;
		return false;
	}

	else if (a[0] != a[n-1])	
		return false;

	else
	{
		char newArray [n - 2];
		int count = 0;
		for (int i = 1; i < n-1; i++)
		{
			newArray[count] = a[i];
			count++;
		}
		return ispalindrome(newArray, n-2);
	}
}

vector<string> generate_substrings(string s)
{
	vector<string> sVec;
	string x = "";
	int len = s.length();
	int count = 0;

	for (int i = 0; i < len; i++)
	{
		x += s[i];
		sVec.push_back(x);
		count++;
		for (int j = i+1; j < len; j++)
		{
			x += s[j];
			sVec.push_back(x);
			count++;
		}
		x = "";
	}

	cout << count + 1 << " substrings" <<  endl;
	for (int k = 0; k < sVec.size(); k++)
	{
		if (k < sVec.size() - 1)
			cout << sVec[k] << ", ";
		else
		{
			cout << sVec[k] << ", ";
			cout << "∅" << endl;
		}
	}
	return sVec;
}

/*
 * draws a pattern using asterisks
 *
 * @param n
 */
void drawPattern(int n, bool pass, int pos_num)
{
	if ((pass == true) && (n == pos_num))
	{
		cout << string(n, '*') << endl;
	}
	else if ((pass == true) && (n < 5))
	{
		cout << string(n, '*') << endl;
		return drawPattern(n + 1, pass, pos_num);
	}
	else if ((pass == false) && (n == 1))
	{
		cout << string(n, '*') << endl;
		pass = true;
		return drawPattern(n, true, pos_num);
	}
	else
	{
		cout << string(n, '*') << endl;
		return drawPattern(n-1, pass, pos_num);
	}
}
int main()
{

	int selection;
	cout << "Select a function to test(1-6): " << endl;
	cin >> selection;
	
	if (selection == 1)
	{
		int n;
		cout << "Enter a positive integer: ";
		cout << endl;
		cin >> n;
		cout << endl;
		cout << "The sum is " << sum(n) << endl;

	}

	else if (selection == 2)
	{
		int size;
		int *a;
		cout << "Finding the minimum element of an array containing random numbers from -1000 to 1000.\n";
		cout << "Enter the size of the array: " << endl;
		cin >> size;
		a = new int [size];
		for (int i = 0; i < size; i++)
		{
			a[i] = rand()%(1000 - -1000 + 1) + -1000;
		}
		cout << endl;
		cout << "The minimum element of the array is ";
		cout << findmin(a, size) << endl;

	}
	
	else if (selection == 3)
	{
		int size;
		int *a;
		cout << "Finding the sum of the elements of an array containing random numbersfrom -1000 to 1000.\n";
		cout << "Enter the size of the array: ";
		cin >> size;
		cout << endl;
		a = new int [size];
		for (int i = 0; i < size; i++)
		{
			a[i] = rand()%(1000 - -1000 + 1) + -1000;
		}
		cout << endl;
		cout << "The sum of the elements of the array is "; 
		cout << findsum(a, size) << endl;
	}

	else if (selection == 4)
	{
		string phrase;
		int size;
		const char *p;
		cout << "Enter a phrase: " << endl;
		cin >> phrase;
		size = phrase.length();
		p = new char [size];
		p = phrase.c_str();

		if (ispalindrome(p, size))
			cout << "The phrase is a palindrome." << endl;
		else
			cout << "The phrase is not a palindrome" << endl;
	}

	else if (selection == 5)
	{
		string str;
		int num_substr;

		cout << "Enter a string: " << endl;
		cin >> str;

		generate_substrings(str);
	}

	else if (selection == 6)
	{
		int pos_num;
		cout << "Enter a positive number: " << endl;
		cin >> pos_num;
		bool pass = false;
		drawPattern(pos_num, pass, pos_num);

	}
}
