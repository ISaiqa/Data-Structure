#include <iostream>
#include "Node.h"//without template
using namespace std;

class HeaderLL
{
	private:
		Node *head;
	public:
		HeaderLL()
		{
			head=0;
		}	
		void insert(int neighborV);//addTOHead
		Node* getHead();
		void displayALLNeighbors();
};


Node* HeaderLL::getHead()
{
	return this->head;
}

void HeaderLL::displayALLNeighbors()
{
	Node *i=head;
	while(i!=0)
	{
		cout<<"->"<<i->getInfo();
		i=i->getNext();
	}
}//display similar to dispaly in simple linked list just print all nodes info

void HeaderLL::insert(int neighborV)
{
	Node *n=new Node(neighborV);
	n->setNext(head);
	head=n;
	
}//addToHead


