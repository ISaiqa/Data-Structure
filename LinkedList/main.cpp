#include <iostream>
#include"LinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	LinkedList<int> list1;
	list1.addToTail(3);
	list1.addToTail(7);
	list1.addToTail(1);
	list1.addToTail(5);
	list1.display(); 
	list1.deleteBySearch(7);
//	list1.deleteFromTail();
	 list1.display();
	cout<<endl;
//	cout<<list1.Search(7);
	cout<<endl;
//	cout<<list1.Search(19);
	LinkedList<char> list2;
	list2.addToTail('I');
	list2.addToTail('f');
	list2.addToTail('f');
	list2.addToTail('a');
	list2.addToTail('t');
	list2.display();
	list2.deleteFromTail();
	list2.display();
	LinkedList<string> list3;
	list3.addToTail("My");
	list3.addToTail("name");
	list3.addToTail("is");
	list3.addToTail("Iffat");
    list3.display();
   //list3.deleteFromTail();
  // list3.deleteFromHead();
 //  list3.display();
   // list3.deleteFromTail();
   list3.deleteBySearch("is");
    list3.display();
    cout<<"\n";
    list3.addBeforeElement("name","is");
    list3.addBeforeElement("My","Hello:");
    list3.deleteBySearch("is");
    
    list3.addBeforeElement("Iffat","is");
    list3.addAfterElement("Iffat" ,"Mir");
    list3.display();
	return 0;
}