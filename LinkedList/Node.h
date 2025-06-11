#include<iostream>
using namespace std;
template <class T>
class Node
{
	public:
		T info;
		Node<T> *next;
	public:
		Node(T info=0,Node<T> *next=0)
		{
			this->info=info;
			this->next=next;
		}// constructor
		void setInfo(T info);
		void setNext(Node<T> *next);
		Node<T>*getNext();
		T getInfo();
		void display();
};// end of class
//Implementation of Node<T>.h
template <class T>
void Node<T>::setInfo(T info)
{
	this->info=info;
}//set info
template <class T>
T Node<T>::getInfo()
{
	return this->info;
}//get info
template <class T>
void Node<T>::setNext(Node<T> *next)
{
	this->next=next;
}//setnext
template <class T>
Node<T> * Node<T>:: getNext()
{
	return this-> next;
}//get Next
template <class T>
void Node<T> :: display()
{
	cout<<"Info:"<<this->info<<endl;
//	cout<<"Next:"<<this->next;
	//cout<<"|("<<this<<")|"<<this->info<<"|"<<this->next<<"|"<<endl;
	
}