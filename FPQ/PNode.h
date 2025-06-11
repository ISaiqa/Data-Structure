#ifndef PNODE_H
#define PNODE_H
#include <iostream>
using namespace std;

template <class T>
class PNode {
private:
    T vertex;
    float priority;
    PNode<T>* next;
public:
    PNode(T v, float p, PNode<T>* n = 0) 
	{
        this->vertex = v;
        this->priority = p;
        this->next = n;
    }
    void setPriority(float priority);
    float getPriority();
    void setVertex(T v);
    T getVertex();
    void setNext(PNode<T>* n);
    PNode<T>* getNext();
    void display();
};

template <class T>
void PNode<T>::setPriority(float priority) {
    this->priority = priority;
}

template <class T>
float PNode<T>::getPriority() {
    return this->priority;
}

template <class T>
void PNode<T>::setVertex(T v) {
    this->vertex = v;
}

template <class T>
T PNode<T>::getVertex() {
    return this->vertex;
}

template <class T>
void PNode<T>::setNext(PNode<T>* n) {
    this->next = n;
}

template <class T>
PNode<T>* PNode<T>::getNext() {
    return this->next;
}

template <class T>
void PNode<T>::display() {
    cout << "[" << this->priority << "] " << this->vertex;
}

#endif