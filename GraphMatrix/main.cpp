#include <iostream>
#include"Graph.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*/ Create a graph with 4 vertices
    Graph g(4);

    // Test addEdge
    g.addEdge(0, 1); // Edge 0 -> 1
    g.addEdge(0, 2); // Edge 0 -> 2
    g.addEdge(1, 2); // Edge 1 -> 2
    g.addEdge(2, 3); // Edge 2 -> 3

    // Print initial graph
    cout << "Initial Graph:" << endl;
    g.printGraph();

    // Test removeEdge
    g.removeEdge(0, 1); // Remove edge 0 -> 1

    // Print graph after removal
    cout << "\n\nGraph after removing edge 0 -> 1:" << endl;
    g.printGraph();

    // Test invalid edge addition
    cout << "\n\nTesting invalid edge addition:" << endl;
    g.addEdge(0, 5); // Invalid destination vertex
    g.BFS(0);*/
    
     // Create graph with 4 vertices
    Graph g(4);
    
    // Add edges: 0->1, 0->2, 1->3, 2->3
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    // Print graph structure
    cout << "Graph Structure:" << endl;
    g.printGraph();
    cout << "\n\n";
    
    // Run DFS from vertex 0
    cout << "DFS Traversal (starting from vertex 0):" << endl;
    g.DFS(0);
    cout << "\n\n";
    
    // Run BFS from vertex 0
    cout << "BFS Traversal (starting from vertex 0):" << endl;
    g.BFS(0);
    cout << "\n";

 
	return 0;
}