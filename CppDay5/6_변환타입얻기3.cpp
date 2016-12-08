#include <iostream>
#include <type_traits>

int goo(short, char)	// int (short, char) 타입
{
	return 0;
}

template<typename T> struct result_type
{
	typedef T type;
};

template<typename R, typename A1, typename A2> struct result_type<R(A1, A2)>
{
	typedef R type;
};

template<typename T> void foo(T& a)
{
	typename result_type<T>::type n;		// 단, 함수인자는 2개라고 가정

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(goo);
}