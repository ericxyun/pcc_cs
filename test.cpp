#include <iostream>
#include <map>:

using namespace std;

int foo(int x)
{
	return x;
}

void bar(int x, map<char, string>& align)
{
	if (x == 0)
	{
		align['N'] = "Monster";
		align['S'] = "Genie";
		align['E'] = "Picture";
		align['W'] = "Exit";
	}

	else 
	{
		align['N'] = "Exit";
		align['S'] = "Monster";
		align['E'] = "Genie";
		align['W'] = "Picture";
	}
}

int main()
{
	map<char, string> align;

	int x = foo(0);
	bar(x, align);



	cout << align['N'] << endl;
	cout << align['S'] << endl;
	cout << align['E'] << endl;
	cout << align['W'] << endl;

	


}

