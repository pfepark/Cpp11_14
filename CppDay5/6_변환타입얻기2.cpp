#include <iostream>
#include <type_traits>

// ����� ��
// 1. primary template�� typedef T type�� �ִ´�.
// 2. �κ� ����ȭ�� ���ؼ� ���ϴ� Ÿ���� �򵵷� Ÿ�Ժ����� �ؾ� �Ѵ�.
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