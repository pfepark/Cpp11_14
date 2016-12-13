#include <iostream>

void foo(int n) { std::cout << "int" << std::endl; }
void foo(void* n) { std::cout << "void*" << std::endl; }
void goo(char* n) { std::cout << "void*" << std::endl; }

int main()
{
	foo(0);	// 0은 포인터로 변환되기도 하지만 정확히는 int이다.
	foo((void*)0);	// 포인터 버전 호출

#define NULL (void*)0

	goo(NULL);
}