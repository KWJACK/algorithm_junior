#include <iostream>
#include "Num1.h"
#include "Num2.h"
#include "Num3.h"
#include <crtdbg.h> 
#include <stdlib.h>
#include <time.h>

#ifndef _DEBUG //메모리 누수 체크
#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
#endif

using namespace std;
int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(NULL));//for random value
	cout << "[Num1] START: " <<endl;
	Num1 num1(6,7);
	int result1= num1.LCS(6, 7);
	num1.printTable(num1.getMatrix(),1);
	cout << "[Num1] The length of LCS: " << result1 <<endl<<endl;

	cout << "[Num2] START: " << endl;
	Num2 num2(6, 7);
	int result2 = num2.bottom_upLCS();
	cout << "[Num2] The length of LCS: " << result2 << endl << endl;

	cout << "[Num3] START: " << endl;
	Num3 num3(6, 7);
	int result3 = num3.appendLCS();
	cout << "[Num3] The length of LCS: " << result3 << endl << endl;
	cout << "[Num3] The LCS is ";
	num3.printLCS(num3.getArrayA(), 6, 7);
	cout << endl;	
	
	cout << endl;
	return 0;
}