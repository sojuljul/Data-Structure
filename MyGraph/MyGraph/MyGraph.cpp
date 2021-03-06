// MyGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class MyGraph
{
private:
	int size;
	vector<int> *adjList;

	void DFSHelper(int src, bool visited[]);

public:
	MyGraph(int size);
	void addEdge(int src, int dest);
	void printGraph();

	void BFS(int src);
	void DFS(int src);
};

void MyGraph::DFSHelper(int src, bool visited[])
{
	// mark current as true and print
	visited[src] = true;
	cout << src << " -> ";

	// visit the next and if not visited, call it again
	vector<int>::iterator itr;
	for (itr = adjList[src].begin(); itr != adjList[src].end(); itr++)
	{
		if (!visited[*itr])
		{
			DFSHelper(*itr, visited);
		}
	}
}

void MyGraph::DFS(int src)
{
	// bool array for not visited
	// mark all false
	bool *visited = new bool[size];
	for (int i = 0; i < size; i++)
	{
		visited[i] = false;
	}

	DFSHelper(src, visited);
}


// bool array, mark all not visited
// queue, mark src as true, and add to queue
// while queue is not empty, pop & print
// then iterator through current index
// if not visited, mark as true and add to queue
void MyGraph::BFS(int src)
{
	// all vertices as not visited
	bool *visited = new bool[size];

	for (int i = 0; i < size; i++)
	{
		visited[i] = false;
	}

	// queue for BFS
	queue<int> queue;

	visited[src] = true;
	queue.push(src);

	vector<int>::iterator itr;

	while (!queue.empty())
	{
		// pop from the queue and print
		src = queue.front();
		cout << src << " -> ";
		queue.pop();

		// iterator is the value in the linked list of current index
		for (itr = adjList[src].begin(); itr != adjList[src].end(); itr++)
		{
			if (!visited[*itr])
			{
				visited[*itr] = true;
				queue.push(*itr);
			}
		}
	}
}

MyGraph::MyGraph(int size)
{
	this->size = size;
	adjList = new vector<int>[size];
}

void MyGraph::addEdge(int src, int dest)
{
	adjList[src].push_back(dest);

	// undirected, add the next line
	//adjList[dest].push_back(src);
}

void MyGraph::printGraph()
{
	for (int i = 0; i < size; i++)
	{
		cout << "index " << i << ": ";

		for (auto value : adjList[i])
		{
			cout << value << " -> ";
		}

		cout << endl;
	}
}

int main()
{
	MyGraph loona(4);
	loona.addEdge(0, 1);
	loona.addEdge(0, 2);
	loona.addEdge(1, 2);
	loona.addEdge(2, 0);
	loona.addEdge(2, 3);
	loona.addEdge(3, 3);

	loona.printGraph();

	cout << "\nBFS at 2" << endl;
	loona.BFS(2);

	cout << "\nDFS at 2" << endl;
	loona.DFS(2);
}

