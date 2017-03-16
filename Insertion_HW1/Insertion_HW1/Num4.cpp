#include "Num4.h"
using namespace std;

Num4::Num4()//Num4의 결과는 한 파일에 출력함
{
	myFile = new ofstream;
	myFile->open("num4_result.txt", ios_base::trunc);
	myFile->close();
}
Num4::~Num4(){ }

void Num4::deleteFile() { delete myFile; }
//Num5, Nu6과 달리 파일 스트림 객체 1개기때문
//problem class의 deleteFile에 종속 X

void Num4::show(int length, int * a)//정렬하는 원소 모두 출력
{
	for (int i = 0; i < length; i++) {
		*myFile << "[" << *(a + i) << "] ";
	}
	*myFile << endl;
}

void Num4::insertion(int length)
{
	myFile->open("num4_result.txt", ios_base::app);
	*myFile << "best case, worst case, average case" << endl;
	
	for (int k = 0; k < 3; k++) {//k=0 best, k=1 worst, k2 = average
		*myFile <<endl<<endl;
		for (int i = 1; i < length; i++)
		{
			int key = *(*(a + k) + i);
			int j = i - 1;
			*myFile <<i<<"번째 반복"<<"시작. 아래는 직전 정렬 상태"<< endl;
			show(length, *(a + k));
			*myFile <<"현재 key 값: " << key<<endl;
			while (j >= 0 && *(*(a + k) + j) >= key)//오름차순
			{
				*(*(a + k) + (j + 1)) = *(*(a + k) + j);
				show(length, *(a + k));
				j = j - 1;
			}
			*(*(a + k) + (j + 1)) = key;
			show(length, *(a + k));
			*myFile << "반복" << i<< "번째 끝" << endl;
		}
	}
	for (int i = 0; i < 3; i++) {//메모리 해제
		delete[] *(a + i);
	}
	delete[] a;
	delete[] index_arr;
	myFile->close();
}