

template <class T>
class Stack:public LinkList<T>
{
	private:
		int maxStackSize;
	public:
		Stack()
		{
			maxStackSize = 50;
		}
		bool isEmpty();
		bool isFull();
		void Push(T num);
		T Pop();
		void display();
};

