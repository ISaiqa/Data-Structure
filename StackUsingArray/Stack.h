#include <iostream>
using namespace std;

template<class T>
class Stack
{
	private:
		int top;
		int size;
		T *arr;	
	public:
		Stack(int size=5)
		{
			this->top=-1;
			this->size=size;
			//arr=new T(size);
			arr=new T[size];
		}
		void push(T element);
		T pop();
		bool isEmpty();
		bool isFull();
		T topValue();
};

template<class T>
void Stack<T>::push(T element)
{
	if(top==size-1)
		cerr<<"Stack Overflow \n";
	else
	{
		top++;
		arr[top]=element;
		//arr[++top]=element;
	}
}//push

template<class T>
T Stack<T>::pop()
{
	if(top==-1)
	{
		cerr<<"Stack Underflow \n";
		return T();
			}
	else
	{
		T element=arr[top];
		top--;
		//T element=arr[top--];
		return element;
	}
}

template<class T>
bool Stack<T>::isEmpty()
{
	return top==-1;
}

template<class T>
bool Stack<T>::isFull()
{
	return top==size-1;
}

template<class T>
T Stack<T>::topValue()// peak
{
	if(top==-1)
		cerr<<"Stack undeflow \n";
	else
		return arr[top];
}
