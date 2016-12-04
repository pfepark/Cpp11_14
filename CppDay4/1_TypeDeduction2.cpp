#include <iostream>

// 규칙 1. 인자(T)의 타입이 값이면 함수 인자의 const, volatile, reference는
//			제거하고 타입이 결정된다.
template<typename T> void foo(T a)
{
	//a = 'a';
	//--a;
}

int main()
{
	int n = 10;
	int&r = n;
	const int c = n;
	const int& cr = c;

	foo(n);		// T : int
	foo(r);		// T : int
	foo(c);		// T : int
	foo(cr);	// T : int

	const char* s = "hello";
	foo(s);	// T : const char* 주의 : 인자의 상수성만 제거됨. 포인터를 따라가면 그대로 상수

	const char* const s2 = "aaa";
	foo(s2);	// T : const char*
}