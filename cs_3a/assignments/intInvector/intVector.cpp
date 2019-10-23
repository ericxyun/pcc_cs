#include "intVector.h"

/**
* initializes intVector object to 0
*/
IntVector::IntVector()
{
	sz = 0;
	cap = 0;
	data = new int[sz];
}

/**
* initalizes intVector object size and value to
*	parameter value and assigns 0 to all elements		
*/
IntVector::IntVector( unsigned size)
{
	sz = size;	
	cap = size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = 0;
}

/**
* initalizes intVector object size and value to
*	parameter value and assigns the value parameter 
*	to all elements		
*/
IntVector::IntVector( unsigned size, int value )
{
	sz = size;
	cap = size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = value;
}

/**
 * destroys the inVector object
 */
IntVector::~IntVector()
{
	delete [] data;
}

/**
* returns the size value of the intVector object
*/
unsigned IntVector::size() const
{
	return sz;
}

/**
 * returns the capacity value of the intVector object
 */
unsigned IntVector::capacity() const
{
	return cap;
}

/**
* checks to see if a vector is empty
*/
bool IntVector::empty() const
{
	if ( sz == 0 )
		return true;
	return false;
}

/**
* returns the value of the vector at the defined position
*
* @param index: position of vector
*/
const int & IntVector::at( unsigned index ) const
{
	if ( index >= sz )
		exit (0);
	return data[index];
}

/**
* returns the value of the vector at the defined position
*
* @param index: position of vector
*/
int & IntVector::at( unsigned index )
{
	if ( index >= sz )
		exit (0);
	return data[index];
}

/**
* returns the first element
*/
const int & IntVector::front() const
{
	return data[0];
}

/**
* returns the first element
*/
int & IntVector::front()
{
	return data[0];
}

/**
* returns the last element
*/
const int & IntVector::back() const
{
	return data[sz - 1];
}

/**
* returns the last element
*/
int & IntVector::back()
{
	return data[sz - 1];
}

/**
 * inserts a value at a given position in the index
 *
 * @param index position in vector
 * @param value value to be place in the index position
 */
void IntVector::insert( unsigned index, int value )
{
	if (index > sz)
		return exit(1);

	sz = sz + 1;

	if (sz > cap)
		expand();

	///shift values to the right
	for (int i = sz; i > index; i--)
	{
		data[i] = data[i - 1];
	}

	 data[index] = value;
}

/**
* removes the element at a given position
*
* @param index: position in vector
*/
void IntVector::erase ( unsigned index )
{
	if ( (index > sz) || (index < 0) )
		return exit(1);

	///shift values to the left
	for (int i = index; i < sz; i++)
		data[i] = data[i+1];
	sz = sz - 1;
}

/**
 * adds a defined value to the end of the IntVector object
 *
 * @param value value to be added to the end of the IntVector object
 */
void IntVector::push_back( int value )
{
	if (sz == 0)
	{
		sz = 1;
		cap = 1;
	}
	else	
	{
		sz = sz + 1;	
		if (sz > cap)
			expand();
	}

	// add value to end
	data[sz - 1] = value;
}

/**
 * removes the last element of the vector
 */
void IntVector::pop_back()
{
	if (sz == 0)	
		return exit(1);
	sz = sz - 1;
}

/**
 * converts the IntVector size to 0
 */
void IntVector::clear()
{
	sz = 0;
}

// TODO utilize expand with param values
// TODO finish documenting 
/**
 * resizes the IntVector size to the defined size
 *
 * @param size new size for the IntVector object
 */
void IntVector::resize( unsigned size )
{
	int tmp_sz = sz;
	sz = size;
	if (sz > cap)
	{
		if (sz < size - cap)
			expand(size - cap);
		else
			expand();

		for (int i = tmp_sz; i < sz; i++)
			data[i] = 0;
	}
}

// TODO utilize expand with param values
// TODO finish documenting
/**
 * resizes the IntVector size to the defined size
 *
 * @param size new size for the IntVector object
 */
void IntVector::resize( unsigned size, int value )
{
	int tmp_sz = sz;
	sz = size;
	if (sz > cap)
	{
		if (sz < size - cap)
			expand(size - cap);
		else
			expand();

	}
	for (int i = tmp_sz; i < sz; i++)
		data[i] = value;
	// if (size < sz) 
	// 	sz = size;
	// else if (size > sz)
	// {
	// 	if (size > sz)
	// 	{
	// 		int tmp_sz = sz;
	// 		sz = size;
	// 		if (sz > cap)
	// 			expand();
	// 		for (int i = tmp_sz; i < sz; i++)
	// 			data[i] = value;
	// 	}
	// }
}

/**
* drops all contents of a vector and resizes to n and fills
* 	in value the value parameter
*
* 	@param n: size 
* 	@param value: value to assign element
*/
void IntVector::assign( unsigned n , int value )
{
	resize(n);
	for (int i = 0; i < sz; i++)
		data[i] = value;
}

/**
 * minimum capacity to set, else increase capacity
 *
 * @param n: capacity to set
 */
void IntVector::reserve( unsigned n)
{
	if (n > cap)
	{
		if (cap * 2 < cap + n - cap)
		{
			expand(cap + n - cap);
		}
		else
			expand();
			// expand();
	}
	
}

void IntVector::display()
{
	for (int i = 0; i < sz; i++)
		cout << data[i] << " ";
	cout << endl;
	cout << "size: " << sz << endl;
	cout << "cap: " << cap << endl;
	cout << endl;
}

/// PRIVATE
/**
 *	doubles the capacity of the intVector object
 */
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

/**
* increases the capacity of the intVector object
* 	by the value of n
*/
void IntVector::expand( unsigned n )
{
	int *tmp;
	cap = n;
	tmp = new int[cap];
	for (int i = 0; i < sz; i++)
		tmp[i] = data[i];
	delete [] data;
	data = tmp;
}
