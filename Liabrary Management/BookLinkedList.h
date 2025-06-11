#include<iostream>
#include <fstream> // For file operations
#include <sstream> // For parsing lines
#include "Book.h"
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedList\LinkedList.h"
using namespace std;
template <class T>
class BookLinkedList : public LinkedList <T>
{
	public:
		void display();
		Node<T>* SearchByID(int BookID);
		double total ();
		void removeSelectedBook(int id);
		void loadFromFile(string FileName);
		
};// bookLinkedList child class of linkedlist class contains all its parameters
template <class T>
void BookLinkedList<T>::display()
{
	Node <T> *i= this->getHead();
	while(i!=0)
	{
		i->getInfo().display();
		i=i->getNext();
	}
}
template <class T>
double BookLinkedList<T>::total()
{
	Node <T> *i= this->getHead();
	double total=0.0;
	double price;
	while(i!=0)
	{
		price=i->getInfo().getPrice();
		total=total+price;
		i=i->getNext();
	}
	return total;
	
} //return total amount spent by adding price of individual book (nodes) in the list
template <class T>
 Node<T>* BookLinkedList<T>::SearchByID(int BookID)
 {
 	Node<T> *i=this->getHead();
 	while(i!=0 && i->getInfo().getBookID()!=BookID)
 	{
 		i=i->getNext(); 		
	}
	if(i==0)
	{
		return 0;
	}
	else
	{
		return i;
	}
 }
 template <class T>
void BookLinkedList<T>::removeSelectedBook(int id)
{
	Node<T> *reqID=SearchByID(id);
	if((this->getHead()==0&&this->getTail()==0)||reqID==0)
	{
		cerr<<"Error";
		return;
	}
	else if(this->getHead()==this->getTail())
	{
		this->deleteFromTail();
	}
	else if(this->getHead()==reqID)
	{
		this->deleteFromHead();
	}
	else if(this->getTail()==reqID)
	{
		this->deleteFromTail();
	}
	else
	{
		
		Node <T>*j=this->getHead();
		while (j->getNext()!=reqID)
		{
			j=j->getNext();
		}
		j->setNext(reqID->getNext());
		delete reqID;
	}
	
}

template <class T>
void BookLinkedList<T>::loadFromFile(string FileName)
{
    ifstream read(FileName);
    if (!read.is_open()) 
    {
        cout << "Error: Could not open " << FileName << "!" << endl;
        return;
    }

    int id;
    string title, author, line;
    double price;

    while (getline(read, line)) 
    {
        stringstream ss(line);
        string price_str;

        if (getline(ss, line, ',') && (stringstream(line) >> id))
        {
            if (getline(ss, title, ',') &&
                getline(ss, author, ',') &&
                getline(ss, price_str))
            {
                try 
                {
                    price = stod(price_str);
                    Book book(id, title, author, price);
                    this->addToTail(book);
                } 
                catch (const exception& e) 
                {
                    cout << "Error: Invalid price format for book ID " << id << " in " << FileName << endl;
                    continue;
                }
            }
            else 
            {
                cout << "Error: Invalid data format for book ID " << id << " in " << FileName << endl;
                continue;
            }
        }
        else 
        {
            cout << "Error: Invalid ID format in " << FileName << endl;
            continue;
        }
    }

    read.close();
    cout << "Books successfully loaded from " << FileName << endl;
}
	


