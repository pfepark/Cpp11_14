#include "stdafx.h"
#include <iostream>

void* operator new(size_t sz)
{
	void* p = malloc(sz);	// 메모리 할당을 시도
	if (p == 0) throw std::bad_alloc();
	return p;
}

// nothrow 버전ㄱ
// 실제 사용하지는 않지만 함수 오버로딩때문에 인자가 필요할때는
// 대부분 empty class 를 사용한다. - 핵심.
struct nothrow_t {}; // sizeof(nothrow_t) : 1

nothrow_t nothrow;	// 전역변수

void* operator new(size_t sz, nothrow_t )
{
	void* p = malloc(sz);
	return p;		// 실패하면 0을 그래도 리턴.
}

int main()
{
	int* p1 = new (nothrow) int;	// 할당 실패시 예외대신 0리턴해달라

	if (p1 == 0)
	{
		std::cout << "메모리 할당 실패" << std::endl;
	}
}