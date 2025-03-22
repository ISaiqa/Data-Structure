#include<iostream>
using namespace std;
class Book
{
	private :
		int BookID;
		string title;
		string author;
		double price;
	public :
		Book(int BookID=0,string title="",string author="",double price=0.0)
		{
			this->BookID = BookID;
        	this->title = title;
        	this->author = author;
        	this->price = price;
		}// constructor
		void setBookID(int BookID) ;
		void setTitle(string title);
		void setAuthor(string author);
		void setPrice(double price);
		int getBookID();
		string getTitle() ;
		string getAuthor();
		double getPrice() ;
		void display();
		
}; //end of book class
//implementation of class book 
//setters
void  Book::setBookID(int BookID) 
{
        this->BookID = BookID;
}
    
void  Book::setTitle(string title)
 {
        this->title = title;
 }
    
void  Book ::setAuthor(string author) 
{
        this->author = author;
}
    
 void Book:: setPrice(double price) 
{
        this->price = price;
}
    
 // Getters
int  Book:: getBookID() 
{
        return this->BookID;
}
    
string Book:: getTitle() 
{
        return this->title;
}
    
 string Book:: getAuthor() 
{
        return this->author;
}
    
double Book:: getPrice() 
{
        return this->price;
}
void Book :: display()
{
	    cout << "Book ID: " << this->BookID << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Price: PKR " << this->price << endl;
        
}// display