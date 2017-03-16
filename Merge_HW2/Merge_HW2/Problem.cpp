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
	buff = new int[total_num]();//0���� �ʱ�ȭ
	memset(index_arr, 0, total_num);//0�� ������ ������ �ǹ�(flag off)
	memset(buff, 0, total_num*4);

	//������ �����ϱ�
	srand((unsigned)time(NULL));
	for (int i = 0; i < total_num;) {
		int temp = rand() % total_num;
		if (index_arr[temp] == 0) {//flag off���, ������ ����
			index_arr[temp] = 1;//�����Ͱ� �������� ǥ��(flag on)			
			*(*(a + 0) + i) = i+1; // best case
			*(*(a + 1) + i) = total_num - i;//worst case
			*(*(a + 2) + i) = temp + 1;//average case
			++i;//���� ���� total_num - i
		}
	}
}
void Problem::deleteFile() {
	delete[] myFile;//���� ��Ʈ�� ��ü 3�� �޸� ����
}