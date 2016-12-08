#include <iostream>
#include <type_traits>

// 만드는 법
// 1. primary template에 typedef T type을 넣는다.
// 2. 부분 전문화를 통해서 원하는 타입을 얻도록 타입분할을 해야 한다.
template<typename T> struct array_base_type
{
	typedef T type;
};

template<typename T, int N> struct array_base_type<T[N]>
{
	typedef T type;
};

template<typename T> void foo(T& a)
{
	typename array_base_type<T>::type n;

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	int x[5] = { 1,2,3,4,5 };
	foo(x);
}