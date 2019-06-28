#include <iostream>
using namespace std;


int main() {
	string user_input;
	do {
		cout << "Enter 'y' or 'n'" << endl;
		cin >> user_input;	
	}
	while (user_input != "y" && user_input != "n");
}


