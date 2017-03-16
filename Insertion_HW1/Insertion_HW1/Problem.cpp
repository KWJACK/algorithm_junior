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
	memset(index_arr, 0, total_num);//0�� ������ ������ �ǹ�(flag off)
	for (int i = 0; i < total_num; i++) {
		*(*(a)+i) = i; // best case�� ������
		*(*(a + 1) + i) = total_num - (i + 1);//worst case�� ������
	}
	//�ߺ������ʴ� ������ �����
	srand((unsigned)time(NULL));
	for (int i = 0; i < total_num;) {
		int temp = rand() % total_num;
		if (index_arr[temp] == 0) {//flag off���, ������ ����
			index_arr[temp] = 1;//�����Ͱ� �������� ǥ��(flag on)
			*(*(a + 2) + i) = temp;
			++i;//���� ���� total_num - i
		}
	}
}
void Problem::deleteFile() {
	delete[] myFile;//���� ��Ʈ�� ��ü 3�� �޸� ����
}