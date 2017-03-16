#include "Num2.h"
Num2::Num2(int m, int n):Num1(m,n)
{ }//creat same as Num1 constructor

Num2::~Num2()
{ }

int Num2::bottom_upLCS()
{
	for (int i = 1; i <= lengthA; i++) {//start bottom
		for (int j = 1; j <= lengthB; j++) {
			if (arrA[i - 1] == arrB[j - 1])//if each array has same value
				mn[i][j] = mn[i - 1][j - 1] + 1;
			else {//other				
				if (mn[i][j - 1] >= mn[i - 1][j])
					mn[i][j] = mn[i][j - 1];
				else
					mn[i][j] = mn[i - 1][j];
			}
		}
	}
	printTable(mn,1);//print table
	return mn[lengthA][lengthB];//return LCS's length
}
