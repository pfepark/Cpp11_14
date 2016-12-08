#include <iostream>
#include <type_traits>

// is_pointer<T>::value : T의 특성 조사
// remove_pointer<T>::type : T의 변형 타입 얻기

// 만드는 법
// 1. primary template에 typedef T type을 넣는다.
// 2. 부분 전문화를 통해서 원하는 타입을 얻도록 타입분할을 해야 한다.
template<typename T> struct xremove_pointer
{
	typedef T type;
};

template<typename T> struct xremove_pointer<T*>
{
	typedef T type;
};

template<typename T> void foo(T a)
{
	typename std::xremove_pointer<T>::type n;

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	int n = 10;
	foo(&n);
}