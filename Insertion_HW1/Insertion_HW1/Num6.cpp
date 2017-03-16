#include "Num6.h"
#include <ctime>
#include <chrono>
using namespace std;

Num6::Num6(){//각 인풋 종류에 따른 결과파일 생성
	myFile = new ofstream[3];
	myFile->open("time_best.txt", ios_base::trunc);//파일 초기화
	(myFile + 1)->open("time_worst.txt", ios_base::trunc);
	(myFile + 2)->open("time_average.txt", ios_base::trunc);
	myFile->close();
	(myFile + 1)->close();
	(myFile + 2)->close();
}
Num6::~Num6(){ }

void Num6::insertion(int length) {
	myFile->open("time_best.txt", ios_base::app);//appendix 모드
	(myFile + 1)->open("time_worst.txt", ios_base::app);
	(myFile + 2)->open("time_average.txt", ios_base::app);	
	for (int k = 0; k < 3; k++) {//k=0 best, k=1 worst, k2 = average
		std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();		
		for (int i = 1; i < length; i++)
		{
			int key = *(*(a+k) + i);
			int j = i - 1;
			while (j >= 0 && *(*(a+k) + j) >= key)
			{
				*(*(a+k) + j + 1) = *(*(a+k) + j);
				j = j - 1;
			}
			*(*(a+k) + j + 1) = key;
		}
		std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
		std::chrono::microseconds micro;//크로노를 통해 시간 구함(마이크로 단위 10^-6)
		micro=std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime);
		*(myFile+k) << micro.count() << endl;
	}
	for (int i = 0; i < 3; i++) {
		(myFile + i)->close();//파일 닫음
		delete[] * (a + i);//3종류의 1차원 배열 해제
	}
	delete[] a;//해제
	delete[] index_arr;
}
