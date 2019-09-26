#include "complex.h"
#include <regex>
Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex::Complex(double real_part)
{
	real = real_part;
	imag = 0;
	
}

Complex::Complex(double real_part, 
		         double i)
{
	real = real_part;
	imag = i;
}

bool Complex::operator == (const Complex& ro) const
{
	if ((ro.real == this->real) &&
		(ro.imag == this->imag))
		return true;
	return false;
}

Complex Complex::operator + (const Complex& ro) const
{
	Complex sum;
	sum.real = this->real + ro.real;
	sum.imag = this->imag + ro.imag;
	return sum;
}

Complex Complex::operator - (const Complex& ro) const
{
	Complex difference;
	difference.real = this->real - ro.real;
	difference.imag = this->imag - ro.imag;
	return difference;
}

Complex Complex::operator * (const Complex& ro) const
{
	Complex product;
	product.real = (this->real * ro.real) - (this->imag * ro.imag);
	product.imag = (this->real * ro.imag) + (this->imag * ro.real);
	return product;
}


ostream& operator << (ostream &out, const Complex &c)
{
	out << c.real;
	if (c.imag >= 0)
		cout << "+";
	out << c.imag << "i";
	return out;
}

istream& operator >> (istream &in, Complex &c)
{
	string str;
	stringstream ss;
	in >> str;
	ss.str(str);
	std::regex rgx("([-]?\\d+[.]?(\\d+)?[+|-]\\d+[.]?(\\d+)?[i])");
	std::regex rgxNumi("^[-]?\\d+[.]?(\\d+)?[i]");
	std::regex rgxni("^[-][i]$"); 		
	std::regex rgxi("^[i]$");
	std::regex rgxn("^[-]?\\d+[.]?(\\d+)?$");
	if ( std::regex_match(str.begin(), str.end(), rgx) )
	{
		ss >> c.real;
		ss >> c.imag;
	}
	else if ( std::regex_match(str.begin(), str.end(), rgxNumi) )
	{
		ss >> c.imag;
		c.real = 0;
	}
	else if ( std::regex_match(str.begin(), str.end(), rgxi) )
	{
		c.real = 0;
		c.imag = 1;
	}
	else if ( std::regex_match(str.begin(), str.end(), rgxni) )
	{
		c.real = 0;
		c.imag = -1;
	}
	else if ( std::regex_match(str.begin(), str.end(), rgxn) )
	{
		ss >> c.real;
		c.imag = 0;
	}

	// if (str[str.size() - 1] == 'i')
	// 	ss >> c.imag;
	// else 
	// {
	// ss >> c.real;
	// ss >> c.imag;
	// }
	// in >> c.real;
	// in >> c.imag;
	return in;
}

void Complex::display()
{
	cout << real << endl;
	cout << imag << endl;
}

void display(const Complex &c1, const Complex &c2)
{
	cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
	cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
	cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;

}
