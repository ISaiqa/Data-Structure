#include<iostream>
using namespace std;

template <class T>
class CircularQueue
{
	private:
		int rear;
		int front;
		int size;
		T *arr;
	public:
		CircularQueue(int size=5)
		{
			this->size=size;
			rear=-1;
			front=-1;
			arr=new T[size];
		}
		void enqueue(T element);
		T dequeue();
		bool isFull();
		bool isEmpty();
		T rearValue();
		T frontValue();
			
	
};
template <class T>
bool CircularQueue<T> :: isEmpty()
{
	return (rear==-1 && front==-1);
}
template <class T>
bool CircularQueue<T> :: isFull()
{
	return (rear+1)%size==front;
	//((front==0 && rear==size-1)||(rear+1==front));
}
template <class T>
void CircularQueue<T> ::enqueue(T element)
{
	if((rear+1)%size==front) // queue is full(front==0 && rear==size-1)||(rear+1==front)
	{
		cerr<<"Queue is full!";
		return;
	}
	else if(rear==-1 && front==-1)//rear==-1 && front ==-1 ,means quesu is empty and this is first slot
	{
		rear++;
		front++;
	}
//	else if(front>0 && rear==size-1)
//	{//we have a vacant slot at the front
//we will reset rear to zero 

//		rear=0;
//	}
//   >>if front==0 && rear>size
		//rear++
	else
	{
		//this condition here will do the task and reset rear to 0 if needed
		rear=(rear+1)%size;
	}
	arr[rear]=element;
	return;
}
template <class T>
T CircularQueue<T> ::dequeue()
{
	if(isEmpty())// rear==-1 && front==-1
	{
		cerr<<"Queue is empty!";
		return T();
	}
	T element=arr[front];
	if(front==rear && front!=-1) // if rear is once set to zero and this is the last elemnt
	{//we check front!=-1 cuz this is initial condition of queue
	//where rear and front are both equal
		//T element=arr[front];
		front=-1;
		rear=-1;
		//return element;
	}
	else if((front==size-1) && front >rear)// if rear once set to zero and some elements remain
	{//so we need to reset front also 
	//as we can see rear was once set to zero
		//T element=arr[front];
		front=0;
		//return element;
	}
	else 
	{
		//T element=arr[front];
		front++;
		//return element;
	}
	return element;
}
/*
template <class T>
void CircularQueue<T>::enqueue(T item)
{
    if (front == 0 && rear == size - 1) || (rear + 1 == front)
    {
        throw std::runtime_error("Queue overflow");
    }
    if (isEmpty()) // rear == -1 && front == -1
    {
        front = 0;
        rear = 0;
    }
    else if (rear == size - 1 && front > 0) // Vacant slots at beginning
    {
        rear = 0;
    }
    else // Normal case
    {
        rear++; // Simple increment
    }
    arr[rear] = item;
}*/
template <class T>
T CircularQueue<T> :: frontValue()
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
T CircularQueue <T> :: rearValue() 
{
	if(isEmpty())
	{
		cerr<<"Queue is empty";
	}
	else 
		return arr[rear];
}