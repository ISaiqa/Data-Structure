#include<iostream>
#include"PNode.h"
using namespace std;
template <class T>
class PriorityQueue
{
	private:
		PNode<T>*rear;
		PNode<T>* front;
	public:
		PriorityQueue()
		{
			rear=front=0;
		}
		void addSorted(T element,int priority);
		T dequeue();
		bool isEmpty();
		bool isFull();
		T rearValue();
		T frontValue();
		
};

template <class T>
bool PriorityQueue<T>::isEmpty()
{
	if(front==0 && rear==0)
	{
		return true;
	}
	else
		return false;
}
template <class T>
T PriorityQueue<T>::frontValue()
{
	if(isEmpty)
	{
		cerr<<"Queue is empty!"<<endl;
	}
	else 
		return front->getInfo();
}// get front
template <class T>
T PriorityQueue<T>::rearValue()
{
	if(isEmpty)
	{
		cerr<<"Queue is empty!"<<endl;
	}
	else 
		return this->rear->getInfo;
} // get rear
template <class T>
T PriorityQueue<T>::dequeue()
{
	if(rear==0&&front==0)
	{
		cerr<<"List is empty";
		//return;
	}//if
	else if(rear==front)
	{
		T element=rear->getInfo();
		delete rear;
		rear=front=0;
		return element;
	}//else if
	else
	{
		T element=front->getInfo();
		Node<T> *i=front->getNext();
		delete front;
		front =(PNode<T>*)i;
		return element;
	}
}
//smaller value = higher priority
//smiliar to queue just add element 
//sorted w.r.t priority so we can process then accordingly
template <class T>
void PriorityQueue<T>:: addSorted(T element,int priority)
{
	PNode<T>* n=new PNode<T>(element,priority);
	if(front==0 && rear==0) // first element
	{
		front=rear=n;
		
	}
	else if(front->getPriority()>=priority) //if priority of front is >= priority add before front
	{//if priority smaller then front add before front
		n->setNext(front);
		front=n;
		
	}
	else if(priority> rear->getPriority())//if greater  then rear's priority add after rear
	{
		rear->setNext(n);
		rear=n;
	}
	else
	{
		PNode<T>* i=front;
		//while(priority > i->getNext()->getPriority())
		while (i->getNext()!=0 && priority > ((PNode<T>*)i->getNext())->getPriority())
		{//check until the given priority is greater then priority of the i
			i=(PNode<T>*)i->getNext();
		}
		n->setNext(i->getNext());//when found add element there 
		i->setNext(n);
	}
}
