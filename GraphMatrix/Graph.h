#include<iostream>
using namespace std;
#include "C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\QueueUsingArray\Queue.h"
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\StackUsingArray\Stack.h"
class Graph
{
	private:
		int vertices;
		int **graph;
	public:
		Graph(int vertices=5)
		{
			this->vertices=vertices;
			graph=new int*[vertices];
			for(int i=0;i<vertices;i++)
			{
				graph[i] = new int[vertices]; // Allocate each row
				for (int j=0;j<vertices;j++)
				{
					graph[i][j]=0;
				}
			}
		}
		void addEdge(int src,int dst);
		void removeEdge(int src,int dst);
		void printGraph();
		void BFS(int startV);
		void DFS(int startV);
};
void Graph::addEdge(int src,int dst)
{
	if (src >= 0 && src < vertices && dst >= 0 && dst < vertices)
		graph[src][dst]=1;
	else
        cout << "Invalid vertex" << endl;
	//if we have weighted graph we can assign the weight here instead
}

void Graph::removeEdge(int src,int dst)
{
	if (src >= 0 && src < vertices && dst >= 0 && dst < vertices)
		graph[src][dst]=0;
	else
        cout << "Invalid vertex" << endl;
}

void Graph::printGraph()
{
	for(int i=0;i<vertices;i++)
	{
		cout<<"\n"<<i<<": ";
		for (int j=0;j<vertices;j++)
		{
			
			if (graph[i][j]==1)
			{
				cout<<"<<";
				cout<<j;
			}
		}
	}
}

void Graph::DFS(int startV)
{

	Stack<int> s(vertices);
	bool visited[vertices]={false};
	
	s.push(startV);
	visited[startV]=true;
	
	while(!s.isEmpty())
	{
		int v=s.pop();
		cout<<v<<"\t";
		
		for(int j=0;j<vertices;j++)
		{
			if(graph[v][j]==1 && !visited[j])
			{
				visited[j]=true;
				s.push(j);
			}
		}
		
		
	}
	
	

}


void Graph::BFS(int startV)
{

	Queue<int> q(vertices);
	bool visited[vertices]={false};
	
	q.enqueue(startV);
	visited[startV]=true;
	
	while(!q.isEmpty())
	{
		int v=q.dequeue();
		cout<<v<<"\t";
		
		for(int j=0;j<vertices;j++)
		{
			if(graph[v][j]==1 && !visited[j])
			{
				visited[j]=true;
				q.enqueue(j);
			}
		}
		
		
	}
	
	

}