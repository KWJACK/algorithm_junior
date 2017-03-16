#include "Graph.h"
int main()
{
	int V = 8;
	Graph g(V);	

	g.addEdge(0, 1, 6);
	g.addEdge(0, 2, 12);
	g.addEdge(1, 2, 5);
	g.addEdge(2, 3, 9);
	g.addEdge(2, 5, 7);
	g.addEdge(5, 6, 15);
	g.addEdge(5, 7, 10);
	g.addEdge(1, 7, 8);
	g.addEdge(1, 4, 14);
	g.addEdge(4, 7, 3);
	
	g.prim();
	//g.getHeap().heapSort();
	return 0;
}