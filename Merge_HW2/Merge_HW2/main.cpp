#include <iostream>
#include "Num4.h"
#include "Num3.h"
#include <string.h>
#include <crtdbg.h> 


#ifndef _DEBUG //메모리 누수 체크
#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
#endif

#define total_num 300
#define scale 70
using namespace std;
int main() {
	cout << "연산중" << endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//메모리 누수 확인
	Problem *a[2];
	a[0] = new Num3;
	a[1] = new Num4;	
	a[0]->makearr(10);//num3 
	a[0]->mergeSort(0, 9, 10);
	int** b =new int* [3];
	for (int i = 2; i <= total_num; i++) {//num4
		a[1]->makearr(i*scale);//best, worst, random input생성
		b[0] = new int[i*scale];//b는 case별로 생성된 a의 배열을 복사하는 배열
		b[1] = new int[i*scale];
		b[2] = new int[i*scale];
		memcpy_s(*(b + 0), sizeof(int)*i*scale, *((a[1]->getAbuff()) + 0),sizeof(int)*i*scale);//best
		memcpy_s(*(b + 1), sizeof(int)*i*scale, *((a[1]->getAbuff()) + 1), sizeof(int)*i*scale);//worst
		memcpy_s(*(b + 2), sizeof(int)*i*scale, *((a[1]->getAbuff()) + 2), sizeof(int)*i*scale);//avaerge
		a[1]->mergeSort(0, (i * scale) - 1,i * scale);//mergesort진행
		a[1]->insertSort(i * scale, b);//insertsort 진행
		delete[] * (b + 0);//해제
		delete[] * (b + 1);
		delete[] * (b + 2);
	}
	for (int i = 0; i < 2; i++) {
		a[i]->deleteFile();
		delete a[i];		
	}
	delete b;
	cout << "연산 종료..결과는 프로젝트 안의 txt파일들을 참고하세요" << endl;
	return 0;
}