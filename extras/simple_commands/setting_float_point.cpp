#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    // cout.precision(2);

    double n1(3), n2(7);

    cout << n1 / n2 << endl;
}