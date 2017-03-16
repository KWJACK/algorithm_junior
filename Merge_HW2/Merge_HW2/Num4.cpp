#include "Num4.h"
#include <ctime>
#include <chrono>
using namespace std;
Num4::Num4()
{
	myFile = new ofstream[6];
	(myFile + 0)->open("time_best[M].txt", ios_base::trunc);
	(myFile + 1)->open("time_worst[M].txt", ios_base::trunc);
	(myFile + 2)->open("time_average[M].txt", ios_base::trunc);
	(myFile + 3)->open("time_best[I].txt", ios_base::trunc);
	(myFile + 4)->open("time_worst[I].txt", ios_base::trunc);
	(myFile + 5)->open("time_average[I].txt", ios_base::trunc);

	(myFile + 0)->close();
	(myFile + 1)->close();
	(myFile + 2)->close();
	(myFile + 3)->close();
	(myFile + 4)->close();
	(myFile + 5)->close();
}

Num4::~Num4(){ }
void Num4::mergeSort(int start, int end, int length)
{
	(myFile + 0)->open("time_best[M].txt", ios_base::app);//appendix 모드
	(myFile + 1)->open("time_worst[M].txt", ios_base::app);
	(myFile + 2)->open("time_average[M].txt", ios_base::app);
	for(int k=0;k<3;k++){	
		std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
		merge(*(a + k), start, end, length);//best, worst, average
		std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
		std::chrono::microseconds micro;//크로노를 통해 시간 구함(나노 단위 10^-9)
		micro = std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime);
		*(myFile + k) << micro.count() << endl;
		(myFile + k)->close();
	}
	for (int i = 0; i < 3; i++) {
		(myFile + i)->close();
		delete[] * (a + i);
	}
	delete[] a;
	delete[] index_arr;
	delete[] buff;
}
void Num4::merge(int *a, int start, int end, int length)
{
	if (length < 2) return;
	int mid = length / 2;

	merge(a, start, mid, mid);
	merge(a, start + mid, end, length - mid);

	int i = start, k = start;
	int j = mid + start;

	//Merge
	while (i < mid + start && j < length + start)
		buff[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
	while (i < mid + start) 
		buff[k++] = a[i++];
	while (j < length + start)
		buff[k++] = a[j++];
	for (i = start; i < length + start; i++)
		a[i] = buff[i];
}
void Num4::insertSort(int length, int **b) {
	(myFile + 3)->open("time_best[I].txt", ios_base::app);//appendix 모드
	(myFile + 4)->open("time_worst[I].txt", ios_base::app);
	(myFile + 5)->open("time_average[I].txt", ios_base::app);
	for (int k = 0; k < 3; k++) {//k=0 best, k=1 worst, k2 = average
		std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
		for (int i = 1; i < length; i++)
		{
			int key = *(*(b + k) + i);
			int j = i - 1;
			while (j >= 0 && *(*(b + k) + j) >= key)
			{
				*(*(b + k) + j + 1) = *(*(b + k) + j);
				j = j - 1;
			}
			*(*(b + k) + j + 1) = key;
		}
		std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
		std::chrono::microseconds micro;//크로노를 통해 시간 구함(마이크로 단위 10^-6)
		micro = std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime);
		*(myFile + (k+3)) << micro.count() << endl;
	}
	for (int i = 0; i < 3; i++) {
		(myFile + (i+3))->close();//파일 닫음
	}
}