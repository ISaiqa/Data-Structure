#include <iostream>
#include "Graph.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) 
{
	
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(0, 5);
	g.addEdge(1, 3);
	g.printGraph();
	g.DFS(0);
	
	return 0;
}
