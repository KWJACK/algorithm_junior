#pragma once
#include <vector>
#include "mHeap.h"
using namespace std;
typedef pair<int, int> Pair;//edge, vertex
class Graph
{
private:
	mHeap Q;			//priority queue
	int V;				//number of vertex
	vector<Pair> *adj;	//adjacent vertex and edge				
public:
	Graph();			//not used
	Graph(int V);
	~Graph();
	void addEdge(int u, int v, int w);
	void prim();
	mHeap getHeap() { return Q; }
};

