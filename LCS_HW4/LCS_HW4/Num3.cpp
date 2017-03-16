#include "Num3.h"
#include <iostream>
using namespace std;
Num3::Num3(int m, int n):Num2(m,n)
{
	trace = new char*[lengthA+1];
	for (int i = 0; i <= lengthA; i++)
		*(trace + i) = new char[lengthB + 1]();//initialization 0
}

Num3::~Num3(){}

int Num3::appendLCS()
{
	for (int i = 1; i <= lengthA; i++) {//start bottom
		for (int j = 1; j <= lengthB; j++) {
			if (arrA[i - 1] == arrB[j - 1]) {//if each array has same value
				mn[i][j] = mn[i - 1][j - 1] + 1;
				trace[i][j] = 1;//¢Ø
			}
			else {//other				
				if (mn[i][j - 1] > mn[i - 1][j]) {
					mn[i][j] = mn[i][j - 1];
					trace[i][j] = 2;//¡ç
				}
				else {
					mn[i][j] = mn[i - 1][j];
					trace[i][j] = 3;//¡è
				}
			}
		}
	}
	printTable(mn,1);//print table
	printTable(trace,2);//print table	
	return mn[lengthA][lengthB];//return LCS's length
}

void Num3::printLCS(char * arr, int length_A, int length_B)
{
	if (length_A == 0 || length_B == 0)return;//till end of element of A and B
	if (trace[length_A][length_B] == 1) {
		printLCS(arr, length_A - 1, length_B - 1);
		cout << arr[length_A-1];//print element by traceback
	}
	else if (trace[length_A][length_B] == 2)printLCS(arr, length_A, length_B - 1);		
	else printLCS(arr, length_A - 1, length_B);
}