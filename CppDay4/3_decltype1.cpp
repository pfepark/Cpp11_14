#include <iostream>

int main()
{
	int n = 10;
	int& r = n;
	const int c = n;

	// decltype�� �ش纯���� ������ �����ؼ� ��Ȯ�� Ÿ������ �������ش�.
	decltype(n) d1;	// int d1
	decltype(r) d2;	// int& d2	���������� �ʱⰪ�� ����. error
	decltype(c) d3;	// const int d3 ��� �ʱⰪ�� �����Ƿ� error

	int x[3] = { 1, 2,3 };

	decltype(x) d4;		// int d4[3]
	decltype(x) d5 = x; // int d5[3] = x	error

	d4[0] = 2;
}