


template <class T>
class Queue
{
	private:
		Node<T> *front;
		Node<T> *rear;
		int maxQueueSize;
	public:
		Queue()
		{
			front = 0;
			rear = 0;
			maxQueueSize = 5;
		}
		bool isEmpty();
		int numberOfNodes();
		bool isFull();
		void enqueue(T num);
		T dequeue();
		T getFront();
		void printQueue();

};

