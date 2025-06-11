#include<iostream>
using namespace std;

template <class T>
class Queue
{
	private:
		int rear;
		int front;
		int size;
		T *arr;
	public:
		Queue(int size=5)
		{
			this->size=size;
			rear=-1;
			front=-1;
			arr=new T(size);
		}
		void enqueue(T element);
		T dequeue();
		bool isFull();
		bool isEmpty();
		T rearValue();
		T frontValue();
			
	
};
template <class T>
void Queue<T> ::enqueue(T element)
{
	if (rear==size-1)
	{
		cerr<<"Queue is full!"<<endl;
		return;
		
	}
	else if(rear==-1 && front==-1) // adding first element
	{
		rear++; // rear=0
		front++; //front=0
		arr[rear]=element;
	}
	else //partially filled
	{// we always add element at rear or at the end
		rear++;
		arr[rear]=element;
	}
}
template <class T>
T Queue<T> ::dequeue()
{
	if(rear==-1 && front==-1) //queue is empty
	{//as queue is empty we cant remove anything
		cerr<<"Queue is empty";
	}
	else if (front!=rear) // front!=rear || front <rear
	{//we remove elements always from front
		T element=arr[front];
		front++;
		return element;
	}
	else if (rear==front)
	{//only one element was there so 
		T element=arr[front];
		rear=-1;
		front=-1;
		return element;
	}
}
template <class T>
bool Queue<T> :: isEmpty()
{
	return rear==-1 && front==-1;
}
template <class T>
bool Queue<T> :: isFull()
{
	return rear==size-1;
}
template <class T>
T Queue<T> :: frontValue()
{
	if(rear==-1 && front ==-1)
	{
		cerr<<"Queue is empty!";
		return;
	}
	else 
		return arr[front];
}
template <class T>
T Queue <T> :: rearValue() 
{
	if(isEmpty())
	{
		cerr<<"Queue is empty";
	}
	else 
		return arr[rear];
}
