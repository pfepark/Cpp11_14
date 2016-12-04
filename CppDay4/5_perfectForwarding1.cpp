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
	logTime(goo, n);	// lvalue ��� �ޱ� ���ؼ� T&&�� ����.
	logTime(hoo, 10);	// int&& a = 10; �ε� a��ü�� lvalue�̹Ƿ� �� �ۺ��Լ��� ����ȯ�ؼ� �ѱ��.
}