#include "Num1.h"
#include <iostream>

#define max(a,b) ((a>=b)? a : b)
using namespace std;
Num1::Num1() {}
Num1::Num1(int m, int n) :lengthA(m), lengthB(n)
{		
	arrA = new char[lengthA];//test{'B', 'D', 'C', 'A', 'B', 'A'};
	arrB = new char[lengthB];//test{'A', 'B', 'C', 'B', 'D', 'A', 'B'};
	mn = new char*[lengthA + 1];
	*(mn + 0)= new char[lengthB + 1]();//initialize 0
	cout << "arrA ={ ";	
	for (int i = 0; i < lengthA; i++) {//fill arrA value		
		arrA[i] = (char)(rand() % 4 + 65);//A,B,C,D
		*(mn + 1 + i) = new char[lengthB + 1]();
		cout << arrA[i] << " ";
	}
	cout << "}" << endl<<"arrB ={ ";
	for (int j = 0; j < lengthB; j++) {//fill arrA value		
		arrB[j] = (char)(rand() % 4 + 65);//A,B,C,D
		cout << arrB[j] << " ";
	}
	cout << "}" << endl;
}
Num1::~Num1()
{
	delete arrA;
	delete arrB;
	for (int i = 0; i <= lengthA; i++)
		delete[] * (mn + i);	
	delete mn;
}
//except boath arrA, arrB parameter cause already known in class
int Num1::LCS(int m,int n)
{
	if (mn[m][n] == 0) {//NIL is -1 in here
		if (m == 0 || n == 0)mn[m][n] = 0;
		else if (arrA[m-1] == arrB[n-1])mn[m][n] = (1 + LCS(m - 1, n - 1));
		else mn[m][n] = max(LCS(m - 1, n), LCS(m, n - 1));
	}return mn[m][n];
}
void Num1::printTable(char **mat, int opt) {
	if(opt==1)cout << endl<< "LCS table" << endl;
	else cout << "trace Table" << endl;
	printf("      ");
	for (int m = 0; m <= lengthA; m++) {			
		if (m == 0) {//row-arrB
			for(int n=0;n<lengthB;n++)
			printf("%c  ", arrB[n]);
			cout << endl;
			printf("   ");
		}		
		for (int n = 0; n <= lengthB; n++) {						
			if (m>0 && 0 == n)printf("%c  ", arrA[m-1]);//col-arrA
			printf("%d  ", (int)mat[m][n]);//table entry
		}
		cout << endl;
	}
}