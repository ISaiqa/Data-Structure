#include<iostream>
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedList\Node.h"
using namespace std;

template <class T>

class LinkedQueue
{
	private:
		Node<T>* rear;
		Node <T>* front;
	public:
		LinkedQueue()
		{
			rear=front=0;
		}
		void enqueue (T element);
		T dequeue();
		bool isEmpty();
		T rearValue();
		T frontValue();
		bool inList(T element);
};
template <class T>
bool LinkedQueue<T>::inList(T element)
{
	Node<T> *i=front;
	while(i!=0)
	{
		if(i->getInfo()==element)
		{
			return true;
		}
		i=i->getNext();
	}
	return false;
}

template <class T>
bool LinkedQueue<T>::isEmpty()
{
	if(front==0 && rear==0)
	{
		return true;
	}
	else
		return false;
}
template <class T>
T LinkedQueue<T>::frontValue()
{
	if(isEmpty())
	{
		cerr<<"Queue is empty!"<<endl;
	}
	else 
		return front->getInfo();
}// get front
template <class T>
T LinkedQueue<T>::rearValue()
{
	if(isEmpty())
	{
		cerr<<"Queue is empty!"<<endl;
	}
	else 
		return this->rear->getInfo();
} // get rear

template <class T>
void LinkedQueue<T>::enqueue(T element)
{
	Node<T> *n=new Node<T>(element);
	if(front==0&&rear==0)// list is empty we are adding first Node<T>
	{
		front=rear=n;
	}
	else // 1 or more Node<T>s already exist
	{//add to tail
		rear->setNext(n);
		rear=n;
	}
}
template <class T>
T LinkedQueue<T>::dequeue()
{
	if(rear==0&&front==0)
	{
		cerr<<"List is empty";
	}//if
	else if(rear==front)
	{
		T element=rear->getInfo();
		delete front;//delete rear same effect
		rear=front=0;
		return element;
	}//else if
	else
	{
		//delete from head
		T element=front->getInfo();
		Node<T> *i=front->getNext();
		delete front;
		front =i;
		return element;
	}
}
//in queue front ==head   rear==tail
//enqueue==add to tail]
//dequeue ==delete from head
//ensures the element that came first is processed first and vice versa
//First In First Out  /Last In Last Out

