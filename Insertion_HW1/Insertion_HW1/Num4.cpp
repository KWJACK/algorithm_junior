#include "Num4.h"
using namespace std;

Num4::Num4()//Num4�� ����� �� ���Ͽ� �����
{
	myFile = new ofstream;
	myFile->open("num4_result.txt", ios_base::trunc);
	myFile->close();
}
Num4::~Num4(){ }

void Num4::deleteFile() { delete myFile; }
//Num5, Nu6�� �޸� ���� ��Ʈ�� ��ü 1���⶧��
//problem class�� deleteFile�� ���� X

void Num4::show(int length, int * a)//�����ϴ� ���� ��� ���
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
			*myFile <<i<<"��° �ݺ�"<<"����. �Ʒ��� ���� ���� ����"<< endl;
			show(length, *(a + k));
			*myFile <<"���� key ��: " << key<<endl;
			while (j >= 0 && *(*(a + k) + j) >= key)//��������
			{
				*(*(a + k) + (j + 1)) = *(*(a + k) + j);
				show(length, *(a + k));
				j = j - 1;
			}
			*(*(a + k) + (j + 1)) = key;
			show(length, *(a + k));
			*myFile << "�ݺ�" << i<< "��° ��" << endl;
		}
	}
	for (int i = 0; i < 3; i++) {//�޸� ����
		delete[] *(a + i);
	}
	delete[] a;
	delete[] index_arr;
	myFile->close();
}