#include "Bellman.h"
#include <vector>
#include <iostream>
#define HUGENUM 9999
Bellman::Bellman(int v, int e):V(v), E(e){}
Bellman::~Bellman(){}
void Bellman::addEdge(int u, int v, int w)//src, deti, weight
{
	//direction linking
	adj.push_back( make_pair(u, make_pair(v, w)));//u, v vertex, w- edge's weight
}
void Bellman::bellman() {
	cout << "Bellman-Ford algorithm" << endl;
	int s = 0;//source
	vector<int> d(V, HUGENUM);//d = dist <- shorest path	
	vector<int> phi(V, 0);//predecessor
	d[s] = 0;	
	for (int i = 0; i < V-1; i++) {		
		list<dPair>::iterator C;//Crrent
		for (C = adj.begin(); C!=adj.end(); C++) {//travel all edge
			int u = (*C).first;
			int v = (*C).second.first;
			int weight = (*C).second.second;
			if (d[v] > d[u] + weight) {//relaxation
				d[v] = d[u] + weight;
				phi[v] = u;//update predecessor
			}
		}
	}
	for (int i = 0; i < V; i++)
		printf("d[%d] : %d\tpredecessor(%d) - edge(%d)\n", i, d[i], phi[i], i);
	
	for (int i = 0; i < V - 1; i++) {
		list<dPair>::iterator C;//Crrent
		for (C = adj.begin(); C != adj.end(); C++) {//edge all				
			int u = (*C).first;
			int v = (*C).second.first;
			int weight = (*C).second.second;
			if (d[v] > d[u] + weight) {
				cout << "graph has negetive-weight edge";
				return;
			}
		}
	}
}