#include "stdafx.h"
#include <iostream>
#include <new>

int main()
{
	// ������ �߸��� ���� ã�ƺ�����
	int* p1 = new int;	// �Ҵ� ���н� std::bad_alloc ���ܰ� ���´�.

	int* p1 = new (std::nothrow) int;	// �Ҵ� ���н� ���ܴ�� 0�����ش޶�

	if (p1 == 0)
	{
		std::cout << "�޸� �Ҵ� ����" << std::endl;
	}
}