#include <iostream>
#include"Queue.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Queue<int> q1(5); // size=5,rear=-1,front=-1
	q1.enqueue(15); 
	q1.enqueue(25);
	q1.enqueue(7);
	q1.enqueue(11);
	q1.enqueue(19);
	q1.enqueue(19);
	
	cout<<"Dequeue"<<q1.dequeue()<<endl;
	while(!q1.isEmpty())
	{
		cout<<q1.dequeue();
		cout<<"\t";
	}
	cout<<q1.dequeue();
	return 0;
}