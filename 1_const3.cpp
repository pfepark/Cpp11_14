#include "stdafx.h"

//C++11 constexpr : ������ �ð� ����� ����� Ű����

int main()
{
	int n = 10;

	constexpr int c1 = 10;		// ok
	constexpr int c2 = n;		// error

	const int c3 = 10;			// ok
	const int c4 = n;			// ok

	return 0;
}