#include <iostream>
#include "StudentLinkedList.h"
#include"Student.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	StudentLinkedList<Student* > list;
	Student *s1=new Student(1,"Iffat",3.8);
	Student *s2=new Student(2,"Rafia" ,3.77);
	list.addToHead(s1);
	list.addToTail(s2);
	list.display();
	// Search for a book and display it
    
	
	
	return 0;
}