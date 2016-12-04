#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }


// int&  : lvalue reference
// int&& : rvalue reference
// T&	 : lvalue reference
// T&&	 : forwarding reference
//			��Ģ : ���ڷ� lvalue�� ���� T�� lvalue ���� Ÿ��(int&)�̴�.
//				   ���ڷ� rvalue�� ���� T�� �� Ÿ��(int)�̴�.
template<typename F, typename T>
void logTime(F f, T&& arg)
{
	f(arg);
}

int main()
{
	int x = 0;

	logTime(foo, 10);	// 10�� rvalue, T : �� Ÿ�� int�̹Ƿ� arg : T&& => int&&
	logTime(goo, x);	// x�� lvalue, T�� ���� Ÿ��(int&)�̹Ƿ� arg�� T& && => int& && �浹=> int&
	//logTime(hoo, 10);	
						

	std::cout << x << std::endl;
}