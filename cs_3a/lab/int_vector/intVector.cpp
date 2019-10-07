#include "intVector.h"
/**
 * Constructor to initialize IntVector class to default values
 */
IntVector::IntVector()
{
	sz =0;
	cap = 0;
}

/**
 * Constructor to initialize IntVector class to default values
 * 	
 * 	@param size IntVector object size
 */
IntVector::IntVector (unsigned size)
{
	sz = size;
	cap = sz;
	data = new int[size];
	for (unsigned i = 0; i < size; i++)
	{
		data[i] = 0;

	}
}

/**
 * Constructor to initialize IntVector class to default values
 * 	
 * 	@param size IntVector object size
 * 	@param initial value of array
 */
IntVector::IntVector( unsigned size, int value)
{
	sz = size;
	cap = size;
	data = new int[size];
	for (unsigned i = 0; i < size; i++)
	{
		data[i] = value;
	}
}

/*
 * @return size of the vector
 */
unsigned IntVector::size() const
{
	return sz;
}

/*
 * @return capactiy of the vector
 */
unsigned IntVector::capacity() const
{
	return cap;
}

/* checks to see if the IntVector object is empty
 *
 * @return boolean
 */
bool IntVector::empty() const
{
	if (sz == 0)
		return true;
	return false;
}

/* returns the value of the array at a given index
 *
 * @return value at position of index
 */
const int &IntVector::at(unsigned index) const
{
	if (index >= sz)
		exit (0);
	return data[index];
}
