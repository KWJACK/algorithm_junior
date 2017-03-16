#pragma once
#include "Num2.h"
class Num3 : public Num2
{
	char **trace;
public:
	Num3(int m, int n);
	~Num3();
	char* getArrayA() { return arrA; }
	char* getArrayB() { return arrB; }
	int appendLCS();//override	
	void printLCS(char* arr, int length_A, int length_B);
};

