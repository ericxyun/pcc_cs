IntVector::IntVector()
{
	sz = 0;
	cap = 0;
	data = new int[sz];
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
	display();
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
	display();
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
	display();
	int tmp_sz = sz;
	sz = size;
	if (sz > cap)
	{
		if (sz < size - cap)
			expand(size - cap);
		else
			expand();

		for (int i = tmp_sz; i < sz; i++)
			data[i] = value;
	}
	display();
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

void IntVector::assign( unsigned n , int value )
{
	display();
	resize(n);
	for (int i = 0; i < sz; i++)
		data[i] = value;
	display();
}

void IntVector::reserve( unsigned n)
{

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
