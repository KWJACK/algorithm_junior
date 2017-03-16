#pragma once
class Num1
{
protected:
	int lengthA, lengthB;//length of each A, B array
	char *arrA, *arrB;
	char **mn;//table
public:	
	Num1();	
	~Num1();
	Num1(int m, int n);
	int LCS(int m, int n);
	void printTable(char **arr, int opt);
	char** getMatrix() { return mn; }
};

