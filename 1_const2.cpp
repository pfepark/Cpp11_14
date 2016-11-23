#include "stdafx.h"

void foo(const int c)
{
	int x[c];	// 변수c는 runtime 상수이므로 error
}

int main()
{
	int n = 10;

	int a1[n];	//error 배열의 크기는 변수사용 안됨

	const int c1 = 10;
	int a2[c1];	//ok

	const int c2 = n;
	int a3[c2];	// error. 배열의 크기는 컴파일 시간 상수만 가능
				// C99 : 배열크기로 변수가능. VC가 지원 안함, gcc지원

	return 0;
}