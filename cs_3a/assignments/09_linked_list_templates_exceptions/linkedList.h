template<typename E>

struct Node {
	E data;	
	Node *next;
	Node( E data ): data (data), next(0) {}
};

class LinkedList
{
	private:
		Node *head;
		Node *tail;
	
	public:
		LinkedList()
		LinkedList(const LinkedList& source)
		~LinkedList()
		LinkedList & operator=( const LinkedList& source )
		void display() const
		void push_front( const E& value )
		void push_back( const E& value )
		void pop_front() throw(ListEmpty)
		const E& front() const throw(ListEmpty);
		const E& back() const throw(ListEmpty);
		void clear();
		void select_sort()
		void insert_sorted( const E& value )
		void remove_duplicates()
		Iterator begin()
		Iterator end()
		int length() const;
		int sum() const;
		bool isEmpty() const;  

}
