#include "stdafx.h"
#include "LinkList.h"

template <class T>
bool LinkList<T>::isEmpty()
{
	if(head == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void LinkList<T>::addToHead(T num)
{
	Node<T> *ptrnode = new Node<T>;
	ptrnode->data = num;
	ptrnode->ptrprevious = 0;
	ptrnode->ptrnext = 0;

	if(isEmpty())
	{
		head = ptrnode;
		tail = ptrnode;
	}
	else
	{
		ptrnode->ptrnext = head;
		head->ptrprevious = ptrnode;
		head = ptrnode;
	}
}

template <class T>
void LinkList<T>::deleteFromHead()
{
	if(isEmpty())
	{
		cout<<"DLinked List Empty!!";
	}
	else
	{
		if(head == tail)
		{
			delete head;
			head = 0;
			tail = 0;
		}
		else
		{
			Node<T> *ptrtemp = head;
			head = head->ptrnext;
			head->ptrprevious = 0;
			delete ptrtemp;
		}
	}
}

template <class T>
void LinkList<T>::display()
{
	if(isEmpty())
	{
		cout<<"LinkList Empty"<<endl;
	}
	else
	{
		Node<T> *ptrtemp = head;
		while(ptrtemp->ptrnext != 0)
		{
			cout<<ptrtemp->data<<endl;
			ptrtemp = ptrtemp->ptrnext;
		}
		cout<<ptrtemp->data<<endl;
	}
}

template <class T>
int LinkList<T>::NumberOfNodes()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		int count = 0;
		Node<T> *ptrtemp = head;
		while(ptrtemp->ptrnext != 0)
		{
			count++;
			ptrtemp = ptrtemp->ptrnext;
		}
		count++;
		return count;
	}
}

template <class T>
T LinkList<T>::getHead()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return head->data;
	}
}

