#include "Problem.h"
#include <string.h>//memset
#include <time.h> //srand
#include <stdlib.h>

Problem::Problem(){ }
Problem::~Problem(){ }

void Problem::makearr(int total_num)
{
	a = new int*[3];
	*a = new int[total_num];
	*(a + 1) = new int[total_num];
	*(a + 2) = new int[total_num];
	index_arr = new char[total_num];
	memset(index_arr, 0, total_num);//0은 데이터 없음을 의미(flag off)
	for (int i = 0; i < total_num; i++) {
		*(*(a)+i) = i; // best case의 데이터
		*(*(a + 1) + i) = total_num - (i + 1);//worst case의 데이터
	}
	//중복되지않는 데이터 만들기
	srand((unsigned)time(NULL));
	for (int i = 0; i < total_num;) {
		int temp = rand() % total_num;
		if (index_arr[temp] == 0) {//flag off라면, 데이터 넣음
			index_arr[temp] = 1;//데이터가 들어왔음을 표시(flag on)
			*(*(a + 2) + i) = temp;
			++i;//남은 갯수 total_num - i
		}
	}
}
void Problem::deleteFile() {
	delete[] myFile;//파일 스트림 객체 3개 메모리 해제
}