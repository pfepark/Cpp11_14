#include <iostream>

void foo(int a) {}
void goo(int& a) {}
void hoo(int&& a) {}

template<typename F, typename T> void logTime(F f, T&& a)
{
	f(static_cast<T&&>(a));
}

int main()
{
	int n;
	logTime(foo, 10);	// rvalue
	logTime(goo, n);	// lvalue 모두 받기 위해서 T&&로 선언.
	logTime(hoo, 10);	// int&& a = 10; 인데 a자체는 lvalue이므로 위 템블릿함수는 형변환해서 넘긴다.
}