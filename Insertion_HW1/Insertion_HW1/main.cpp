#include "Num4.h"
#include "Num5.h"
#include "Num6.h"
#include "Problem.h"
#include <iostream>
//#include <crtdbg.h> 

/*#ifndef _DEBUG //메모리 누수 체크
#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
#endif*/

#define iteration 100
int main() {
	cout << "연산중" << endl;
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Problem *a[3];
	a[0] = new Num4;
	a[1] = new Num5;
	a[2] = new Num6;//Problem에 맞는 문제 생성
	a[0]->makearr(10);//데이터 생성
	a[0]->insertion(10);//소팅 후 결과 출력
	for (int i = 2; i <= iteration; i++) {//2<= n <= 100까지 반복
		a[1]->makearr(i);
		a[1]->insertion(i);

		a[2]->makearr(i*100);//num6는 시간출력을 확인하기위해 간격을 100띄움
		a[2]->insertion(i*100);		
	}
	for (int i = 0; i < 3; i++) {
		a[i]->deleteFile();
		delete a[i];
	}
	cout << "연산 종료..결과는 프로젝트 안의 txt파일들을 참고하세요" << endl;
	return 0;
}