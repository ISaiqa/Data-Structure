#include <iostream>
#include<conio.h>
#include "BookLinkedList.h"
//#include "Book.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
    int choice;
    int bookID;
    Node<Book>* foundNode;
    BookLinkedList <Book > BookInventory;
    BookLinkedList <Book > PersonalCollection;
    BookInventory.loadFromFile("Books.txt");
    cout << "\n=== Initial Book Inventory ===" << endl; 
    BookInventory.display();
   
    do
    {
        cout << "\n=== Menu Options ===\n" 
             << "1 - Add a book to your personal collection\n"
             << "2 - Remove a book from your personal collection\n"
             << "3 - Display the full book inventory\n" 
             << "0 - View summary report and exit\n" 
             << "Please enter your choice (0-3): "; 
        if(cin>>choice)
   
        switch(choice)
        {
            case 1:
                cout << "Enter the Book ID to add to your collection: "; 
                cin>>bookID;
                foundNode = BookInventory.SearchByID(bookID);
                if(foundNode==0)
                {
                    cout << "\tError: Book ID " << bookID << " not found in inventory!" << endl; // Modified: Added ID for clarity
                }
                else if(foundNode==PersonalCollection.SearchByID(bookID))
                {
                    cout << "\tNotice: Book ID " << bookID << " is already in your collection!" << endl; 
                    PersonalCollection.display();
                }
                else
                {
                    PersonalCollection.addToTail(foundNode->getInfo());
                    cout << "\tSuccess: Book ID " << bookID << " added to your collection!" << endl; 
                    cout << "\t=== Your Updated Collection ===" << endl; 
                    PersonalCollection.display();
                }
                break;
            case 2:
                cout << "Enter the Book ID to remove from your collection: "; 
                cin>>bookID;
                foundNode = PersonalCollection.SearchByID(bookID);
                if(foundNode==0)
                {
                    cout << "\tError: Book ID " << bookID << " not found in your collection!" << endl; 
                 }
				else
                {
                    PersonalCollection.removeSelectedBook(bookID);
                    cout << "\tSuccess: Book ID " << bookID << " removed from your collection!" << endl; 
                    cout << "\t=== Your Updated Collection ===" << endl; 
                    PersonalCollection.display();
                }
                break;
            case 3:
                cout << "\n=== Full Book Inventory ===" << endl; 
                BookInventory.display();
                break;
            case 0:
                cout << "\n=== Summary Report of Your Collection ===\n"; 
                PersonalCollection.display();
                cout << "Total Amount Spent: PKR " << PersonalCollection.total() << endl; 
                cout << "Thank you for using the Library System. Exiting now!\n"; 
                //exit(-1);
               return 0;
               //break;
            default: 
                cout << "\tInvalid Choice! Please select 0, 1, 2, or 3." << endl; 
        } // switch
    } // do
    while(true);
   getch();
    return 0;
}