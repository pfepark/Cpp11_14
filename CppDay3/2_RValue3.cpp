#include <iostream>

// 참조와 함수 오버로딩
void foo(int& a)
{
	std::cout << "int&" << std::endl;			// 1
}

void foo(const int& a)
{
	std::cout << "const int&" << std::endl;			// 2
}

void foo(int&& a)
{
	std::cout << "int&&" << std::endl;			// 3
}

int main()
{
	int n = 10;

	foo(n);		// 1, 없으면 2.
	foo(10);	// 3, 없으면 2.

	int& r1 = n;
	foo(r1);	// 1, 없으면 2

	int&& r2 = 10;	// 10은 rvalue 이지만 
					// 10을 가르키는 r2는 lvalue 이다. (이름이 있고, 단일식을 넘어 존재)
	foo(r2);	// "이름이 있는 rvalue reference는 lvalue 이다."

	foo(static_cast<int&&>(r2));	// 3번 호출
									// 이 캐스팅은 _1_ 로 캐스팅하는 것이다.
									// 1. rvalue
									// 2. rvalue reference
}