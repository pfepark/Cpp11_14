// 3_lambdaexpression3.cpp

#include <iostream>


// 람다와 타입 - 30page
// 핵심) 모든 람다 표현식은 다른 타입이다.
int main()
{
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };

	f2 = [](int a, int b) { return a + b; };	// 될까요? 안됨.. 생성된 람다와 타입이 다르다.
	// 람다로 초기화된 auto 변수는 절대 다른 람다를 가르킬 수 없게 된다.

	// f1, f2는 같은 타입일까요? 다른 타입일까요?

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
}