#include <iostream>
#include <string>
#include "C:\Users\abc\OneDrive\Desktop\LinkedList1\LinkedList.h"
using namespace std;

template <class T>
class Hash
{
	private:
		LinkedList<T> **arr;
		int size;
	public:
		Hash(int k=5)
		{
			this->size = k;
    		arr = new LinkedList<T>*[size]; // Allocate array of pointers
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
		int hashF(T key);
		void insertV(T key);
		bool search(T key);
		void removeV(T key);
		void displayAll();
		int count();
		bool isEmpty();
		void clear();
		double loadFactor();
};

template <class T>
double Hash<T>::loadFactor()
{
	int c=count();
	return (double)c/size;
}

template <class T>
void Hash<T>::clear()
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

template <class T>
bool Hash<T>::isEmpty()
{
	for(int i=0;i<size ;i++)
	{
		if(arr[i]->getHead()!=nullptr)
			return false;
	}
	return true;
}

template <class T>
void Hash<T>::insertV(T key)
{
	int i=hashF(key);
	if (arr[i]==nullptr)
	{
		arr[i]=new LinkedList<T>();
	}
	arr[i]->addToHead(key);
}

template <class T>
bool Hash<T>::search(T key)
{
	int i= hashF(key);
	if (arr[i] == nullptr)
    {
        return false; // No list at this index, key not found
    }
	Node<T>* s= arr[i]->Search(key);
	if(s==0)
	{
		return false;
	}
	else
		return true;
}

template <class T>
void Hash<T>::removeV(T key)
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

template <class T>
void Hash<T>::displayAll()
{
	cout<<"| ";
	for(int i=0;i<size;i++)
	{
		
		if(arr[i]==nullptr)
		{
			cout<<" At ["<<i<<"] (null)";
		}
		else
		{
			cout<<" At ["<<i<<"]( ";
			arr[i]->display();
			cout<<" )";
		}
		
	}
	cout<<"| ";
}

template <class T>
int Hash<T>::count()
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
			Node <T>* j=arr[i]->getHead();
			while(j!=0)
			{
				j=j->getNext();
				count++;
			}
		}
	}
	return count;
}

// Template specializations for hashF
template <>
int Hash<int>::hashF(int key)
{
	//diviosn method
	return key%size;
	//multiplication method
	//const double A = (sqrt(5)-1)/2; // Golden ratio
    //return (int)(size * (key * A - (int)(key * A)));
    
    
}

template <>
int Hash<char>::hashF(char key)
{
	return key%size; // ASCII value mod size
}

template <>
int Hash<string>::hashF(string key)
{
	int sum=0;
	for (char c : key)
	{
		sum += c; // ASCII sum
	}
	return sum%size;
}

/*
/ Shift Folding Method 
template <>
int HashSet<int>::hashF(int key)
{
    int sum=0;                    // Start with sum of 0 to add parts
    while(key>0)                  // Keep going until no digits left
    {
        sum+=key%100;             // Get last 2 digits as a part
        key/=100;                 // Remove last 2 digits
    }
    return sum%size;              // Return sum mod table size for index
}

template <>
int HashSet<char>::hashF(char key)
{
    return (int)key%size;         // Use ASCII value mod table size (no parts)
}

template <>
int HashSet<string>::hashF(string key)
{
    int sum=0;                    // Start with sum of 0
    int addressSize=3;            // Set part size to 3 characters
    for(int i=0;i<key.length();i+=addressSize) // Loop through string in chunks
    {
        string part=key.substr(i,addressSize); // Get substring of addressSize
        int partValue=0;          // Value for this part
        for(char c:part)          // Sum ASCII values of chars in part
            partValue+=c;
        sum+=partValue;           // Add part value to total sum
    }
    return sum%size;              // Return sum mod table size
}

/*
// Boundary Folding Method
template <>
int HashSet<int>::hashF(int key)
{
    int sum=0;                    // Start with sum of 0
    bool reverse=false;           // Track if part should be reversed
    while(key>0)                  // Keep going until no digits left
    {
        int part=key%100;         // Get last 2 digits as a part
        if(reverse)               // If reverse flag is true
        {
            part=(part%10)*10 + part/10; // Swap digits (e.g., 34 -> 43)
        }
        sum+=part;                // Add part to sum
        key/=100;                 // Remove last 2 digits
        reverse=!reverse;         // Toggle reverse for next part
    }
    return sum%size;              // Return sum mod table size
}

template <>
int HashSet<char>::hashF(char key)
{
    return (int)key%size;         // Use ASCII value mod table size (no parts)
}

template <>
int HashSet<string>::hashF(string key)
{
    int sum=0;                    // Start with sum of 0
    int addressSize=3;            // Set part size to 3 characters
    for(int i=0;i<key.length();i+=addressSize) // Loop through string in chunks
    {
        string part=key.substr(i,addressSize); // Get substring of addressSize
        int partValue=0;          // Value for this part
        for(char c:part)          // Sum ASCII values of chars in part
            partValue+=c;
        if(i/addressSize%2==1)    // Reverse alternate parts (every odd chunk)
        {
            int temp=partValue;   // Store original value
            partValue=0;          // Reset part value
            while(temp>0)         // Convert digits to reversed form
            {
                partValue=partValue*10+(temp%10); // Build reversed number
                temp/=10;
            }
        }
        sum+=partValue;           // Add part value to sum
    }
    return sum%size;              // Return sum mod table size
}
*/

/*
// Multiplication Method
template <>
int HashSet<int>::hashF(int key)
{
    const double A=(sqrt(5)-1)/2; // Use golden ratio (~0.618)
    double product=key*A;         // Multiply key by A
    double frac=product-(int)product; // Get fractional part
    return (int)(size*frac);      // Scale by table size, floor to index
}

template <>
int HashSet<char>::hashF(char key)
{
    const double A=(sqrt(5)-1)/2; // Use golden ratio
    double product=(int)key*A;    // Multiply ASCII value by A
    double frac=product-(int)product; // Get fractional part
    return (int)(size*frac);      // Scale by table size, floor
}

template <>
int HashSet<string>::hashF(string key)
{
    int sum=0;                    // Start with sum of 0
    for(char c:key)               // Loop through each character
        sum+=c;                   // Add ASCII value
    const double A=(sqrt(5)-1)/2; // Use golden ratio
    double product=sum*A;         // Multiply sum by A
    double frac=product-(int)product; // Get fractional part
    return (int)(size*frac);      // Scale by table size, floor
}
*/

/*
// Mid-Square Method
template <>
int HashSet<int>::hashF(int key)
{
    long long square=(long long)key*key; // Square the key
    int digits=(size<=1)?0:(int)log10(size); // Get digits based on table size
    long long divisor=(digits==0)?1:(long long)pow(10,digits); // Set divisor
    square/=divisor;              // Extract middle digits
    return square%size;            // Mod table size for index
}

template <>
int HashSet<char>::hashF(char key)
{
    long long square=(long long)key*key; // Square ASCII value
    int digits=(size<=1)?0:(int)log10(size); // Get digits based on size
    long long divisor=(digits==0)?1:(long long)pow(10,digits); // Set divisor
    square/=divisor;              // Extract middle digits
    return square%size;            // Mod table size
}

template <>
int HashSet<string>::hashF(string key)
{
    int sum=0;                    // Start with sum of 0
    for(char c:key)               // Loop through each character
        sum+=c;                   // Add ASCII value
    long long square=(long long)sum*sum; // Square the sum
    int digits=(size<=1)?0:(int)log10(size); // Get digits based on size
    long long divisor=(digits==0)?1:(long long)pow(10,digits+1); // Larger divisor
    square/=divisor;              // Extract middle digits
    return square%size;            // Mod table size
}
*/


*/