#include <iostream>
#include"BookLinkedList.h"
//#include"Book.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{

    int choice;
    int bookID;
    Node<Book>* foundNode;
    BookLinkedList <Book > BookInventory;
    BookLinkedList <Book > PersonalCollection;
    BookInventory.loadFromFile("Books.txt");
    cout << "\nBook Inventory:" << endl;
    BookInventory.display();
   
    do
    {
    cout << "Please select an option:\n"
     << "1 - Add a book to your personal collection\n"
     << "2 - Remove a book from your personal collection\n"
     << "3 - Display the list of available books in the inventory\n"
     << "0 - Generate a summary report of your collection and exit\n"
     << "Enter your choice (0-3): ";
    if(cin>>choice)
   
	
    switch(choice)
    {
    	case 1:
    		
    		cout << "Enter the Book ID to add to your personal collection: ";
    		cin>>bookID;
    		foundNode =BookInventory.SearchByID(bookID);
    		if(foundNode==0)
    		{
    			cout<<"\tBook is not found in inventory!"<<endl;
			}
			else if(foundNode==PersonalCollection.SearchByID(bookID))
			{
				cout <<"\t Book already added!"<<endl;
				PersonalCollection.display();
			}
    		else
    		{
    			PersonalCollection.addToTail(foundNode->getInfo());
    			cout<<"\tBook successfully added!"<<endl;
    			cout<<"\t Updated Collection now"<<endl;
    			PersonalCollection.display();
			}
			break;
    	case 2:
    		cout << "Enter the Book ID to remove from your personal collection: ";
    		cin>>bookID;
    			foundNode =PersonalCollection.SearchByID(bookID);
    		if(foundNode==0)
    		{
    			cout<<"\tBook not in your personal collection!"<<endl;
			}
    		else
			{
				PersonalCollection.removeSelectedBook(bookID);
    			cout<<"\tBook successfully removed!"<<endl;
    			cout<<"\t Updated Collection now"<<endl;
    			PersonalCollection.display();
			}
    		break;
    	case 3:
    		 cout << "\nBook Inventory:" << endl;
    		BookInventory.display();
    		break;
    	case 0:
    		cout << "Generating summary report for your collection:\n";
     		PersonalCollection.display();
	        cout<<"Total Amount Spent:PKR"<<PersonalCollection.total()<<endl;
     		cout<< "Thank you for using the system. Goodbye!\n";
     		exit(-1);
    		break;
    	default: 
    		cout<<"\tWrong Choice!"<<endl;
    	    break;
    			
    	}// switch
    }// do
    while(true);
    
	return 0;
}
