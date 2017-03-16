#pragma once
#include <list>
using namespace std;
typedef pair <int , pair<int, int> > dPair;//double pair
class Bellman
{
private:
	list<dPair> adj;
	int V, E;//number of vertex and edge
public:
	Bellman(int v, int e);
	~Bellman();
	void addEdge(int u, int v, int w);
	void bellman();
};

