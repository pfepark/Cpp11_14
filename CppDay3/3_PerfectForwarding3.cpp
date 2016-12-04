#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }

// 완벽한 전달자 해결책
// 1. int&와 int&& 버전의 함수를 2개 만들어야 한다.
//		정확히는 const int&와 const int&&까지 있어야 한다.

// 2. int&& 버전에서는 원본에 보낼때 static_cast<int&&> 해서 보내야 한다.

template<typename F>
void logTime(F f, int& arg)
{
	f(arg);
}

template<typename F>
void logTime(F f, int&& arg)
{
	//f(arg);

	// 원래 10은 rvalue였는데 arg로 받으면서 lvalue가 되었다.
	// 다시 rvalue로 변경해서 전달한다.

	f(static_cast<int&&>(arg));
}

int main()
{
	int x = 0;

	logTime(foo, 10);	//foo(10);
	logTime(goo, x);	//goo(x);
	logTime(hoo, 10);	//hoo(10)이므로 되어야 한다. void logTime(F f, int&& arg)가 호출되는데...
						// 10은 rvalue이지만 arg는 lvalue이다. hoo(int&)를 찾게 된다.

	std::cout << x << std::endl;
}