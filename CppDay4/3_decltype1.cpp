#include <iostream>

int main()
{
	int n = 10;
	int& r = n;
	const int c = n;

	// decltype은 해당변수의 선언문을 조사해서 정확한 타입으로 결정해준다.
	decltype(n) d1;	// int d1
	decltype(r) d2;	// int& d2	참조변수의 초기값이 없다. error
	decltype(c) d3;	// const int d3 상수 초기값이 없으므로 error

	int x[3] = { 1, 2,3 };

	decltype(x) d4;		// int d4[3]
	decltype(x) d5 = x; // int d5[3] = x	error

	d4[0] = 2;
}