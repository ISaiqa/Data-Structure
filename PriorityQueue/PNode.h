#include<iostream>
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedList\LinkedList.h"
using namespace std;
template <class T>
class PNode:public Node <T>
{
	private:
		int priority;//all same in this node only added priority
	public:
		PNode(T info ,int priority,PNode *next=0):Node <T>(info,next)
		{
			this->priority=priority;
		}
		void setPriority(int priority);
		int getPriority();
		void display();
		
};
template <class T>
void PNode <T> ::setPriority(int priority)
{
	this->priority=priority;
}
template <class T>
int PNode <T> ::getPriority()
{
	return this->priority;
}
template <class T>
void PNode <T>:: display()
{
	
	cout<<"["<<this->priority<<"]";
	Node<T>::display();
}