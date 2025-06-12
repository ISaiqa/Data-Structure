#include <iostream>
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedList\Node.h"
using namespace std;

template<class T>
class LinkedStack
{
	private:
		Node<T> *top; //HEAD

	public:
		LinkedStack()
		{
			this->top=0;//STACK IS EMPTY
		}
		void push(T element);//ADDtOhEAD
		T pop();//REMOVEfROMhEAD
		bool isEmpty();
		//bool isFull();
		T topValue();
		void removeAll();
};
template <class T>
void LinkedStack<T>:: removeAll()
{
	while(!isEmpty())
	{
		pop();
	}
}

template<class T>
void LinkedStack<T>::push(T element)
{
	Node<T> *n=new Node<T>(element);
	if(top==0)//first element
	{
		top=n;
	}
	else
	{//add to head logic
		n->setNext(top);
		top=n;
	}
}//push

template<class T>
T LinkedStack<T>::pop()
{
	if(top==0)
		{
			cerr<<"Stack undeflow \n";
		}
	else if(top->getNext()==0)//last element on stack set top to 0
	{
		T element=top->getInfo();
		delete top;
		top=0;
		return element;
	}
	else
	{	
		T element=top->getInfo();
		Node<T> *temp=top->getNext();//stroes address of node that should be top
		delete top;
		top=temp;
		return element;
		//delete from head logic
	}
}

template<class T>
T LinkedStack<T>::topValue()
{
	if(top==0)
		cerr<<"Stack Underflow \n";
	else
		return top->getInfo();
}

template<class T>
bool LinkedStack<T>::isEmpty()
{
	return top==0;
}