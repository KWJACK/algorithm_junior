#include <iostream>
#include "Num4.h"
#include "Num3.h"
#include <string.h>
#include <crtdbg.h> 


#ifndef _DEBUG //�޸� ���� üũ
#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
#endif

#define total_num 300
#define scale 70
using namespace std;
int main() {
	cout << "������" << endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//�޸� ���� Ȯ��
	Problem *a[2];
	a[0] = new Num3;
	a[1] = new Num4;	
	a[0]->makearr(10);//num3 
	a[0]->mergeSort(0, 9, 10);
	int** b =new int* [3];
	for (int i = 2; i <= total_num; i++) {//num4
		a[1]->makearr(i*scale);//best, worst, random input����
		b[0] = new int[i*scale];//b�� case���� ������ a�� �迭�� �����ϴ� �迭
		b[1] = new int[i*scale];
		b[2] = new int[i*scale];
		memcpy_s(*(b + 0), sizeof(int)*i*scale, *((a[1]->getAbuff()) + 0),sizeof(int)*i*scale);//best
		memcpy_s(*(b + 1), sizeof(int)*i*scale, *((a[1]->getAbuff()) + 1), sizeof(int)*i*scale);//worst
		memcpy_s(*(b + 2), sizeof(int)*i*scale, *((a[1]->getAbuff()) + 2), sizeof(int)*i*scale);//avaerge
		a[1]->mergeSort(0, (i * scale) - 1,i * scale);//mergesort����
		a[1]->insertSort(i * scale, b);//insertsort ����
		delete[] * (b + 0);//����
		delete[] * (b + 1);
		delete[] * (b + 2);
	}
	for (int i = 0; i < 2; i++) {
		a[i]->deleteFile();
		delete a[i];		
	}
	delete b;
	cout << "���� ����..����� ������Ʈ ���� txt���ϵ��� �����ϼ���" << endl;
	return 0;
}