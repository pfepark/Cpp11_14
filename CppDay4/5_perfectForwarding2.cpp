#include <iostream>

void foo(int a) {}
void goo(int& a) {}
void hoo(int&& a) {}

template<typename T> struct identity
{
	typedef T Type;
};

// logTime�� ���ڷ� 10�� ���ų� n�� ���ų� ���� a�� lvalue�̴�.
// �Ʒ� �Լ��� T&�� ������ �ȴ�.
template<typename T> T&& xforward(typename identity<T>& obj)
{
	return static_cast<T&&>(obj);
}

template<typename F, typename T> void logTime(F f, T&& a)
{
	// main���� n�� ������ T��...
	// T : int&   T&& => int& && => int&
	// ���� �Ʒ� ĳ������ static_cast<int&>(a)
	//f(static_cast<T&&>(a));

	// ���� ��Ȳ�� a : int&�̴�. �Ʒ� �ڵ带 �����غ���.
	// xforward���� T��? ��Ģ2�� ���� int.
	// �׷��Ƿ� xforward�� ĳ������ static_cast<T&&>(obj) -> static_cst<int&&>(obj) 
	// lvalue n�� �Դµ� xforward���� rvalue�� ĳ�����Ϸ��� �ϴ� ����...
	//f(xforward(a));

	f(xforward<T>(a));	// �����Ϸ��� Ÿ���� �����ϸ� int& => int�� �����ϰ� �ȴ�.
					// �ݵ�� ����ڰ� Ÿ���� �����ؾ� �Ѵ�.
}

int main()
{
	int n;
	//logTime(foo, 10);	// rvalue
	logTime(goo, n);	// lvalue ��� �ޱ� ���ؼ� T&&�� ����.
	//logTime(hoo, 10);	// int&& a = 10; �ε� a��ü�� lvalue�̹Ƿ� �� �ۺ��Լ��� ����ȯ�ؼ� �ѱ��.
}