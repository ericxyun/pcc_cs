#include "music_collection.h"

Music_collection::Music_collection()
{
	number = 0;
	max = 100;
	collection = new Tune[max];
}

Music_collection::Music_collection( int n )
{
	number = 0;
	max = n;
	collection = new Tune[max];
}

Music_collection::Music_collection( const Music_collection &m )
{
	number = m.number;
	max = m.max;
	collection = new Tune[max];
	for (int i = 0; i < number; i++)
		collection[i] = m.collection[i];
}

Music_collection & Music_collection::operator=( const Music_collection &m)
{
	if (collection)
	{
		delete [] collection;
		collection = new Tune[m.max];
	}

	number = m.number;
	max = m.max;

	for (int i = 0; i < m.number; i++)
		collection[i] = m.collection[i];
	return *this;
}

Music_collection::~Music_collection()
{
	delete [] collection;
}

bool Music_collection::add_tune( const Tune &t )
{
	if (number > max)
	{
		cout << "Number is greater than max" << endl;
		return false;
	}

	collection[number] = t;
	number++;
	return true;

}

bool Music_collection::set_tune( int index, const Tune &t )
{ 
	if (index < number)
	{
		collection[index] = t;
		return true;
	}
	return false;
}

ostream & operator<<( ostream &out, const Music_collection &m)
{
	for (int i = 0; i < m.number; i++)
	{
		out << m.collection[i].get_title();
		out << endl;
	}
	return out;

}
	
Tune::Tune()
{
	title = "";
}

Tune::Tune ( const string &n )
{
	title = n;
}

const string & Tune::get_title() const
{
	return title;
}





