#include <iostream>
#include"TWLL.H"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	TWLL <int> list1;
	list1.addToHead(12);
	list1.addToHead(11);
	list1.addToHead(10);
	list1.addToHead(19);
	list1.addToTail(23);
	
	list1.display();
	cout<<"\n"<<list1.Search(19);
	list1.deleteFromTail();
	list1.display();
	cout<<"\n";
	list1.deleteBySearch(110);
	list1.display();
	list1.addBeforeElement(10,27);
	cout<<"\n";
	list1.display();
	return 0;
}