/*Problem Ŭ������ super class �Դϴ�.
*Num3, Num4 Ŭ������ Problem�� ����� �޽��ϴ� */
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Problem
{
protected:
	int** a;			//������ thema�� ������(merge)	
	int* buff;			//merge�� ���� buffer
	char* index_arr;	//�������� ������ ���
	ofstream *myFile;	//���� ��� ��ü
public:
	Problem();
	~Problem();
	virtual void mergeSort(int start, int end, int length){};//������ �� �����Լ�
	void makearr(int total_num);//�����͸� ���� �κ�
	virtual void deleteFile();//����
	virtual	void insertSort(int length, int **b) {};
	int** getAbuff() { return a; }
};