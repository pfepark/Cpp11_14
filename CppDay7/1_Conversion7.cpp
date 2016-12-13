#include <iostream>

void foo(int n) { std::cout << "int" << std::endl; }
void foo(void* n) { std::cout << "void*" << std::endl; }
void goo(char* n) { std::cout << "void*" << std::endl; }

// 포인터 0을 만들자.
struct xnullptr_t
{
	// void*로의 형변환 필요
	template <typename T>
	operator T*() { return (T*)0; }
	explicit operator bool() { return false; }
};

xnullptr_t xnullptr;

int main()
{
	foo(0);	// 0은 포인터로 변환되기도 하지만 정확히는 int이다.
	foo(xnullptr);	// void* 버전 호출
	goo(xnullptr);
}