#pragma once
#include "Problem.h"
class Num4 : public Problem
{
public:
	Num4();
	~Num4();
	void mergeSort(int start, int end, int length);	
	void merge(int * a, int start, int end, int length);
	void insertSort(int length, int **b);
};

