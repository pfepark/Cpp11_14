#include "stdafx.h"

void foo(const int c)
{
	int x[c];	// ����c�� runtime ����̹Ƿ� error
}

int main()
{
	int n = 10;

	int a1[n];	//error �迭�� ũ��� ������� �ȵ�

	const int c1 = 10;
	int a2[c1];	//ok

	const int c2 = n;
	int a3[c2];	// error. �迭�� ũ��� ������ �ð� ����� ����
				// C99 : �迭ũ��� ��������. VC�� ���� ����, gcc����

	return 0;
}