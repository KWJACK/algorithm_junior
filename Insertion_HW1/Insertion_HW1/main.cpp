#include "Num4.h"
#include "Num5.h"
#include "Num6.h"
#include "Problem.h"
#include <iostream>
//#include <crtdbg.h> 

/*#ifndef _DEBUG //�޸� ���� üũ
#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
#endif*/

#define iteration 100
int main() {
	cout << "������" << endl;
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Problem *a[3];
	a[0] = new Num4;
	a[1] = new Num5;
	a[2] = new Num6;//Problem�� �´� ���� ����
	a[0]->makearr(10);//������ ����
	a[0]->insertion(10);//���� �� ��� ���
	for (int i = 2; i <= iteration; i++) {//2<= n <= 100���� �ݺ�
		a[1]->makearr(i);
		a[1]->insertion(i);

		a[2]->makearr(i*100);//num6�� �ð������ Ȯ���ϱ����� ������ 100���
		a[2]->insertion(i*100);		
	}
	for (int i = 0; i < 3; i++) {
		a[i]->deleteFile();
		delete a[i];
	}
	cout << "���� ����..����� ������Ʈ ���� txt���ϵ��� �����ϼ���" << endl;
	return 0;
}