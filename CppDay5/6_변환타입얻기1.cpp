#include <iostream>
#include <type_traits>

// is_pointer<T>::value : T�� Ư�� ����
// remove_pointer<T>::type : T�� ���� Ÿ�� ���

// ����� ��
// 1. primary template�� typedef T type�� �ִ´�.
// 2. �κ� ����ȭ�� ���ؼ� ���ϴ� Ÿ���� �򵵷� Ÿ�Ժ����� �ؾ� �Ѵ�.
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