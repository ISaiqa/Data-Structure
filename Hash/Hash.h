#include <iostream>
//#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedList\LinkedList.h"
#include"C:\Users\abc\OneDrive\Desktop\LinkedList1\LinkedList.h"
using namespace std;
class Hash
{
	private:
		LinkedList<int> **arr;
		int size;
	public:
		Hash(int size=5)
		{
			this->size = size;
    		arr = new LinkedList<int>*[size]; // Allocate array of pointers
    		for (int i = 0; i < size; i++)
    		{
        		arr[i] = nullptr; // Initialize each element to nullptr
    		}
		}
		~Hash()
		{
    		for (int i = 0; i < size; i++)
    		{
        		if (arr[i] != nullptr)
        		{
            		delete arr[i]; // Delete each LinkedList
        		}		
    	}
    delete[] arr; // Delete the array of pointers
}
		int hashF(int key);
		void insertV(int key);
		bool search(int key);
		void removeV(int key);
		void displayAll();
		int count();
		bool isEmpty();
		void clear();
		double loadFactor();
	
	
	
};
double Hash::loadFactor()
{
	int c=count();
	return (double)c/size;
}

void Hash::clear()
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]!=nullptr)
		{
		
			delete arr[i];
			arr[i]=nullptr;
		}
	}
}
bool Hash::isEmpty()
{

	for(int i=0;i<size ;i++)
	{
		if(arr[i]->getHead()!=nullptr)
			return false;
	}
	return true;
}
int Hash::hashF(int key)
{
	return key%size;
}

void Hash::insertV(int key)
{
	int i=hashF(key);
	if (arr[i]==nullptr)
	{
		arr[i]=new LinkedList<int>();
	}
	arr[i]->addToHead(key);
}

bool Hash::search(int key)
{
	int i= hashF(key);
	if (arr[i] == nullptr)
    {
        return false; // No list at this index, key not found
    }
	Node<int>* s= arr[i]->Search(key);
	if(s==0)
	{
		return false;
	}
	else
		return true;
}

void Hash::removeV(int key)
{
	int i=hashF(key);
	if(arr[i]==nullptr)
	{
		cout<<"Not Found";
		
		
	}
	else if(arr[i]->deleteBySearch(key))
		cout<<"Removed Successfully";
	else 
		cout<<"Key not found";
	
}
void Hash::displayAll()
{
	
	for(int i=0;i<size;i++)
	{
		if(arr[i]==nullptr)
		{
			cout<<" Empty at ["<<i<<"]\t";
		}
		else
		{
			cout<<"\tAt ["<<i<<"]( ";
			arr[i]->display();
			cout<<" )";
		}
			
	}

}
int Hash::count()
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==nullptr)
		{
			continue;
		}
		else
		{
			Node <int>* j=arr[i]->getHead();
			while(j!=0)
			{
				j=j->getNext();
				count++;
			}
		}
	}
	return count;
}