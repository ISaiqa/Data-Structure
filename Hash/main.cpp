#include <iostream>
#include "Hash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Hash h;
	h.insertV(12);
	h.insertV(89);
	h.insertV(23);
	h.insertV(102);
	h.insertV(9);
	cout<<"Inserted";
//	cout<<h.search(12)<<endl;
//	cout<<h.search(10)<<endl;
	

	h.displayAll();
//	cout<<"\n";
	h.clear();
	cout<<"\n"<<h.loadFactor();
	//h.displayAll();
//	cout<<h.count();
//	cout<<"\n"<<h.isEmpty();	
	return 0;
}