

template <class T>
struct Node
{
	T data;
	Node *ptrprevious;
	Node *ptrnext;
};

// header file
template <class T>
class LinkList
{
	private:
		Node<T> *head;
		Node<T> *tail;
	public:
		LinkList()
		{
			head = 0;
			tail = 0;
		}
		bool isEmpty();
		void addToHead(T num);
		void deleteFromHead();
		void display();
		int NumberOfNodes();
		T getHead();

};

