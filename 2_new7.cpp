#include "stdafx.h"
#include <iostream>

void* operator new(size_t sz)
{
	void* p = malloc(sz);	// �޸� �Ҵ��� �õ�
	if (p == 0) throw std::bad_alloc();
	return p;
}

// nothrow ������
// ���� ��������� ������ �Լ� �����ε������� ���ڰ� �ʿ��Ҷ���
// ��κ� empty class �� ����Ѵ�. - �ٽ�.
struct nothrow_t {}; // sizeof(nothrow_t) : 1

nothrow_t nothrow;	// ��������

void* operator new(size_t sz, nothrow_t )
{
	void* p = malloc(sz);
	return p;		// �����ϸ� 0�� �׷��� ����.
}

int main()
{
	int* p1 = new (nothrow) int;	// �Ҵ� ���н� ���ܴ�� 0�����ش޶�

	if (p1 == 0)
	{
		std::cout << "�޸� �Ҵ� ����" << std::endl;
	}
}