#include "stdafx.h"
// 1_const.cpp

#include <iostream>

using namespace std;

int main()
{
	//const int c = 10;	// 컴파일 시간 상수 - 컴파일 시간에 매크로처럼 문자 치환 (매크로 처럼 컴파일 타임에 c변수는 10이 들어간다.)
	int n = 10;
	const int c = n;	// 런타임 상수.. 컴파일시에 값을 알 수 없다.

	//int* p = &c;	// error. 상수 주소는 비상수를 가르키는 포인터에 담을 수 없다.
	int* p = (int*)&c;	// ok
						// c++ style : const_cast<int*>(&c)

	*p = 20;

	cout << c << endl;		// 10	20
	cout << (*p) << endl;	// 20	20

	return 0;
}