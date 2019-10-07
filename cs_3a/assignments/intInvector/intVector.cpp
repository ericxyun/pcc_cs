IntVector::IntVector()
{
	sz = 0;
	cap = 0;
	data = NULL;
}

IntVector::IntVector( unsigned size)
{
	sz = size;	
	cap = size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = 0;
}

IntVector::IntVector( unsigned size, int value )
{
	sz = size;
	cap = size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = value;
}

IntVector::~IntVector()
{
	delete [] data;
}

unsigned IntVector::size() const
{
	return sz;
}
unsigned IntVector::capacity() const
{
	return cap;
}
bool IntVector::empty() const
{
	if ( sz == 0 )
		return true;
	return false;
}

const int & IntVector::at( unsigned index ) const
{
	if ( index >= sz )
		exit (0);
	return data[index];
}

int & IntVector::at( unsigned index )
{
	if ( index >= sz )
		exit (0);
	return data[index];
}

const int & IntVector::front() const
{
	return data[0];
}

int & IntVector::front()
{
	return data[0];
}

const int & IntVector::back() const
{
	return data[sz - 1];
}

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

	expand();
}

void IntVector::erase ( unsigned index )
{

}
void IntVector::assign( unsigned n , int value )
{

}
void IntVector::push_back( int value )
{

}
void IntVector::pop_back()
{

}
void IntVector::clear()
{

}
void IntVector::resize( unsigned size )
{

}
void IntVector::resize( unsigned size, int value )
{

}
void IntVector::reserve( unsigned n)
{

}

