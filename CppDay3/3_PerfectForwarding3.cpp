#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }

// �Ϻ��� ������ �ذ�å
// 1. int&�� int&& ������ �Լ��� 2�� ������ �Ѵ�.
//		��Ȯ���� const int&�� const int&&���� �־�� �Ѵ�.

// 2. int&& ���������� ������ ������ static_cast<int&&> �ؼ� ������ �Ѵ�.

template<typename F>
void logTime(F f, int& arg)
{
	f(arg);
}

template<typename F>
void logTime(F f, int&& arg)
{
	//f(arg);

	// ���� 10�� rvalue���µ� arg�� �����鼭 lvalue�� �Ǿ���.
	// �ٽ� rvalue�� �����ؼ� �����Ѵ�.

	f(static_cast<int&&>(arg));
}

int main()
{
	int x = 0;

	logTime(foo, 10);	//foo(10);
	logTime(goo, x);	//goo(x);
	logTime(hoo, 10);	//hoo(10)�̹Ƿ� �Ǿ�� �Ѵ�. void logTime(F f, int&& arg)�� ȣ��Ǵµ�...
						// 10�� rvalue������ arg�� lvalue�̴�. hoo(int&)�� ã�� �ȴ�.

	std::cout << x << std::endl;
}