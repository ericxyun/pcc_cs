#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

/**
 * Representation of an imaginary number 
 *
 * This class manages two attributes: real and imag. a+bi is used to represent 
 * the imaginary number where real = a and imag = b.
 *
 */
class Complex
{
	private:
		double real; ///< real number
		double imag; ///< imaginary number

	public:
		/****************
		 * CONSTRUCTORS *
		 ****************/
		/**
		 * Constructor to initialize the Complex object to it's default values.
		 *
		 * @param none
		 * @return none
		 */
		Complex();

		/**
		 * Constructor to initilize the Complex object with one parameter.
		 *
		 * @param real_part representation of the real number.
		 * @return none
		 *
		 * @overload
		 */
		Complex(double);

		/**
		 * Constructor to initilize the Complex object with two parameters.
		 *
		 * @param real_part representation of a real number.
		 * @param i reprentation of a imaginary number.
		 * @return none
		 *
		 * @overload
		 */
		Complex(double, double);
		
		/*************
		 * ACCESSORS *
		 *************/
		/**
		 * Compares two Complex objects
		 *
		 * @relatesalso Complex
		 */
		bool operator == (const Complex& ro) const;

		/**
		 * Stream insertion operator for Complex objects
		 *
		 * @relatesalso Complex
		 */
		friend ostream& operator << (ostream &out, const Complex &c);

		/************
		 * MUTATORS *
		 ************/
		/**
		 * Sums two Complex objects.
		 * 
		 * @relatesalso Complex
		 */
		Complex operator + (const Complex& ro) const;

		/**
		 * Subtracts two Complex objects.
		 *
		 * @relatesalso Complex
		 */
		Complex operator - (const Complex& ro) const;

		/**
		 * Multiplies two Complex objects.
		 *
		 * @relatesalso Complex
		 */
		Complex operator * (const Complex& ro) const;

		/**
		 * Stream extraction operation for Complex objects
		 *
		 * @relatesalso Complex
		 */
		friend istream& operator >> (istream &in, Complex &c);
};

// constant i
const Complex i(0,1);

/**
 * Prints the equation and solution for the sum, difference
 * 		and product of two Complex objects
 *
 * @param c1 first Complex object
 * @param c2 second Complex object
 */
void display(const Complex &c1, const Complex &c2);
