
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab 14	 : Vectors
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : July 18, 2019	
 **************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/**************************************************************************
 *
 * VECTORS 
 *
 *--------------------------------------------------------------------------
 * This program will take in a string with delimiters and will convert
 *		it into a vector
 *--------------------------------------------------------------------------
 * INPUT:
 *		target: starting string to be converted.
 *		delimiter: delimiting character
 *
 * OUTPUT:
 *		outputs a vector with sections of the strings that have been 
 *		separated by the delimiter
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

// FUNCTION Prototypes
/**************************************************************************
 * split
 * 		This function will take in a target string and a target delimiter
 *		and will return a vector of the contents of the string with the 
 *		delimiter removed.
 ***************************************************************************/
vector<string> split(string target, 	// target string
		             string delimiter);	// delimiter used to convert target

int main()
{
	// variables
	vector<string> v; 	// holds the vector to output
	string target;
	string delimiter;
//	cout << "Enter the taret string: \n";
//	getline(cin, target);
//	cout << "Enter the delimiter: \n";
//	cin >> delimiter;

	target = "the cow jumped over the moon";
	delimiter = "the";

	// split function converts string to vector given the delimiter
	v = split(target, delimiter);

	// OUTPUT - prints the resulting vector
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}


/************************************************************************
 * 
 * FUNCTION split
 * 	
 *-----------------------------------------------------------------------
 * This function will take in a target string and a target delimiter
 *		and will return a vector of the contents of the string with the 
 *		delimiter removed.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 *		target: user input string 
 *		delmiter: user input string
 *
 * POST-CONDITIONS
 *		returns a vector filled with the target's content separated by
 *		the delimiter.
 *
*************************************************************************/
vector<string> split(string target, 	// target string
		             string delimiter)	// delimiter used to convert target
{
	// variables
	vector<string> v; 	// vector to hold target values
	size_t  delimPos;			// string to track non-delimiter strings
	string str;
	string strRest;
	string result;

	str = target;
	do
	{
		delimPos = str.find(delimiter);
		str = str.substr(delimPos + delimiter.size());
		if (delimPos < target.size())
		{
			v.push_back(str);
		}
	}
	while (delimPos < target.size());

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].find(delimiter) < target.size())
		{
			delimPos = v[i].find(delimiter);
			v[i] = v[i].erase(delimPos, target.size());
			cout << v[i] << endl;
		}
	}

		



	




	// OUTPUT - returns vector with string contents
	return v;
}

