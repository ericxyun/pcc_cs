using namespace std;
struct IntNode
{
	int data;
	IntNode *next;
	IntNode( int data ) : data(data), next(0) {}
};

class IntList
{
	private:
		IntNode *head;
		IntNode *tail;

	public:
		IntList();
		IntList( const IntList &list);
		// ~IntList();
		// void display() const;
		// void push_front( int value );
		// void push_back( int value );
		// void pop_front();
		// void select_sort();
		// void insert_sorted( int value );
		// void remove_duplicates();
		// IntListIterator begin();
		// IntListIterator end();
		// int front() const;
		// int back() const;
		// int length() const; 
		// int sum() const; 
		// void reverseDisplay() const; 
		// IntList & operator=( const IntList &list );

};
