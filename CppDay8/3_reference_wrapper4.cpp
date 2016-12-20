#include <iostream>
#include <functional>

using namespace std::placeholders;	// C++ bind() 사용하기 위해

void foo(int a, int& b)
{
	std::cout << a << " ";
	std::cout << "foo" << std::endl;
	b = 20;
}

int main()
{
	std::function<void(int)> f;

	int n = 0;

	// 값방식에서 메모리 정보를 전달하는 방법은 포인터 밖에 없다.
	//f = std::bind(&foo, _1, &n);		// 문제점 : 메모리 정보인 주소를 보관하지만
										//			원본 함수의 인자는 참조이다.
										//			참조로 변경가능한 포인터가 필요하다.
	//std::reference_wrapper<int> r(n);
	//f = std::bind(&foo, _1, r);	// 결국 n의 주소 보관, 원본에 보낼때는 참조로 변환가능

	//f = std::bind(&foo, _1, std::reference_wrapper<int>(n));	// 임시객체로 전달

	f = std::bind(&foo, _1, std::ref(n));	// std::ref() 는 함수 템플릿입니다. 함수 템플릿은 추론해주고 클래스 템플릿은 못한다.
											// 내부적으로 reference_wrapper<>를 만들어서 리턴합니다.

	f(10);		// foo(10, n)

	std::cout << n << std::endl;
}