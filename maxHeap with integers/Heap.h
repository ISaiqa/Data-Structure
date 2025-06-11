#include<iostream>
using namespace std;

template <class T>
class Heap
{
private:
    int size;
    int capacity;
    T* heap; 
public:
    Heap(int capacity = 5)
    {
        this->size = 0;
        this->capacity = capacity;
        heap = new T[capacity + 1]; // Allocate memory for 1-based indexing
    }
   
    void insert(T element);
    T remove();
    void reheapifyUpward(int start); // Add parameter to match implementation
    void reheapifyDownward(int start); // Add parameter to match implementation
    void swap(int i, int j);
    bool isEmpty();
    bool isFull();
    T getRoot();
    void display();
    void heapify(T arr[],int n);
    void heapSort(T arr[],int n);
    
};
template <class T>
void Heap<T>::heapSort(T arr[],int n)
{
	int OSize=size;
	heapify(arr,n);
	for (int i=size;i>1;i--)
	{
		swap(1,i);
		size--;
		reheapifyDownward(1);
	}
	size=OSize;
	for (int i=0;i<n;i++)
	{
		arr[i]=heap[i+1];
	}
	
}
template <class T>
void Heap<T>::heapify(T arr[], int n) 
{
    // Resize internal heap if needed
    if (n > capacity) 
	{
        delete[] heap;
        capacity = n * 2;
        heap = new T[capacity + 1]; // +1 for 1-based indexing
    } //not needed as such 
    
    size = n;
    // Copy elements to internal heap (1-based index)
    for (int i = 0; i < n; i++) 
	{
        heap[i + 1] = arr[i];
    }
    
    // Start from last parent node (n/2) and move to root
    int index = n / 2; // Parent of last node
    for (int i = index; i >= 1; i--) 
	{
        reheapifyDownward(i);
    }
}
template <class T>
T Heap<T>::getRoot()
{
	if (isEmpty())
		return 0;
	else 
		return heap[1];
}

template <class T>
bool Heap<T>::isEmpty()
{
    return size == 0;
}

template <class T>
bool Heap<T>::isFull()
{
    return size == capacity;
}
template <class T>
void Heap<T>::swap(int i, int j)
{
    T temp = heap[i]; // Initialize temp properly
    heap[i] = heap[j];
    heap[j] = temp;
}

template <class T>
void Heap<T>::reheapifyUpward(int start)
{
    if (start > 1)  //it is not a root node then we will perform the comparisons
    {
        int parent = start / 2; //get parent of the starting index
        if (heap[parent] <= heap[start]) // Max-heap: parent should be >= child then we need to swap 
        {//>=for min heap means only swap if parent is greater then start in min heap parent should be <= child so keep going till condition is met
            swap(parent, start);
            reheapifyUpward(parent);
        }
    }
}

template <class T>
void Heap<T>::reheapifyDownward(int start)
{
    if (2 * start <= size) // Check if left child exists //it means it is not a leaf node
    {//we check left child because it is complete binary search tree so missing nodes could be on right side never on left side
        int index = 2 * start; // Start with left child
        if (2 * start + 1 <= size && heap[2 * start] < heap[2 * start + 1]) // Check right child
        {
            index = 2 * start + 1; // Use right child if larger
        }
        /* alternatively we can use an if else for this task such as
        if(2*start<=size)
        {
         	index=2*start
        	if(2*start+1<=size)
        	{
        		ifheap[2*start+1]>=heap[2*start]
        			index=2*start+1
        	}
    	}
        
       	*/
        if (heap[start] < heap[index]) // Max-heap: parent should be > child
        {
            swap(index, start);    //keep swapping until order property is satisfied
            reheapifyDownward(index);
        }
    }
}

template <class T>
void Heap<T>::insert(T element)
{
    if (size >= capacity) // Check capacity
    {
        capacity *= 2; // Double the capacity
        T* newHeap = new T[capacity + 1];
        for (int i = 0; i <= size; i++)
            newHeap[i] = heap[i];
        delete[] heap; // Free old array
        heap = newHeap;
    }
    /*
    if (size >= capacity) // Check if heap is full
    {
        cerr << "Error: Heap is full, cannot insert more elements." << std::endl;
        return; // Exit the function
    }
	
	*/
    size++;
    heap[size] = element;
    reheapifyUpward(size);
}

template <class T>
T Heap<T>::remove()
{
    if (size == 0)
    {
    	cerr<<("Heap is empty");
    	return 0;
	}
	T element = heap[1];
    heap[1] = heap[size];
    size--;
    if (size > 0) // Only reheapify if heap is not empty
        reheapifyDownward(1); //  use 1 for 1-based indexing
    return element;
}
/*
#include <iostream>
using namespace std;

template <class T>
class Heap
{
private:
    int size;
    int capacity;
    T* heap; 
public:
    Heap(int capacity = 5)
    {
        this->size = 0;
        this->capacity = capacity;
        heap = new T[capacity + 1]; // Allocate memory for 1-based indexing
    }
   
    void insert(T element);
    T remove();
    void reheapifyUpward(int start);
    void reheapifyDownward(int start);
    void swap(int i, int j);
    bool isEmpty();
    bool isFull();
    T getRoot();
    void display();
    void heapify(T arr[], int n);
    void heapSort(T arr[], int n);
    
};

template <class T>
void Heap<T>::heapSort(T arr[], int n)
{
    int OSize = size;
    heapify(arr, n);
    for (int i = size; i > 1; i--)
    {
        swap(1, i); // Smallest element to end
        size--;
        reheapifyDownward(1);
    }
    size = OSize;
    // Reverse the array to get ascending order
    for (int i = 0; i < n; i++)
    {
        arr[i] = heap[n - i]; // Copy from end to start
    }
}

template <class T>
void Heap<T>::heapify(T arr[], int n) 
{
    // Resize internal heap if needed
    if (n > capacity) 
    {
        delete[] heap;
        capacity = n * 2;
        heap = new T[capacity + 1]; // +1 for 1-based indexing
    }
    
    size = n;
    // Copy elements to internal heap (1-based index)
    for (int i = 0; i < n; i++) 
    {
        heap[i + 1] = arr[i];
    }
    
    // Start from last parent node (n/2) and move to root
    int index = n / 2; // Parent of last node
    for (int i = index; i >= 1; i--) 
    {
        reheapifyDownward(i); // Build min-heap
    }
}

template <class T>
T Heap<T>::getRoot()
{
    if (isEmpty())
        return 0;
    else 
        return heap[1];
}

template <class T>
bool Heap<T>::isEmpty()
{
    return size == 0;
}

template <class T>
bool Heap<T>::isFull()
{
    return size == capacity;
}

template <class T>
void Heap<T>::swap(int i, int j)
{
    T temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

template <class T>
void Heap<T>::reheapifyUpward(int start)
{
    if (start > 1) // Not the root node
    {
        int parent = start / 2;
        if (heap[parent] > heap[start]) // Min-heap: parent should be <= child
        {
            swap(parent, start);
            reheapifyUpward(parent);
        }
    }
}

template <class T>
void Heap<T>::reheapifyDownward(int start)
{
    if (2 * start <= size) // Check if left child exists
    {
        int index = 2 * start; // Start with left child
        if (2 * start + 1 <= size && heap[2 * start] > heap[2 * start + 1]) // Check right child
        {
            index = 2 * start + 1; // Use right child if smaller
        }
        if (heap[start] > heap[index]) // Min-heap: parent should be <= child
        {
            swap(index, start);
            reheapifyDownward(index);
        }
    }
}

template <class T>
void Heap<T>::insert(T element)
{
    if (size >= capacity) // Check capacity
    {
        capacity *= 2; // Double the capacity
        T* newHeap = new T[capacity + 1];
        for (int i = 0; i <= size; i++)
            newHeap[i] = heap[i];
        delete[] heap; // Free old array
        heap = newHeap;
    }
    size++;
    heap[size] = element;
    reheapifyUpward(size);
}

template <class T>
T Heap<T>::remove()
{
    if (size == 0)
    {
        cerr << "Heap is empty" << endl;
        return 0;
    }
    T element = heap[1];
    heap[1] = heap[size];
    size--;
    if (size > 0) // Only reheapify if heap is not empty
        reheapifyDownward(1);
    return element;
}

*/