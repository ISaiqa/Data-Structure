#include <iostream>
#include"LinkedQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	LinkedQueue<int> q1; // size=5,rear=-1,front=-1
	q1.enqueue(15); 
	q1.enqueue(25);
	q1.enqueue(7);
	q1.enqueue(11);
	q1.enqueue(19);
	q1.enqueue(120);
	q1.enqueue(1); 
	q1.enqueue(9);
	q1.enqueue(70);
	q1.enqueue(13);
	q1.enqueue(89);
	q1.enqueue(12);
	
	cout<<q1.inList(9);
	cout<<"Front value:"<<q1.frontValue()<<endl;
	cout<<"Rear value:"<<q1.rearValue()<<endl;
	cout<<"Remove element from front "<<q1.dequeue()<<endl;
	while(!q1.isEmpty())
	{
		cout<<q1.dequeue();
		cout<<"\t";
	}
	return 0;
}