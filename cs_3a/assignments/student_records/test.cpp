#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile ("input.txt");
	infile.seekg(0, infile.end);
	int len = infile.tellg();
	infile.seekg(0, infile.beg);
	int size;

	infile >> size;

	char *buffer = new char[len];
	infile.read(buffer, len);
	cout << buffer << endl;

}
