/*Problem Ŭ������ Absoulte code �Դϴ�.
*Num4, Num5, Num6 Ŭ������ Problem�� ���ӵ˴ϴ� */
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Problem
{
protected:
	int** a;			//������ thema�� ������
	char* index_arr;	//�������� ������ ���
	ofstream *myFile;	//���� ��� ��ü
public:
	Problem();
	~Problem();
	virtual void insertion(int length) {};//������ �� �����Լ�
	void makearr(int total_num);//�����͸� ���� �κ�
	virtual void deleteFile();//����
};