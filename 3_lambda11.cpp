#include <iostream>

//void foo(auto a) {}	// error. 함수 인자로 auto 안됨.

int main()
{
	auto f1 = [](int a) { return a * a; };
	auto f2 = []()		{ return 10; };
	auto f3 = []		{ return 10; };	// 인자가 없으면 () 생략 가능. //nullary lambda.

	// 숙제. C++14 람다인자는 auto 가능
	auto f4 = [](auto a, auto b) { return a + b;  };
	// 클래스 예측하자. MEC++ lambda에 있음

	std::cout << f4(1, 2.5) << std::endl;

	// 다음시간 항목 1-6, 1-18 perfect forwarding.
}