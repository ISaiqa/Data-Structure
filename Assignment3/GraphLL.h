#include<iostream>
#include"GNode.h"

using namespace std;

class GraphLL
{
	private:
		GNode *head;
	public:
		GraphLL()
		{
			head=0;
		}
		~GraphLL();
		void insert(int neighborV,float distance);
		GNode* getHead();
		void displayAllNeighbors();
		void remove(int vertice);
		void clear();
		
		
		
};
GNode* GraphLL::getHead()
{
	return this->head;
}
void GraphLL::displayAllNeighbors()
{
	GNode *i=head;
	while(i!=0)
	{
		
		cout<<i->getInfo()<<" ";
		cout<<"(";
		cout<<i->getDistance();
		cout<<" km)";
		cout<<",";
		
	   // i->display();
		i=i->getNext();                                                                                                                       
	}
}
void GraphLL::insert(int neighborV,float distance)
{
	GNode *n=new GNode(neighborV,distance);
	n->setNext(head);
	head=n;
	//n->setDistance(distance);
	
}
void GraphLL::remove(int vertice) 
{
    GNode *current = head;
    GNode *prev = nullptr;
    while (current != nullptr) 
	{
        if (current->getInfo() == vertice) 
		{
            if (prev == nullptr) 
			{
                head = current->getNext();
                delete current;
                current = head;
            } else 
			{
                prev->setNext(current->getNext());
                delete current;
                current = prev->getNext();
            }
        } 
		else 
		{
            prev = current;
            current = current->getNext();
        }
    }
}

void GraphLL::clear() 
{
    GNode *current = head;
    while (current != nullptr) 
	{
        GNode *next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
}
GraphLL::~GraphLL()
{
    GNode *current = head;
    while (current != nullptr) {
        GNode *next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
}
