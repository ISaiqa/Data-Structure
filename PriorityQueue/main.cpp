#include <iostream>
#include"PriorityQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	PriorityQueue<char> q1;
	q1.addSorted('b',2);
	q1.addSorted('c',3);
	q1.addSorted('a',1);
	while(!q1.isEmpty())
	{
		cout<<q1.dequeue()<<endl;
	}

	return 0;
}