#include "Num5.h"
using namespace std;
Num5::Num5() {
	myFile = new ofstream[3];
	myFile->open("inner_test_best.txt", ios_base::trunc);
	(myFile + 1)->open("inner_test_worst.txt", ios_base::trunc);
	(myFile + 2)->open("inner_test_average.txt", ios_base::trunc);
	myFile->close();
	(myFile + 1)->close();
	(myFile + 2)->close();
}
Num5::~Num5(){ }
void Num5::insertion(int length) {
	myFile->open("inner_test_best.txt", ios_base::app);
	(myFile + 1)->open("inner_test_worst.txt", ios_base::app);
	(myFile + 2)->open("inner_test_average.txt", ios_base::app);
	int inner_test;
	for (int k = 0; k < 3; k++) {//k=0 best, k=1 worst, k2 = average
		inner_test = 0;
		for (int i = 1; i < length; i++)
		{
			int key = *(*(a + k) + i);
			int j = i - 1;
			while (inner_test++, j >= 0 && *(*(a + k) + j) > key)
			{
				*(*(a + k) + j + 1) = *(*(a + k) + j);
				j = j - 1;
			}
			*(*(a + k) + j + 1) = key;
		}
		*(myFile + k) << inner_test << endl;
		delete[] *(a + k);//3종류의 1차원 배열 해제
	}
	for (int i = 0; i < 3; i++) {
		(myFile + i)->close();//파일 닫음
	}
	delete[] a;//해제
	delete[] index_arr;	
}
