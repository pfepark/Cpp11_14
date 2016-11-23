#include "stdafx.h"
#include <iostream>

// operator new() 함수 재정의 하기
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
	int* p = new int;				// 인자가 1개인 operator new() 호출
	int* p = new ("park", 10) int;	// 인자가 3개인 operator new() 호출
	delete p;
}