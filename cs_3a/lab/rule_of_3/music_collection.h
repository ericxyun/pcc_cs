#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Tune
{
	private:
		string title;
	public:
		Tune();
		Tune ( const string &n );
		const string & get_title() const;
};

class Music_collection
{
	private:
		int number;
		int max;
		Tune *collection;
	
	public:
		Music_collection();
		Music_collection( int n );
		Music_collection( const Music_collection &m );
		~Music_collection();
		bool add_tune( const Tune &t );
		bool set_tune( int index, const Tune &t );
		Music_collection & operator=( const Music_collection &m);
		friend ostream & operator<<( ostream &out, const Music_collection &m );
};

