#include <iostream>

int x = 10;

int& foo()
{ 
	return x;
}

int main()
{
	//auto p = v.begin();	// 반복자 꺼낼때 처럼 함수리턴값을 받을 때 auto를 사용하면 편하다....

	auto ret = foo();		// int ret = foo()

	decltype(foo()) ret2 = foo();	// int& ret2 = foo(), decltype(foo())에는 foo()라는 함수 선언을 보고 리턴 타입을 확인. 호출이 아님.
	ret2 = 20;	// 값이 바뀜.

	// foo()를 2번서야 하니 보기 안좋다..
	// C++14 style : 우변의 수식으로 좌변의 타입을 결정해라 (auto의 의미)
	//				그런데, 타입 추론 규칙은 decltype() 규칙으로..
	decltype(auto) ret3 = foo();
	
	std::cout << x << std::endl;

	int n{ 1 };		//C++11 초기화
	int x[1]{ 13 };	// 배열도 가능

	auto a{ 1 };	//배열? int?
}