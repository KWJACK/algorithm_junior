#include "mHeap.h"
#include <iostream>
#include <algorithm>//swap
using namespace std;
mHeap::mHeap(){}

mHeap::~mHeap(){}
void mHeap::push(int e, int v)
{
	Arr.push_back(make_pair( e, v ));//insert back
	Build_Min_Heap();
}
int mHeap::top()
{
	return Arr[0].second;//first: edge, second: vertex
}
void mHeap::pop()
{
	std::swap(Arr[Arr.size()-1], Arr[0]);//swap pair
	Arr.pop_back();//pop last element
	Min_Heapify(0);
}
void mHeap::Build_Min_Heap() {
	for (int i = (Arr.size() / 2)-1; i >=0; i--) {
		Min_Heapify(i);
	}
}
void mHeap::Min_Heapify(int index) {
	int l = (index + 1) * 2 - 1;//left
	int r = (index + 1) * 2;	//right
	int smallest = index;
	if ((Arr.size() > l) && (Arr[l] < Arr[smallest])) {//check it is over than leave or not

		smallest = l;
	}
	if ((Arr.size() > r) && (Arr[r] < Arr[smallest])) {//right case			
		
		smallest = r;			
	}
	if (smallest != index) {//swap with smallest
		std::swap(Arr[index], Arr[smallest]);
		Min_Heapify(smallest);
	}		
}
/*
void mHeap::heapSort()
{	
	cout << endl<<"Before Heap sort" << endl;
	Arr.push_back(make_pair(3, 0));
	Arr.push_back(make_pair(2, 0));
	Arr.push_back(make_pair(1, 0));
	Arr.push_back(make_pair(9, 0));
	Arr.push_back(make_pair(8, 0));
	Arr.push_back(make_pair(4, 0));
	Arr.push_back(make_pair(7, 0));
	Arr.push_back(make_pair(10, 0));
	Arr.push_back(make_pair(14, 0));
	for (auto &i : Arr) {
		cout << i.first <<" ";
	}
	cout << endl << "After Heap sort" << endl;
	Build_Min_Heap();
	while (!Arr.empty()) {
		cout << Arr[0].first<< " ";
		pop();
	}
	cout << endl;
}
*/
int mHeap::indexOf(int v) {//get index
	for (int i = 0; i < Arr.size(); i++) {
		if (Arr[i].second==v)return i;
	}
	
}
void mHeap::decreaseKey(int key, int v) {
	int i = indexOf(v); // index of v(vertex)	
	Arr[i].first = key; // update key	
	while (i && (Arr[i]< Arr[(i - 1) / 2])) {
		//swap with parent		
		std::swap(Arr[i], Arr[(i - 1) / 2]);
		//shift to parent
		i = (i - 1) / 2;
	}	
}
