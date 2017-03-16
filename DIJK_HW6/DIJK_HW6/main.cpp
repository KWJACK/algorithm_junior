#include "Graph.h"
#include "Bellman.h"
int main() {
	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);	
	g.dijkstra();
	/////////end num1/////////

	Bellman g2(5, 8);
	g2.addEdge(0, 1, -1);
	g2.addEdge(0, 3, 4);
	g2.addEdge(1, 2, 2);
	g2.addEdge(1, 3, 3);
	g2.addEdge(1, 4, 2);
	g2.addEdge(2, 4, -3);
	g2.addEdge(4, 1, 1);
	g2.addEdge(4, 3, 5);
	g2.bellman();
	return 0;
}