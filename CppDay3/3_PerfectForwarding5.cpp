#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }

template<typename F, typename T>
void logTime(F f, T&& arg)
{
	// 10�� ���ڷ� ���� T : int, T&& : int&& �̹Ƿ�
	// static_cast<int&&>(arg); lvalue�� arg�� rvalue�� ĳ����

	// x�� ���� T : int&, T&& : int& && �� int& static_cast<int& &&>(arg) �� �ϴ� ���. 
											//	�ٽ� ���ϸ� static_cast<int&>(arg).
	// lvalue�� arg�� lvalue�� ĳ����
	f(static_cast<T&&>(arg));
}

int main()
{
	int x = 0;

	logTime(foo, 10);
	logTime(goo, x);	// x : lvalue T : int& arg: int& && => int&
	logTime(hoo, 10);	// 10 : rvalue T:int arg: int&&
						

	std::cout << x << std::endl;
}