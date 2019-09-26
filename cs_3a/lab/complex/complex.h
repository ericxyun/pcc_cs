#include <iostream>
#include <sstream>
#include <regex>
using namespace std;
class Complex
{
	private:
		double real;
		double imag;

	public:
		Complex();
		Complex(double);
		Complex(double, double);
		bool operator == (const Complex& ro) const;
		Complex operator + (const Complex& ro) const;
		Complex operator - (const Complex& ro) const;
		Complex operator * (const Complex& ro) const;
		friend ostream& operator << (ostream &out, const Complex &c);
		friend istream& operator >> (istream &in, Complex &c);
		void display();
};

const Complex i(0,1);
void display(const Complex &c1, const Complex &c2);

