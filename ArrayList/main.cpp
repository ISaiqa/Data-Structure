#include <iostream>
#include"ArrayList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	ArrayList mylist(3);// currentIndex =0; capacity=10
	cout<<"capacity :";
	cout<<mylist.getCapacity()<<endl;
	mylist.insert(23);//[23]
	mylist.insert(28);//[23][40]
	mylist.insert(52);
	mylist.insert(23);//[23]
	mylist.insert(2);//[23][40]
	mylist.insert(0);
	mylist.insert(20);//[23]
	mylist.insert(98);//[23][40]
	mylist.insert(5);
	
//	mylist.resize();
	mylist.insert(7);
	
//		cout<<"capacity :";
//	cout<<mylist.getCapacity()<<endl;
	cout<<"Before Sorting:";
	mylist.display();
	//mylist.insertAt(2,66);
//	cout<<"\n";
//	mylist.display();
//	mylist.insertAt(1,0);
//		cout<<"\n";
	//mylist.display();
	//mylist.remove(3);
//		cout<<"\n";
//	mylist.display();
//	cout<<"\n "<<mylist.linearSearch(23);
//	cout<<"\n "<<mylist.linearSearch(0)<<endl;
//	cout<<mylist.largest()<<endl;
//	mylist.swap(1,4);
	mylist.quickSort();
	cout<<"\nAfter:";
	mylist.display();
	//cout<<endl<<mylist.BinarySearch(70);
	return 0;
}