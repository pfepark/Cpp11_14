#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }


// int&  : lvalue reference
// int&& : rvalue reference
// T&	 : lvalue reference
// T&&	 : forwarding reference
//			규칙 : 인자로 lvalue가 오면 T는 lvalue 참조 타입(int&)이다.
//				   인자로 rvalue가 오면 T는 값 타입(int)이다.
template<typename F, typename T>
void logTime(F f, T&& arg)
{
	f(arg);
}

int main()
{
	int x = 0;

	logTime(foo, 10);	// 10은 rvalue, T : 값 타입 int이므로 arg : T&& => int&&
	logTime(goo, x);	// x는 lvalue, T는 참조 타입(int&)이므로 arg는 T& && => int& && 충돌=> int&
	//logTime(hoo, 10);	
						

	std::cout << x << std::endl;
}