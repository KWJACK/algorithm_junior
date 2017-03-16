/*Problem 클래스는 super class 입니다.
*Num3, Num4 클래스는 Problem의 상속을 받습니다 */
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Problem
{
protected:
	int** a;			//정렬할 thema별 데이터(merge)	
	int* buff;			//merge를 위한 buffer
	char* index_arr;	//랜덤변수 생성시 사용
	ofstream *myFile;	//파일 출력 객체
public:
	Problem();
	~Problem();
	virtual void mergeSort(int start, int end, int length){};//내용이 빈 가상함수
	void makearr(int total_num);//데이터를 생성 부분
	virtual void deleteFile();//파일
	virtual	void insertSort(int length, int **b) {};
	int** getAbuff() { return a; }
};