#include <iostream>
#include "bboard.h"
using namespace std;

int main(int argc, char **argv)
{
	cout << "Welcome!\n";
	BBoard b;
	b.setup(argv[1]);
	b.login();
}
