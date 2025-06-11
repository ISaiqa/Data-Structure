#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "PNode.h"
#include <iostream>
using namespace std;

template <class T>
class PriorityQueue {
private:
    PNode<T>* rear;
    PNode<T>* front;
public:
    PriorityQueue() {
        rear = front = 0;
    }
    ~PriorityQueue();
    void addSorted(T vertex, float priority);
    T dequeue();
    bool isEmpty();
    T frontValue();
    T rearValue();
};

template <class T>
PriorityQueue<T>::~PriorityQueue() {
    while (front != 0) {
        PNode<T>* temp = front;
        front = front->getNext();
        delete temp;
    }
    rear = 0;
}

template <class T>
bool PriorityQueue<T>::isEmpty() {
    if (front == 0 && rear == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
T PriorityQueue<T>::frontValue() {
    if (isEmpty()) {
        cerr << "Queue is empty!" << endl;
        return T(); // Default value
    }
    else {
        return front->getVertex();
    }
}

template <class T>
T PriorityQueue<T>::rearValue() {
    if (isEmpty()) {
        cerr << "Queue is empty!" << endl;
        return T(); // Default value
    }
    else {
        return rear->getVertex();
    }
}

template <class T>
T PriorityQueue<T>::dequeue() {
    if (rear == 0 && front == 0) {
        cerr << "List is empty" << endl;
        return T(); // Default value
    }
    else if (rear == front) {
        T vertex = rear->getVertex();
        delete rear;
        rear = front = 0;
        return vertex;
    }
    else {
        T vertex = front->getVertex();
        PNode<T>* i = front->getNext();
        delete front;
        front = i;
        return vertex;
    }
}

template <class T>
void PriorityQueue<T>::addSorted(T vertex, float priority) {
    PNode<T>* n = new PNode<T>(vertex, priority);
    if (front == 0 && rear == 0) { // First element
        front = rear = n;
    }
    else if (front->getPriority() >= priority) { // Add before front
        n->setNext(front);
        front = n;
    }
    else if (priority > rear->getPriority()) { // Add after rear
        rear->setNext(n);
        rear = n;
    }
    else { // Insert in middle
        PNode<T>* i = front;
        while (i->getNext() != 0 && i->getNext()->getPriority() <= priority) {
            i = i->getNext();
        }
        n->setNext(i->getNext());
        i->setNext(n);
    }
}

#endif