#include <iostream>
#include <stdio.h>
using namespace std;

class IntVector
{
	private:
		unsigned sz;	///< size
		unsigned cap;	///< capacity
		int *data;		///< dynamic array
			
		/**
		 *
		 */
		void expand();

		/**
		 *
		 */
		void expand( unsigned n );

	public:
		/****************
		 * CONSTRUCTORS *
		 ****************/
		/**
		 *
		 */
		IntVector();
		/**
		 *
		 */
		IntVector( unsigned size);
		/**
		 *
		 */
		IntVector( unsigned size, int value );
		/**
		 *
		 */
		~IntVector();

		/*************
		 * ACCESSORS *
		 *************/
		/**
		 *
		 */
		unsigned size() const;
		/**
		 *
		 */
		unsigned capacity() const;
		/**
		 *
		 */
		bool empty() const;
		/**
		 *
		 */
		const int & at( unsigned index ) const;
		/**
		 *
		 */
	 	int & at( unsigned index );
		/**
		 *
		 */
		const int & front() const;
		/**
		 *
		 */
		int & front();
		/**
		 *
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
		 *
		 */
		void erase ( unsigned index );

		/**
		 *
		 */
		void assign( unsigned n , int value );

		/**
		 * adds a defined value to the end of the IntVector object.
		 *
		 * @param value: value to be added to the end of the IntVector object.
		 */
		void push_back( int value );

		/**
		 *
		 */
		void pop_back();

		/**
		 * converts the IntVector object size to 0.
		 */
		void clear();

		/**
		 *
		 */
		void resize( unsigned size );

		/**
		 *
		 */
		void resize( unsigned size, int value );

		/**
		 *
		 */
		void reserve( unsigned n);
};

