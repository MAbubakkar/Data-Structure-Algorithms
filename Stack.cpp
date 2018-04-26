#include "stdafx.h"
#include "Stack.h"


template <class T>
bool Stack<T>::isEmpty()
{
	bool r = LinkList<T>::isEmpty();
	return r;
}

template <class T>
bool Stack<T>::isFull()
{
	int n = LinkList<T>::NumberOfNodes();
	if (n == maxStackSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Stack<T>::Push(T num)
{
	if(isFull())
	{
		cout<<"Stack Full!!"<<endl;
	}
	else
	{
		LinkList<T>::addToHead(num);
	}
}

template <class T>
T Stack<T>::Pop()
{
	if(isEmpty())
	{
		cout<<"Stack Empty"<<endl;
		return 0;
	}
	else
	{
		T n = LinkList<T>::getHead();
		LinkList<T>::deleteFromHead();
		return n;
	}
}

template <class T>
void Stack<T>::display()
{
	if(isEmpty())
	{
		cout<<"Stack Empty!!"<<endl;
	}
	else
	{
		LinkList<T>::display();
	}
}

