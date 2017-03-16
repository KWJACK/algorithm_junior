#include "Problem.h"
#include <string.h>//memset
#include <time.h> //srand
#include <stdlib.h>

Problem::Problem() { }
Problem::~Problem() { }

void Problem::makearr(int total_num)
{
	a = new int*[3];
	*(a + 0) = new int[total_num];
	*(a + 1) = new int[total_num];
	*(a + 2) = new int[total_num];
	index_arr = new char[total_num];
	buff = new int[total_num]();//0으로 초기화
	memset(index_arr, 0, total_num);//0은 데이터 없음을 의미(flag off)
	memset(buff, 0, total_num*4);

	//데이터 생성하기
	srand((unsigned)time(NULL));
	for (int i = 0; i < total_num;) {
		int temp = rand() % total_num;
		if (index_arr[temp] == 0) {//flag off라면, 데이터 넣음
			index_arr[temp] = 1;//데이터가 들어왔음을 표시(flag on)			
			*(*(a + 0) + i) = i+1; // best case
			*(*(a + 1) + i) = total_num - i;//worst case
			*(*(a + 2) + i) = temp + 1;//average case
			++i;//남은 갯수 total_num - i
		}
	}
}
void Problem::deleteFile() {
	delete[] myFile;//파일 스트림 객체 3개 메모리 해제
}