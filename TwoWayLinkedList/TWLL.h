#include<iostream>
#include"TWNode.h"
using namespace std;
template <class T>
class TWLL 
{
	private:
		TWNode <T> *head;
		TWNode <T> *tail;
	public:
		TWLL()
		{
			head=tail=0;
		}
		void addToHead(T element);
		void display();	
		void display2();
		void addToTail(T element);
		TWNode <T>* Search(T element);
		void deleteFromTail();
		void deleteFromHead();
		void deleteBySearch(T element);
		void addBeforeElement(T existingV, T newV);
		
		
	
};
template <class T>
void TWLL<T> ::addToHead(T element)
{
	TWNode <T> *n=new  TWNode<T> (element);
	if(head==0 && tail==0) // list is empty
	{
		head=tail=n;
	}
	else  // one or more element exist
	{
		n->setNext(head);
		head->setPrev(n);
		head=n;
	}
}

template <class T>
void TWLL<T> :: addToTail(T element)
{
	TWNode <T> *n=new  TWNode<T> (element);
	if(head==0 && tail==0) // list is empty
	{
		head=tail=n;
	}
	else
	{
		tail->setNext(n);
		n->setPrev(tail);
		tail=n;
	}
}

template <class T>
void TWLL <T>::display ()
{
	TWNode<T> *i=head;
	while (i!=0)                                                                                                
	{
	//	i->display();
	    cout<<i->getInfo();
		cout<<"\t";
		i=(TWNode<T> *)i->getNext();                                                   
	}
}
 template <class T>
 TWNode<T>* TWLL<T>::Search(T element)
 {
 	TWNode<T> *i=head;
 	while(i!=0 && i->getInfo()!=element)
 	{
 		i=(TWNode <T> *)i->getNext(); 		
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
 void TWLL<T>::deleteFromTail()
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
	 	TWNode <T> *i=tail->getPrev();
	 	i->setNext(0);
		 delete tail;
		 tail=i;
	 }
 }// delete from tail fn
 template<class T>
void TWLL<T>::deleteFromHead()
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
		TWNode<T> *i=(TWNode<T> *)head->getNext();
		delete head;
		head =i;
	}
}//delete from head
template<class T>
void TWLL<T>::deleteBySearch(T element)
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
		TWNode<T> *i=Search(element);
		TWNode <T> *prev=i->getPrev();
		TWNode<T> *next=(TWNode <T>*)i->getNext();
		prev->setNext(next);
		next->setPrev(prev);
		delete i;
	}
}
template <class T>
 void TWLL<T>::addBeforeElement(T existingV, T newV)
 { 
   
    TWNode <T> *l=Search(existingV);
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
	 	TWNode <T> *n=new TWNode<T>(newV);
	 	TWNode <T> *prev=l->getPrev();
	 	prev->setNext(n)
	
		n->setNext(l);
		 
	 }
 }// add before element