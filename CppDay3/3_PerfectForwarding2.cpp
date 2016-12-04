#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }

// 완벽한 전달자 해결책
// 1. int&와 int&& 버전의 함수를 2개 만들어야 한다.
//		정확히는 const int&와 const int&&까지 있어야 한다.

template<typename F>
void logTime(F f, int& arg)
{
	f(arg);
}

template<typename F>
void logTime(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int x = 0;

	logTime(foo, 10);	//foo(10);
	logTime(goo, x);	//goo(x);

	std::cout << x << std::endl;
}