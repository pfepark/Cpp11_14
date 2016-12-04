#include <iostream>

void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) { }

// 결론 : 인자의 완벽한 전달을 위해서는

// 1. 인자를 받을 때 _T&&(forward reference)_를 사용하자.

// 2. 원본함수에 인자를 보낼 때  _static_cast<T&&>(arg)_로 캐스팅하자.

// 남은 문제 : 인자가 1개 이상일때 처리..
//				리턴값도 돌려줘야 한다.
// forward<>를 구현할 수 있어야 한다. - 도전해보세요;
template<typename F, typename T>
void logTime(F f, T&& arg)
{
	//f(static_cast<T&&>(arg));
	f(std::forward<T>(arg));	// forward()에서 위처럼 캐스팅하고 있다.
}

int main()
{
	int x = 0;

	logTime(foo, 10);
	logTime(goo, x);	// x : lvalue T : int& arg: int& && => int&
	logTime(hoo, 10);	// 10 : rvalue T:int arg: int&&


	std::cout << x << std::endl;
}