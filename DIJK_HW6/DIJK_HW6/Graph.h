#pragma once
#include <vector>
#include "mHeap.h"
using namespace std;
typedef pair<int, int> Pair;//edge, vertex
class Graph
{
private:
	int V;				//number of vertex
	mHeap pq;			//priority queue(min heap)
	vector<Pair> *adj;	//adjacent vertex and edge	
public:
	Graph();			//not used
	Graph(int V);
	~Graph();
	void addEdge(int u, int v, int w);	
	void dijkstra();	
};

