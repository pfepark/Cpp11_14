#include "stdafx.h"
#include <iostream>
#include <new>

int main()
{
	// 다음중 잘못된 것을 찾아보세용
	int* p1 = new int;	// 할당 실패시 std::bad_alloc 예외가 나온다.

	int* p1 = new (std::nothrow) int;	// 할당 실패시 예외대신 0리턴해달라

	if (p1 == 0)
	{
		std::cout << "메모리 할당 실패" << std::endl;
	}
}