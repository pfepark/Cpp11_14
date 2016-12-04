#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }

// �Ϻ��� ������ �ذ�å
// 1. int&�� int&& ������ �Լ��� 2�� ������ �Ѵ�.
//		��Ȯ���� const int&�� const int&&���� �־�� �Ѵ�.

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