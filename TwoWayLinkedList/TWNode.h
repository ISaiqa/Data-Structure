#include<iostream>
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedList\LinkedList.h"
using namespace std;
template <class T>
class TWNode:public Node <T>
{
	private:
		TWNode<T> *prev;
	public:
		TWNode(T info , TWNode<T> *prev=0 ,TWNode<T> *next=0):Node <T>(info,next)
		{
			this->prev=prev;
		}
		void setPrev(TWNode<T> *prev);
		TWNode<T>* getPrev();
		void display();
	
};
template <class T>
void TWNode <T> ::setPrev(TWNode <T> *prev)
{
	this->prev=prev;
}
template <class T>
TWNode<T>* TWNode <T> ::getPrev()
{
	return this->prev;
}
template <class T>
void TWNode <T>:: display()
{
	
	cout<<"["<<this->prev<<"]";
	Node<T>::display();
}