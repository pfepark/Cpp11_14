#include <iostream>

void goo(int a, double d, const char* s)
{
	std::cout << "goo" << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : parameter pack 이라고 부릅니다.
	std::cout << sizeof...(args) << std::endl;
	std::cout << sizeof...(Types) << std::endl;

	// pack expansion : parameter pack을 풀러서 다른 함수로 보내는 기술
	goo(args...);		// ... 위치 기억해 두세요.
						// goo(3, 4.5, "hello")
}

int main()
{
	foo(3, 4.5, "hello");
}