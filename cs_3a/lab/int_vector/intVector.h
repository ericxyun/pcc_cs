/**
 * AUTHOR  : Eric Yun
 * LAB 9   : IntVector
 * CLASS   : CS 3A
 * SECTION : MTRF: 7 - 8
 * DUE DATE: October 2, 2019
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************************************************
 *
 * INTVECTOR
 *
 *--------------------------------------------------------------------------
 * This program will represent a small version of what the Vector Class is
 *--------------------------------------------------------------------------
 * INPUT:
 * 	sz : size of object
 * 	cap: capacit of object
 *
 * OUTPUT:
 * 	data: storage for object
 *
 ***************************************************************************/


/* This class is represents a primitive version of a Vector class
 * and is responsible for handingling three attributes: 
 * sz, cap, and data.
 */
class IntVector
{
	private:
		unsigned sz;	// size
		unsigned cap;	// cap
		int *data;		// data array

	public:
		/**
		 * CONSTRUCTORS
		 */

		/**
		 * initializes all values to 0
		 */
		IntVector();

		/**
		 * initializes all values to 0
		 * 
		 * @param size size of Invector object
		 */
	 	IntVector(unsigned size);

		/**
		 * initializes all values to 0
		 *
		 * @param value capacity of InVector class
		 */
		IntVector (unsigned size, int value);

		/**
		 * ACCESSORS
		 */
		
		/**
		 * returns the size of the IntVector class
		 */
		unsigned size() const;

		/**
		 * returns the capacity of the IntVector class
		 */

		unsigned capacity() const;
		/**
		 * checks to see if the IntVector class is empty
		 */
		bool empty() const;

		/**
		 * MUTATORS
		 */

		/**
		 * returns the value of the IntVector at a particular position
		 */
		const int &at(unsigned index) const;
}; 
