#include <iostream>

void goo(int a, double b, const char* s, short n) {}

// 인자가 2개인 함수의 인자의 타입을 알아내는 traits

// 1. 사용하는 코드를 생각해서 기본 traits를 만든다.
template <int N, typename T> struct argument_type
{
	//typedef T type;
};

/*
// N == 0 일때의 인자 2개짜리 함수를 처리하는 부분 전문화
template<typename R, typename A1, typename A2 >
struct argument_type<0, R(A1, A2)>
{
typedef A1 type;
};
*/

// N == 0 일때의 모든 모양의 함수를 처리하는 부분 전문화
// 함수의 모든 인자를 가변인자로 표현했기 때문에 0번째 인자 타입을 구할 수 없다.
/*
template<typename R, typename ... Types >
struct argument_type<0, R(Types...)>
{
	typedef ? type;
};
*/

template<typename R, typename T, typename ... Types >
struct argument_type<0, R(T, Types...)>
{
	typedef T type;
};

// N이 0이 아닐때
template<int N, typename R, typename T, typename ... Types >
struct argument_type<N, R(T, Types...)>
{
	typedef typename argument_type<N-1, R(Types...)>::type type;
};

// 인자가 없는 함수 처리는 어떻게 하는가?????

template<typename T> void foo(T& a)
{
	typename argument_type<3, T>::type n;

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(goo);
}