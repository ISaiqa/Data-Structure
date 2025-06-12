#include <iostream>
#include"CircularQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	CircularQueue <int> q1(5);
	//cout<<q1.isEmpty()<<endl;
	q1.enqueue(21);
	q1.enqueue(2970);
	q1.enqueue(25);
	q1.enqueue(23);
	q1.enqueue(29);
	cout<<q1.dequeue()<<"out"<<endl;
	cout<<q1.dequeue()<<"out"<<endl;
	cout<<q1.dequeue()<<"out"<<endl;
	
	
	q1.enqueue(35);
	q1.enqueue(54);
	q1.enqueue(90);
	
	//cout<<q1.isFull()<<endl;
	while(!q1.isEmpty())
	{
		cout<<q1.dequeue()<<endl;
	}
	return 0;
}