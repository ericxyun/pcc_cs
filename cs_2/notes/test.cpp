#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int x = 3;
    cout << setfill ('*');
    cout << right;
    cout << setw(5) << x << setw(5) << endl;
}
