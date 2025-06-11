#include<iostream>
using namespace std;

class GNode
{
	public:
		int info;
		float distance;
		GNode *next;
	public:
		GNode(int info=0,float distance=0,GNode *next=0)
		{
			this->info=info;
			this->next=next;
			this->distance=distance;
		}// constructor
		void setInfo(int info);
		void setNext(GNode *next);
		GNode* getNext();
		void setDistance(float distance);
		float getDistance();
		int getInfo();
		void display();
};// end of class
//Implementation of Node<T>.h
void GNode::setInfo(int info)
{
	this->info=info;
}//set info

int GNode::getInfo()
{
	return this->info;
}//get info

void GNode::setNext(GNode *next)
{
	this->next=next;
}//setnext

GNode* GNode:: getNext()
{
	return this-> next;
}//get Next
float GNode::getDistance()
{
	return this->distance;
}
void GNode::setDistance(float distance)
{
	this->distance=distance;
}
void GNode :: display()
{
	cout<<"|("<<this<<")|"<<this->info<<"|"<<this->next<<"|"<<endl;
	
}