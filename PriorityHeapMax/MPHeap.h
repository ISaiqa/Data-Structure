#include<iostream>
using namespace std;
template <class T>

class MPHeap
{
private:
    int size;
    int capacity;
    T* heap; 
public:
	
    MPHeap(int capacity = 5)
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
    void heapify(T arr[], int n);
    void heapSort(T arr[], int n);
};

template <class T>
void MPHeap<T>::reheapifyUpward(int start)
{
    if (start > 1)
    {
        int parent = start / 2;
        if (heap[parent].priority <= heap[start].priority) // Max-heap by priority
        {
            swap(parent, start);
            reheapifyUpward(parent);
        }
    }
}

template <class T>
void MPHeap<T>::reheapifyDownward(int start)
{
    if (2 * start <= size)
    {
        int index = 2 * start;
        if (2 * start + 1 <= size && heap[2 * start].priority < heap[2 * start + 1].priority)
        {
            index = 2 * start + 1;
        }
        if (heap[start].priority < heap[index].priority)
        {
            swap(index, start);
            reheapifyDownward(index);
        }
    }
}

template <class T>
void MPHeap<T>::insert(T element)
{
    if (size >= capacity)
    {
        capacity *= 2;
        T* newHeap = new T[capacity + 1];
        for (int i = 0; i <= size; i++)
            newHeap[i] = heap[i];
        delete[] heap;
        heap = newHeap;
    }
    size++;
    heap[size] = element;
    reheapifyUpward(size);
}

template <class T>
T MPHeap<T>::remove()
{
    if (size == 0)
    {
        cerr << "Heap is empty" << endl;
        return T();
    }
    T element = heap[1];
    heap[1] = heap[size];
    size--;
    if (size > 0)
        reheapifyDownward(1);
    return element;
}

template <class T>
bool MPHeap<T>::isEmpty()
{
    return size == 0;
}

template <class T>
bool MPHeap<T>::isFull()
{
    return size == capacity;
}

template <class T>
void MPHeap<T>::swap(int i, int j)
{
    T temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

template <class T>
T MPHeap<T>::getRoot()
{
    if (isEmpty())
        return T();
    return heap[1];
}



template <class T>
void MPHeap<T>::heapify(T arr[], int n)
{
    if (n > capacity)
    {
        delete[] heap;
        capacity = n * 2;
        heap = new T[capacity + 1];
    }
    size = n;
    for (int i = 0; i < n; i++)
        heap[i + 1] = arr[i];
    int index = n / 2;
    for (int i = index; i >= 1; i--)
        reheapifyDownward(i);
}

template <class T>
void MPHeap<T>::heapSort(T arr[], int n)
{
    int OSize = size;
    heapify(arr, n);
    for (int i = size; i > 1; i--)
    {
        swap(1, i);
        size--;
        reheapifyDownward(1);
    }
    size = OSize;
    for (int i = 0; i < n; i++)
        arr[i] = heap[i + 1];
}