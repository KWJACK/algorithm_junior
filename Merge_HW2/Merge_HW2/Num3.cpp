#include "Num3.h"
using namespace std;

Num3::Num3()
{
	myFile = new ofstream;
	myFile->open("num3_result.txt", ios_base::trunc);
	myFile->close();
}

void Num3::deleteFile()
{
	delete myFile;
	for (int i = 0; i < 3; i++) {
		delete[] * (a + i);//3종류의 1차원 배열 해제
	}
	delete[] a;//해제
	delete[] index_arr;
	delete[] buff;
}

Num3::~Num3(){}

void Num3::mergeSort(int start, int end, int length)
{
	myFile->open("num3_result.txt", ios_base::app);
	*myFile << "best case, worst case, average case" << endl;
	memset(buff, 0, 10); //buff 초기화
	merge(*(a+0), start, end, length);//best
	*myFile << endl;

	merge(*(a+1), start, end, length);//wosrt
	*myFile << endl;

	merge(*(a+2), start, end, length);//average
	myFile->close();

}
void Num3::merge(int *a, int start, int end, int length)
{
	show(start, length, a);
	if (length < 2) return; 	
	int mid = length / 2;
	merge(a, start, mid, mid);
	merge(a, start+mid, end, length - mid);	
	int i = start, k = start;
	int j = mid+start;
	//Merge
	while (i < mid+start && j < length+start)
		buff[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

	while (i < mid+start)buff[k++] = a[i++];

	while (j < length+start)buff[k++] = a[j++];

	for (i = start; i < length+start; i++)
		a[i] =buff[i];
	show(start,length, buff);
	memset(buff, 0, 10);

}
void Num3::show(int start, int length, int * buff)//정렬하는 원소 모두 출력
{
	for (int i = 0; i < start+length; i++) {
		if (i<start)*myFile << "[ ] ";
		else *myFile << "[" << *(buff + i) << "] ";
	}
	*myFile << endl;
}