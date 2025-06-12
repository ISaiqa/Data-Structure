#include<iostream>
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedQueue\LinkedQueue.h"
using namespace std;
template <class T>
class PQ
{
	private:
		int levels;
		LinkedQueue<T> *pr;
	public:
		PQ(int levels=5)
		{
			this->levels=levels;
			pr=new LinkedQueue<T>[levels];
		}
		void enqueue(T element,int priority);
		T dequeue();
	
    	bool isEmpty() ;
    	T frontValue() ;
    	T rearValue() ;
		
	
};
template <class T>
void PQ<T>::enqueue(T element,int priority)
{
	if(priority>=0 && priority<levels)
	{
		pr[priority].enqueue(element);
		return;
	}
	else 
	{
		cerr<<"Invlid Priority!";
		return;
	}
}

template <class T>
T PQ<T>::dequeue()
{
	for (int i=0;i<levels;i++)
	{
		if(!pr[i].isEmpty())
		{
			T element=pr[i].dequeue();
			return element;
		}
	}
	cerr<<"Queue is Empty!";
	return T();
}


template <class T>
bool PQ<T>::isEmpty()
{
    for (int i = 0; i < levels; i++)
    {
        if (!pr[i].isEmpty())
            return false;
    }
    return true;
}

template <class T>
T PQ<T>::frontValue() 
{
    for (int i = 0; i < levels; i++)
    {
        if (!pr[i].isEmpty())
            return pr[i].frontValue();
    }
    cerr << "Error: Priority queue is empty!" << endl;
    return T();
}

template <class T>
T PQ<T>::rearValue() 
{
    for (int i = 0; i < levels; i++)
    {
        if (!pr[i].isEmpty())
            return pr[i].rearValue();
    }
    cerr << "Error: Priority queue is empty!" <<endl;
    return T();
}

