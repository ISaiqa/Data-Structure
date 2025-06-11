#include <iostream>
#include "GraphLL.h"
#include"C:\Users\abc\OneDrive\Desktop\FPQ\PriorityQueue.h"
#include "C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\QueueUsingArray\Queue.h"
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\StackUsingArray\Stack.h"


using namespace std;

class Graph
{
	private:
		int vertices;//total vetices in a graph
		GraphLL *adjList;
	
	public:
		Graph(int vertices)
		{
			this->vertices=vertices;
			adjList=new GraphLL[vertices];// arr=new T[size]
		}
		 ~Graph(); // Destructor declaration
		void addRoute(int src, int dst,float distance);
		void printGraph();
		void BFS(int startV);
		void DFS(int startV);
		void removeRoute(int src,int dst);
		void addCity();
		void removeCity(int city);
		int getVertices();
		void dijkstra(int startV);
};

void Graph::addRoute(int src, int dst,float distance)//0->1
{
	if(0 <= src && src < vertices && 0 <= dst && dst < vertices)
	{
		adjList[src].insert(dst,distance);
	}
	else
	{
		cerr<<"Invalid City !";
		return;
	}
	  
}
void Graph::removeRoute(int src,int dst)
{
	if(0 <= src && src < vertices && 0 <= dst && dst < vertices)
	{
		adjList[src].remove(dst);
	}
	else
	{
		cerr<<"Invalid City !";
		return;
	}

}

void Graph::printGraph()
{
	for(int i=0;i<vertices;i++)
	{
		cout<<" "<<i<<"->";
		adjList[i].displayAllNeighbors();
		cout<<endl;
	}
}


void Graph::addCity()
{
	if(vertices<20)
	{
		int v=vertices+1;
		GraphLL *list=new GraphLL[v];
		for(int i=0; i<vertices;i++)
		{
			GNode *j=adjList[i].getHead();
			while(j!=0)
			{
				list[i].insert(j->getInfo(),j->getDistance());
				j=j->getNext();
			}
		}
		delete []adjList;
		adjList=list;
		vertices=v;
	}
	else
	{
		cerr<<"Limit reached!(20 cities already added)";
		return;
	}
		
}
void Graph::removeCity(int city) 
{
    if (city >= 0 && city < vertices) 
	{
        for (int i = 0; i < vertices; i++) 
		{
            if (i != city) 
			{
                adjList[i].remove(city);
            }
        }
        adjList[city].clear();
    } else {
        cerr << "Invalid City!\n";
        return;
    }
}
Graph::~Graph() 
{
    delete [] adjList;
    adjList = nullptr;
}
int Graph::getVertices()
{
	return this->vertices;
}

void Graph::dijkstra(int startV) 
{
    if (startV < 0 || startV >= vertices) 
	{
        cout << "\tError: Invalid source city!\n";
        return;
    }
    
    // Initialize dynamic arrays
    float *dist = new float[vertices];
    int *pred = new int[vertices];
    bool *visited = new bool[vertices];
    bool *inQueue = new bool[vertices];
    for (int i = 0; i < vertices; i++) 
	{
        dist[i] = 999999.0; // Large number for infinity
        pred[i] = -1;
        visited[i] = false;
        inQueue[i] = false;
    }
    dist[startV] = 0.0;

    // Initialize priority queue
    PriorityQueue<int> pq;
    pq.addSorted(startV, 0.0);
    inQueue[startV] = true;

    // Process vertices
    while (!pq.isEmpty()) 
	{
        int current = pq.dequeue();
        inQueue[current] = false;
        if (visited[current]) continue;
        visited[current] = true;

        // Explore neighbors
        GNode *temp = adjList[current].getHead();
        while (temp != 0) 
		{
            int neighbor = temp->getInfo();
            float weight = temp->getDistance();
            if (!visited[neighbor]) 
			{
                float newDist = dist[current] + weight;
                if (newDist < dist[neighbor]) 
				{
                    dist[neighbor] = newDist;
                    pred[neighbor] = current;
                    if (!inQueue[neighbor]) 
					{
                        pq.addSorted(neighbor, newDist);
                        inQueue[neighbor] = true;
                    }
                }
            }
            temp = temp->getNext();
        }
    }
    
    // Print paths and distances
    cout << "\t~~~~ Shortest Paths from City " << startV << " ~~~~\n";
    for (int i = 0; i < vertices; i++) 
	{
        if (i == startV) continue;
        Stack<int> path(vertices);
        cout << "To City " << i << ": ";
        if (dist[i] >= 999999.0) 
		{
            cout << "Unreachable\n";
        } else 
		{
            // Reconstruct path
            int current = i;
            while (current != -1) 
			{
                path.push(current);
                current = pred[current];
            }
            // Print path
            while (!path.isEmpty()) 
			{
                cout << path.pop();
                if (!path.isEmpty()) cout << " -> ";
            }
            cout << ", Distance: " << dist[i] << " km\n";
        }
    }
    
    // Clean up
    delete [] dist;
    delete [] pred;
    delete [] visited;
    delete [] inQueue;
}

