#include<iostream>
using namespace std;

class Node
{
	private:
		int info;
		Node *next;
	
	public:
		Node(int info=0, Node *next=0)
		{
			this->info=info;
			this->next=next;
		}
		
		void setInfo(int info);
		void setNext(Node *next);
		int getInfo();
		Node* getNext();
		void display();
		
};//EoC


void Node::setInfo(int info)
{
	this->info=info;
}


void Node::setNext(Node *next)
{
	this->next=next;
}


int Node::getInfo()
{
	return this->info;
}


Node* Node::getNext()
{
	return this->next;
}


void Node::display()
{
	cout<<"|("<<this<<")|"<<this->info<<"|"<<this->next<<"|"<<endl;
}

