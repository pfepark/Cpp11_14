#include "stdafx.h"
#include <iostream>

// operator new() �Լ� ������ �ϱ�
void* operator new(size_t sz)
{
	std::cout << "my operator new: " << sz << std::endl;
	return malloc(sz);
}

void* operator new(size_t sz, char* s, int n)
{
	std::cout << "my operator new2: " << sz << std::endl;
	return malloc(sz);
}

void operator delete(void* p)
{
	std::cout << "my operator delete" << std::endl;
	free(p);
}

int main()
{
	int* p = new int;				// ���ڰ� 1���� operator new() ȣ��
	int* p = new ("park", 10) int;	// ���ڰ� 3���� operator new() ȣ��
	delete p;
}