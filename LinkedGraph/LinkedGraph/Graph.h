#include <iostream>
#include "HeaderLL.h"
#include "C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\QueueUsingArray\Queue.h"
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\StackUsingArray\Stack.h"
using namespace std;

class Graph
{
	private:
		int vertices;//total vetices in a graph
		HeaderLL *adjList;
	
	public:
		Graph(int vertices)
		{
			this->vertices=vertices;
			adjList=new HeaderLL[vertices];// arr=new T[size]
		}
		
		void addEdge(int src, int dst);
		void printGraph();
		void BFS(int startV);
		void DFS(int startV);
};

void Graph::addEdge(int src, int dst)//0->1
{
	  adjList[src].insert(dst);
	  adjList[dst].insert(src);
	  //it is for undirected graph for directed only insert source to dest
}

void Graph::printGraph()
{
	for(int i=0;i<vertices;i++)
	{
		cout<<"Vertex "<<i<<" : ";
		adjList[i].displayALLNeighbors();
		cout<<endl;
	}
}

void Graph::BFS(int startV)
{
	bool visited[vertices]={false};
	Queue<int> q(vertices);
	
	visited[startV]=true;
	q.enqueue(startV);
	
	while(!q.isEmpty())//true till queue is not empty only stops when queue is empty
	{
		int v=q.dequeue();
		cout<<v<<"\t";
		
		Node *temp= adjList[v].getHead();//get head to find all neighbors of v
		while(temp!=0)//move in whole linkedlist
		{
			if(visited[temp->getInfo()]==false)//find unvisted members
			{
				visited[temp->getInfo()]=true;//mark then visited
				q.enqueue(temp->getInfo());//add to queue
			}
			temp=temp->getNext();
		}
	}//isEmpty
	
}

void Graph::DFS(int startV)
{
    bool visited[vertices]={false};
    Stack<int> s(vertices);
    visited[startV]=true;
    s.push(startV);
    while(!s.isEmpty())
    {
        int v=s.pop();
        cout<<v<<"\t";
        Node* temp=adjList[v].getHead();
        while(temp!=0)
        {
            if(visited[temp->getInfo()]==false)
            {
                visited[temp->getInfo()]=true;
                s.push(temp->getInfo());
            }
            temp=temp->getNext();
        }
    }
}


