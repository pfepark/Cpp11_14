#include <iostream>
#include <type_traits>

int goo(short, char)	// int (short, char) Ÿ��
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
	typename result_type<T>::type n;		// ��, �Լ����ڴ� 2����� ����

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(goo);
}