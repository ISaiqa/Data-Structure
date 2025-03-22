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
	ifstream file (FileName); //opens the file
	if(!file.is_open()) //check if file could not be opened 
	{
		cout <<"Error! Could not open file:"<<FileName;
		return;
	}
	string line; 
	while(getline(file,line)) // reads each line
	{
		stringstream ss (line) ;// parse each line 
		int bookID;
        string title, author;
        double price;
        string temp; // Temporary string for parsing
        // to parse comma seperated values
        getline(ss,temp,',');
        bookID = stoi(temp);    // Convert to int
        getline(ss, title, ','); // Read title
        getline(ss, author, ','); // Read author
        getline(ss, temp);       // Read price (no comma after last field)
        price = stod(temp);      // Convert to double
        // Create a new Book object and add it to the list
        Book book(bookID, title, author, price);
        this->addToTail(book); // Add to the head of the list
        }

    file.close(); // Close the file
    cout << "Books successfully loaded from " << FileName << endl;
}
	


