#include <iostream>

// step 3. 가변인자 전달된 인자 꺼내기

// 핵심 : 가변 인자 템플릿으로 함수(클래스)템플릿을 만들때, 1번째 인자는 반드시 별도의 타입으로 받아야 한다.
template<typename T, typename ... Types> void foo(T value, Types ... args)
{
	static int n = 0;
	n++;
	std::cout << n << " : ";
	std::cout << typeid(T).name() << " : " << value << std::endl;

	foo(args...);		// foo(4.5, "hello") value : 4.5, args : "hello"
						// foo("hello")
						// foo()		// 함수가 가변인자 개수만큼 만들어지므로 주의필요
}

// 재귀를 종료하기 위해 인자 없는 함수 필요.
void foo() {}

int main()
{
	foo(3, 4.5, "hello");	// value : 3, args : 4.5, "hello"
}