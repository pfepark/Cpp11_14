#include "stdafx.h"

// constexpr �Լ� : ���ڰ� ������ �ð� ����̰�, �Լ� �����θ� ������ �ð���
//					����� �� �ִٸ� ������ �ð��� �ش޶�� �ǹ�.
// �����ϸ� �Ϲ��Լ��� ó����. �׷��Ƿ� ������ �Լ��� constexpr�� ������.
constexpr int Add(int a, int b)
{
	return a + b;
}

// constexpr ���� : �ϳ��� ���Ϲ��� �־�� �Ѵ�.
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