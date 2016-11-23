#include "stdafx.h"

// constexpr 함수 : 인자가 컴파일 시간 상수이고, 함수 구현부를 컴파일 시간에
//					계산할 수 있다면 컴파일 시간에 해달라는 의미.
// 실패하면 일반함수로 처리됨. 그러므로 간단한 함수는 constexpr을 붙이자.
constexpr int Add(int a, int b)
{
	return a + b;
}

// constexpr 조건 : 하나의 리턴문만 있어야 한다.
/*
constexpr int factorial(int a)
{
	if (a == 1)
		return 1;
	return a * factorial(a - 1);
}
*/
constexpr int factorial(int a)
{
	return a == 1? 1 : a * factorial(a - 1);
}

int main()
{
	int x[Add(1, 2)];

	int n1 = 10;
	int n2 = 20;

	int s = Add(n1, n2);

	//int y[Add(n1, n2)];	// error

	return 0;
}