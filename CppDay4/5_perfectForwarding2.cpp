#include <iostream>

void foo(int a) {}
void goo(int& a) {}
void hoo(int&& a) {}

template<typename T> struct identity
{
	typedef T Type;
};

// logTime의 인자로 10이 오거나 n이 오거나 변수 a는 lvalue이다.
// 아래 함수는 T&로 받으면 된다.
template<typename T> T&& xforward(typename identity<T>& obj)
{
	return static_cast<T&&>(obj);
}

template<typename F, typename T> void logTime(F f, T&& a)
{
	// main에서 n을 보내면 T는...
	// T : int&   T&& => int& && => int&
	// 따라서 아래 캐스팅은 static_cast<int&>(a)
	//f(static_cast<T&&>(a));

	// 현재 상황은 a : int&이다. 아래 코드를 생각해보자.
	// xforward에서 T는? 규칙2를 따라 int.
	// 그러므로 xforward의 캐스팅은 static_cast<T&&>(obj) -> static_cst<int&&>(obj) 
	// lvalue n이 왔는데 xforward에서 rvalue로 캐스팅하려고 하니 에러...
	//f(xforward(a));

	f(xforward<T>(a));	// 컴파일러가 타입을 결정하면 int& => int로 변경하게 된다.
					// 반드시 사용자가 타입을 전달해야 한다.
}

int main()
{
	int n;
	//logTime(foo, 10);	// rvalue
	logTime(goo, n);	// lvalue 모두 받기 위해서 T&&로 선언.
	//logTime(hoo, 10);	// int&& a = 10; 인데 a자체는 lvalue이므로 위 템블릿함수는 형변환해서 넘긴다.
}