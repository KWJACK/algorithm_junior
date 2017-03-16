#include "Graph.h"
#include <iostream>

#define HUGENUM 9999
using namespace std;
Graph::Graph(){}

Graph::Graph(int Vec):V(Vec)
{
	adj = new vector<Pair>[V];//allocation
}

Graph::~Graph(){}

void Graph::addEdge(int u, int v, int w)
{
	//linking
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::prim()
{	
	vector<pair<int, int> > a;
	
	cout << "Most small cost path by prim" << endl;
	for (int i = 1; i < V; i++) {//version 2
		Q.push(HUGENUM, i);
	}
	int s = 0;//source
	vector<int> key(V, HUGENUM);
	vector<bool> U(V, false);
	vector<int> phi(V, -1);//-1 means not determined yet	
	Q.push(0,0);//arbitrary  push(weight, v)	
	key[s] = 0;//initial point always zero	
	while (!Q.empty())//till heap is empty
	{			
		int u = Q.top();//get root vertex		
		Q.pop();
		U[u] = true;
		vector<Pair>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{		
            int v = (*i).first;
			int weight = (*i).second;
			if (!U[v] && key[v] > weight)
			{
				key[v] = weight;				
				phi[v] = u;				
				Q.decreaseKey(weight, v);
			}			
		}		
	}	
	for (int i = 0; i < V; i++) {//print path info
		if (phi[i] == -1)printf("X - %d\n", i);//X mean start point
		else printf("%d - %d\n", phi[i], i);
	}	
}
