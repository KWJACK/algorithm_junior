#pragma once
#include <vector>
using namespace std;
class mHeap
{
private:
	vector<pair<int, int> > Arr;
public:
	mHeap();
	~mHeap();
	void push(int e, int v);
	int top(); //print root
	void pop(); //pop root
	bool empty() { return Arr.empty(); }; //check heap is empty
	void Build_Min_Heap();	//Build Heap(insert)
	void Min_Heapify(int); //Heapify	
	int indexOf(int v);
	void decreaseKey(int v, int key);
};
