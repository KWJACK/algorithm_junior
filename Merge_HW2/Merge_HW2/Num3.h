#pragma once
#include "Problem.h"
class Num3 : public Problem
{
public:
	Num3();
	void deleteFile();
	~Num3();
	void mergeSort(int start, int end, int length);
	void merge(int *a,int start, int end, int length);
	void show(int start,int length, int * a);
};

