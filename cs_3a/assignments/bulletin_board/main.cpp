#include <iostream>
#include "bboard.h"
#include "bboard.cpp"
using namespace std;

int main(int argc, char **argv)
{
	cout << "Welcome!\n";
	BBoard b;
	b.setup(argv[1]);
	b.login();
}
