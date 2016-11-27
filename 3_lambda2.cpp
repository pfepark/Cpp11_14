#include <iostream>
#include <algorithm>

int main()
{
	// 람다표현식 활용

	int x[] = { 1,3,2,4,6,5 };
	// 1. 함수의 정책으로 전달
	std::sort(x, x + _countof(x), [](int a, int b) {return a < b; });

	// 2. auto 변수에 담아서 함수처럼 사용가능
	auto f = [](int a, int b) { return a + b; };		// class LambdaClass {}; LambdaClass() 임시객체까지 만드는데....

	std::cout << f(1, 2) << std::endl;

	// 람다 클래스 이름 확인
	std::cout << typeid(f).name() << std::endl;
	return 0;
}