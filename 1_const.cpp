#include "stdafx.h"
// 1_const.cpp

#include <iostream>

using namespace std;

int main()
{
	//const int c = 10;	// ������ �ð� ��� - ������ �ð��� ��ũ��ó�� ���� ġȯ (��ũ�� ó�� ������ Ÿ�ӿ� c������ 10�� ����.)
	int n = 10;
	const int c = n;	// ��Ÿ�� ���.. �����Ͻÿ� ���� �� �� ����.

	//int* p = &c;	// error. ��� �ּҴ� ������ ����Ű�� �����Ϳ� ���� �� ����.
	int* p = (int*)&c;	// ok
						// c++ style : const_cast<int*>(&c)

	*p = 20;

	cout << c << endl;		// 10	20
	cout << (*p) << endl;	// 20	20

	return 0;
}