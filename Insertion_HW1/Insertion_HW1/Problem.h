/*Problem 클래스는 Absoulte code 입니다.
*Num4, Num5, Num6 클래스는 Problem에 종속됩니다 */
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Problem
{
protected:
	int** a;			//정렬할 thema별 데이터
	char* index_arr;	//랜덤변수 생성시 사용
	ofstream *myFile;	//파일 출력 객체
public:
	Problem();
	~Problem();
	virtual void insertion(int length) {};//내용이 빈 가상함수
	void makearr(int total_num);//데이터를 생성 부분
	virtual void deleteFile();//파일
};