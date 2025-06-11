#include <iostream>
#include"BST.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	BST<int> t1;
	
	t1.insert(70);
	t1.insert(80);
	t1.insert(60);
	t1.insert(62);
	t1.insert(30);
	t1.insert(92);
	t1.insert(75);
	t1.inOrderTraversal(t1.getRoot());
	cout<<endl;
	t1.recursiveDelete(t1.getRoot(),75);
	t1.inOrderTraversal(t1.getRoot());
	return 0;
}