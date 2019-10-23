#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class IntVector
{
	private:
		unsigned sz;	///< size
		unsigned cap;	///< capacity
		int *data;		///< dynamic array
			
		/**
		 *	doubles the capacity of the intVector object
		 */
		void expand();

		/**
		 * increases the capacity of the intVector object
		 * 	by the value of n
		 */
		void expand( unsigned n );

	public:
		/****************
		 * CONSTRUCTORS *
		 ****************/
		/**
		 * initializes intVector object to 0
		 */
		IntVector();

		/**
		 * initalizes intVector object size and value to
		 *	parameter value and assigns 0 to all elements		
		 *
		 *	@param assignment value for size and capacity
		 */
		IntVector( unsigned size);

		/**
		 * initalizes intVector object size and value to
		 *	parameter value and assigns the value parameter 
		 *	to all elements		
		 *
		 *	@param assignment value for size and capacity
		 *	@param value: value to assign vector elements
		 */
		IntVector( unsigned size, int value );

		/**
		 * destroys the inVector object
		 */
		~IntVector();

		/*************
		 * ACCESSORS *
		 *************/

		/**
		 * returns the size value of the intVector object
		 */
		unsigned size() const;

		/**
		 * returns the capacity value of the intVector object
		 */
		unsigned capacity() const;

		/**
		 * checks to see if a vector is empty
		 */
		bool empty() const;

		/**
		 * returns the value of the vector at the defined position
		 *
		 * @param index: position of vector
		 */
		const int & at( unsigned index ) const;

		/**
		 * returns the value of the vector at the defined position
		 *
		 * @param index: position of vector
		 */
	 	int & at( unsigned index );

		/**
		 * returns the first element
		 */
		const int & front() const;

		/**
		 * returns the first element
		 */
		int & front();

		/**
		 * returns the last element
		 */
		const int & back() const;

		/**
		 *
		 */
		void display();

		/************
		 * MUTATORS *
		 ************/
		/**
		 *
		 */
		int & back();

		/**
		 * inserts a value at a given position in the index.
		 *
		 * @param index: position in vector
		 * @param value: value to be place in the index position
		 */
		void insert( unsigned index, int value );

		/**
		 * removes the element at a given position
		 *
		 * @param index: position in vector
		 */
		void erase ( unsigned index );

		/**
		 * drops all contents of a vector and resizes to n and fills
		 * 	in value the value parameter
		 *
		 * 	@param n: size 
		 * 	@param value: value to assign element
		 */
		void assign( unsigned n , int value );

		/**
		 * adds a defined value to the end of the IntVector object.
		 *
		 * @param value: value to be added to the end of the IntVector object.
		 */
		void push_back( int value );

		/**
		 * removes the last element of the vector
		 */
		void pop_back();

		/**
		 * converts the IntVector object size to 0.
		 */
		void clear();

		/**
		 * increases the size of a intVector object
		 *
		 * @param size: size value to set
		 */
		void resize( unsigned size );

		/**
		 * resizes the IntVector size to the defined size
		 *
		 * @param size new size for the IntVector object
		 */
		void resize( unsigned size, int value );

		/**
		 * minimum capacity to set, else increase capacity
		 *
		 * @param n: capacity to set
		 */
		void reserve( unsigned n);
};

