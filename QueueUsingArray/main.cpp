#include <iostream>
#include"Queue.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Queue<int> q(5); // size=5,rear=-1,front=-1
	q.enqueue(15); 
	q.enqueue(25);
	q.enqueue(7);
	q.enqueue(11);
	q.enqueue(19);
	q.enqueue(19);
	
	cout<<"Dequeue"<<q.dequeue()<<endl;
	while(!q.isEmpty())
	{
		cout<<q.dequeue();
		cout<<"\t";
	}
	cout<<q.dequeue()<<endl;
	
	
	Queue<int>  q1(5);
	//cout<<q1.isEmpty()<<endl;
	q1.enqueue(21);
	q1.enqueue(2970);
	q1.enqueue(25);
	q1.enqueue(23);
	q1.enqueue(29);
	cout<<q1.inList(0);
	
	
//	q1.enqueue(35);
//	q1.enqueue(54);
//	q1.enqueue(90);
	return 0;
}