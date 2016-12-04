#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }

template<typename F, typename T>
void logTime(F f, T&& arg)
{
	// 10이 인자로 오면 T : int, T&& : int&& 이므로
	// static_cast<int&&>(arg); lvalue인 arg를 rvalue로 캐스팅

	// x가 오면 T : int&, T&& : int& && 즉 int& static_cast<int& &&>(arg) 를 하는 모양. 
											//	다시 말하면 static_cast<int&>(arg).
	// lvalue인 arg를 lvalue로 캐스팅
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