#include <iostream>
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
		bool operator==(const Complex& ro) const;
		Complex operator+(const Complex& ro) const;
		Complex operator-(const Complex& ro) const;
		Complex operator*(const Complex& ro) const;
		void display();
};

const Complex i(0,1);
