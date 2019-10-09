#include "complex.h"
#include <regex>

/**
 * Constructor to initialize the Complex object to it's default values.
 *
 * @param none
 * @return none
 */
Complex::Complex()
{
	real = 0;
	imag = 0;
}

/**
 * Constructor to initilize the Complex object with one parameter.
 *
 * @param real_part representation of the real number.
 * @return none
 */
Complex::Complex(double real_part)
{
	real = real_part;
	imag = 0;
}

/**
 * Constructor to initilize the Complex object with two parameters.
 *
 * @param real_part representation of a real number.
 * @param i reprentation of a imaginary number.
 * @return none
 */
Complex::Complex(double real_part, 
		         double i)
{
	real = real_part;
	imag = i;
}

/**
 * Compares two Complex objects
 *
 * @relatesalso Complex
 */
bool Complex::operator == (const Complex& ro) const
{
	if ( (ro.real == this->real) &&
		 (ro.imag == this->imag) )
		return true;
	return false;
}

/**
 * Sums two Complex objects.
 * 
 * @relatesalso Complex
 */
Complex Complex::operator + (const Complex& ro) const
{
	Complex sum;	///< resulting sum
	sum.real = this->real + ro.real;
	sum.imag = this->imag + ro.imag;
	return sum;
}

/**
 * Subtracts two Complex objects.
 *
 * @relatesalso Complex
 */
Complex Complex::operator - (const Complex& ro) const
{
	Complex difference;		///< resulting difference
	difference.real = this->real - ro.real;
	difference.imag = this->imag - ro.imag;
	return difference;
}

/**
 * Multiplies two Complex objects.
 *
 * @relatesalso Complex
 */
Complex Complex::operator * (const Complex& ro) const
{
	Complex product;	///< resulting product
	product.real = (this->real * ro.real) - (this->imag * ro.imag);
	product.imag = (this->real * ro.imag) + (this->imag * ro.real);
	return product;
}

/**
 * Stream insertion operator for Complex objects
 *
 * @relatesalso Complex
 */
ostream& operator << (ostream &out, const Complex &c)
{
	out << c.real;
	if (c.imag >= 0)
		cout << "+";
	out << c.imag << "i";
	return out;
}

/**
 * Stream extraction operation for Complex objects
 *
 * @relatesalso Complex
 */
istream& operator >> (istream &in, Complex &c)
{
	string str;			///< string to store istream
	stringstream ss;	///< sstream to store string

	/// Regex to filter and redirect
	in >> str;
	ss.str(str);
	/// a+bi, a-bi, -a+bi, -a-bi
	std::regex rgx("([-]?\\d+[.]?(\\d+)?[+|-]\\d+[.]?(\\d+)?[i])");
	/// bi, -bi
	std::regex rgxNumi("^[-]?\\d+[.]?(\\d+)?[i]");
	/// a, -a
	std::regex rgxn("^[-]?\\d+[.]?(\\d+)?$");
	/// -i
	std::regex rgxni("^[-][i]$"); 		
	/// i
	std::regex rgxi("^[i]$");

	/// rgx: real and imaginary
	if ( std::regex_match(str.begin(), str.end(), rgx) )
	{
		ss >> c.real;
		ss >> c.imag;
	}

	/// rgxNumi: non-zero imaginary
	else if ( std::regex_match(str.begin(), str.end(), rgxNumi) )
	{
		c.real = 0;
		ss >> c.imag;
	}

	/// rgxn: real
	else if ( std::regex_match(str.begin(), str.end(), rgxn) )
	{
		ss >> c.real;
		c.imag = 0;
	}

	/// rgxi: imaginary
	else if ( std::regex_match(str.begin(), str.end(), rgxi) )
	{
		c.real = 0;
		c.imag = 1;
	}

	/// rgxni: negative imaginary
	else if ( std::regex_match(str.begin(), str.end(), rgxni) )
	{
		c.real = 0;
		c.imag = -1;
	}

	return in;
}

/**
 * Prints the equation and solution for the sum, difference
 * 		and product of two Complex objects
 *
 * @param c1 first complex object 
 * @parma c2 second complex object 
 * @returns none
 */
void display(const Complex &c1, const Complex &c2)
{
	cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
	cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
	cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;

}
