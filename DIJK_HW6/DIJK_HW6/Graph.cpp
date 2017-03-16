#include "Graph.h"
#include <iostream>

#define HUGENUM 9999
using namespace std;
Graph::Graph() {}
Graph::Graph(int Vec) :V(Vec)
{
	adj = new vector<Pair>[V];//allocation
}

Graph::~Graph() {}
void Graph::addEdge(int u, int v, int w)//src, deti, weight
{
	//direction linking
	adj[u].push_back(make_pair(v, w));
}
void Graph::dijkstra()
{
	cout << "Most small cost path by dijkstra" << endl;
	int s = 0;//source
	vector<int> d(V, HUGENUM);//d = dist <- shorest path
	vector<bool> U(V, false);//check for extracted
	d[s] = 0;//initial point always zero
	pq.push(0, s);//start_point  push(weight, v)

	vector<Pair> phi;//<weight, (small dist, vertex)>
	phi.push_back( make_pair(0, s));//add one more	
	for (int i = 1; i < V; i++) {//initialize
		pq.push(HUGENUM,i);				//priority queue
		phi.push_back(make_pair(0, -1));//0->weight, -1->invalid vertex
	}
	cout << "S: ";
	while (!pq.empty())//till heap is empty
	{
		int u = pq.top();//get root vertex
		cout << u << " ";
		pq.pop();
		U[u] = true;//extracted 
		vector<Pair>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{
			int v = (*i).first;//vertex
			int weight = (*i).second;
			if (d[v] > d[u]+weight)//if new 'u' vertex's path shorter than 'v'
			{
				d[v] = d[u] + weight;//relaxation
				pq.decreaseKey(d[u]+weight, v);//key down(heap)
				phi[v].first = weight; phi[v].second = u;
			}
		}
	}
	cout << endl;	
	for (int i = 0; i < V; i++) {//print each vertex's shortest path
		if (i == s)printf("From start the %d vertex,\n", s);
		else printf("alpha[%d] : %d\n", i, phi[i].first);
	}
	cout << endl<<"Connected like that," << endl;
	for (int i = 0; i < V; i++) {//print vertex-verte(edge) info
		printf("d[%d] : %d\tpredecessor(%d) - edge(%d)\n", i, d[i], phi[i].second, i);
	}
	cout << endl;
}