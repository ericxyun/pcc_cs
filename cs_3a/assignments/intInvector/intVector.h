#include <iostream>
#include <stdio.h>
using namespace std;

class IntVector
{
	private:
		unsigned sz;
		unsigned cap;
		int *data;
		void expand();
		void expand( unsigned n );

	public:
		/// CONSTRUCTORS
		IntVector();
		IntVector( unsigned size);
		IntVector( unsigned size, int value );
		~IntVector();

		/// ACCESSORS
		unsigned size() const;
		unsigned capacity() const;
		bool empty() const;
		const int & at( unsigned index ) const;
	 	int & at( unsigned index );
		const int & front() const;
		int & front();
		const int & back() const;

		/// MUTATORS
		int & back();
		void insert( unsigned index, int value );
		void erase ( unsigned index );
		void assign( unsigned n , int value );
		void push_back( int value );
		void pop_back();
		void clear();
		void resize( unsigned size );
		void resize( unsigned size, int value );
		void reserve( unsigned n);
};

void IntVector::expand()
{
	int *tmp;
	cap = cap * 2;
	tmp = new int[cap];
	for (int i = 0; i < sz; i++)
		tmp[i] = data[i];
	delete [] data;
	data = tmp;
}
// 
// void IntVector::expand( unsigned n )
// {
// 	cout << "helper expand" << endl;
// }
