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
	
	public;
}
