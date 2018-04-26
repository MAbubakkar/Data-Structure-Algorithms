
#include "stdafx.h"
#include "Queue.h"

template <class T>
bool Queue<T>::isEmpty()
{
	if(front==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
int Queue<T>::numberOfNodes()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		int count = 0;
		Node<T> *ptrtemp = front;
		while(ptrtemp != 0)
		{
			count++;
			ptrtemp = ptrtemp->ptrnext;
		}
		return count;
	}
}

template <class T>
bool Queue<T>::isFull()
{
	int n = numberOfNodes();
	if(n == maxQueueSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Queue<T>::enqueue(T num)
{
	if(isFull())
	{
		cout<<"Queue is Full!"<<endl;
	}
	else
	{
		Node<T> *ptrnode = new Node<T>;
		ptrnode->data = num;
		ptrnode->ptrprevious = 0;
		ptrnode->ptrnext = 0;

		if(isEmpty())
		{
			front = ptrnode;
			rear = ptrnode;
		}
		else
		{
			ptrnode->ptrprevious = rear;
			rear->ptrnext = ptrnode;
			rear = ptrnode;
		}
	}
}

template <class T>
T Queue<T>::dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty!"<<endl;
		return 0;
	}
	else
	{
		T n = front->data;
		if(front == rear)
		{
			delete front;
			front = 0;
			rear = 0;
			return n;
		}
		else
		{
			Node<T> *ptrtemp = front;
			front = front->ptrnext;
			front->ptrprevious = 0;
			delete ptrtemp;
			return n;
		}
	}
}

template <class T>
T Queue<T>::getFront()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return front->data;
	}
}

template <class T>
void Queue<T>::printQueue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		Node<T> *ptrtemp = front;
		while(ptrtemp != 0)
		{
			cout<<ptrtemp->data<<"\t";
			ptrtemp = ptrtemp->ptrnext;
		}
	}
}
