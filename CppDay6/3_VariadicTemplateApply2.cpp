#include <iostream>

void goo(int a, int b) {}

// 인자가 2개인 함수의 인자의 타입을 알아내는 traits

// 1. 사용하는 코드를 생각해서 기본 traits를 만든다.
template <int N, typename T> struct argument_type
{
	//typedef T type;
};

// 2. 부분 전문화를 통해서 타입의 분할시도 (함수 타입 => 리턴 타입, 인자 타입으로 분할)
/*
template<int N, typename R, typename A1, typename A2 >
struct argument_type<N, R(A1, A2)>
{
	// typedef를 만들 수 있을까? N이 정해지지 않아서 안됨.
};
*/

// N == 0 일때의 부분 전문화
template<typename R, typename A1, typename A2 >
struct argument_type<0, R(A1, A2)>
{
	typedef A1 type;
};

// N == 1 일때의 부분 전문화
template<typename R, typename A1, typename A2 >
struct argument_type<1, R(A1, A2)>
{
	typedef A2 type;
};

template<typename T> void foo(T& a)
{
	typename argument_type<0, T>::type n;

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(goo);
}