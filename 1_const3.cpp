#include "stdafx.h"

//C++11 constexpr : 컴파일 시간 상수를 만드는 키워드

int main()
{
	int n = 10;

	constexpr int c1 = 10;		// ok
	constexpr int c2 = n;		// error

	const int c3 = 10;			// ok
	const int c4 = n;			// ok

	return 0;
}