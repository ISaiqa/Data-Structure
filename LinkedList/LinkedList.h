#include<iostream>
#include"Node.h"
using namespace std;
template <class T>

class LinkedList
{
	private:
		Node<T> *head;
		Node<T> *tail;
	
	public:
		LinkedList()
		{
			head=0;//0
			tail=0;//0
		}
		Node<T>* getHead();
		Node<T>* getTail();
		
		void addToTail(T element);
		void display();
		Node <T>* Search(T element);
		void addToHead(T element);
		void deleteFromTail();
		void deleteFromHead();
		void deleteBySearch(T element);
		void addBeforeElement(T existingV,T newV);
		void addAfterElement(T existingV, T newV);
		
};//End of class
template <class T>
Node<T>* LinkedList<T>::getHead()
{
	return this->head;
}// get head
template <class T>
Node<T>* LinkedList<T>::getTail()
{
	return this->tail;
} // get Tail
template <class T>
void LinkedList<T>::addToTail(T element)
{
	Node<T> *n=new Node<T>(element);
	if(head==0&&tail==0)// liast is empty we are adding first Node<T>
	{
		head=tail=n;
	}
	else // 1 or more Node<T>s already exist
	{
		tail->setNext(n);
		tail=n;
	}
}// add to tail
template <class T>
void LinkedList<T>::addToHead(T element)
{
	Node<T> *n=new Node<T>(element);
	if(head==0&&tail==0)// list is empty we are adding first Node<T>
	{
		head=tail=n;
	}
	else // 1 or more Node<T>s already exist
	{
		n->setNext(head);
		head=n;
	}
}// add to head
 template <class T>
 void LinkedList<T>::deleteFromTail()
 {
 	if(head==0&&tail==0)// error or empty
 	{
 		cout<<"List is empty";
 	//	return;
	 }
	 else if(head==tail)//only 1 node else if(head==tail)
	 {
	 	delete tail;
	 	head=tail=0;
	 }
	 else //more then one node
	 {
	 	Node<T> *i =head;
	 	while(i->getNext()!=tail)
	 	{
	 		i=i->getNext();
		 }
		 i->setNext(0);
		 delete tail;
		 tail=i;
	 }
 }// delete from tail fn

template<class T>
void LinkedList<T>::deleteFromHead()
{
	if(head==0&&tail==0)
	{
		cerr<<"List is empty";
	}//if
	else if(head==tail){
		delete tail;
		head=tail=0;
	}//else if
	else{
		Node<T> *i=head->getNext();
		delete head;
		head =i;
	}
}//delete from head
template<class T>
void LinkedList<T>::deleteBySearch(T element)
{
	
	if((head==0&&tail==0)||Search(element)==0)
	{
		cerr<<"Error";
		return;
	}
	else if(head==tail)
	{
		delete tail;
		head=tail=0;
	}
	else if(head->getInfo()==element)
	{
		deleteFromHead();
	}
	else if(tail->getInfo()==element)
	{
		deleteFromTail();
	}
	else
	{
		Node<T> *i=Search(element);
		Node <T>*j=head;
		while (j->getNext()!=i)
		{
			j=j->getNext();
		}
		j->setNext(i->getNext());
		delete i;
	}
	
}
template <class T>
void LinkedList<T>::display()
{
	Node<T> *i=head;
	while(i!=0)
	{
		cout<<i->getInfo()<<" ";
	   // i->display();
		i=i->getNext();                                                                                                                       
	}
 } // Display linked list
 template <class T>
 Node<T>* LinkedList<T>::Search(T element)
 {
 	Node<T> *i=head;
 	while(i!=0 && i->getInfo()!=element)
 	{
 		i=i->getNext(); 		
	}
	if(i==0)
	{
		return 0;
	}
	else
	{
		return i;
	}
 }
 template <class T>
 void LinkedList<T>::addBeforeElement(T existingV, T newV)
 { 
   
    Node <T> *l=Search(existingV);
 	if ((head==0 && tail==0) ||(l==0))
 	{
 		cerr<<"Cannot  insert value either list is empty or element not found";
	 }
	 else if(head==l)
	 {
	 	addToHead(newV);
	 }
	 else
	 {
	 	Node <T> *i=head;
	 	while(i->getNext()!=l)
	 	{
	 		i=i->getNext();
		 }
		  Node <T> *n=new Node<T>(newV);
		 i->setNext(n);  
		 n->setNext(l);
	
		 
	 }
 }// add before element
 template <class T>
 void LinkedList <T> ::addAfterElement(T existingV ,T newV)
 {
 	Node <T> *l=Search(existingV);
 	if ((head==0 && tail==0) ||(l==0))
 	{
 		cerr<<"Cannot  insert value either list is empty or element not found";
	 }
	 else if(tail==l)
	 {
	 	addToTail(newV);
	 }
	 else
	 {
	 	
		 Node <T> *n=new Node<T>(newV);
		 n->setNext(l->getNext());
		 l->setNext(n);
		 	 
	 }
 }
 