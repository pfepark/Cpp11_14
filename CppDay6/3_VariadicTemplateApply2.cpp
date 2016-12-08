#include <iostream>

void goo(int a, int b) {}

// ���ڰ� 2���� �Լ��� ������ Ÿ���� �˾Ƴ��� traits

// 1. ����ϴ� �ڵ带 �����ؼ� �⺻ traits�� �����.
template <int N, typename T> struct argument_type
{
	//typedef T type;
};

// 2. �κ� ����ȭ�� ���ؼ� Ÿ���� ���ҽõ� (�Լ� Ÿ�� => ���� Ÿ��, ���� Ÿ������ ����)
/*
template<int N, typename R, typename A1, typename A2 >
struct argument_type<N, R(A1, A2)>
{
	// typedef�� ���� �� ������? N�� �������� �ʾƼ� �ȵ�.
};
*/

// N == 0 �϶��� �κ� ����ȭ
template<typename R, typename A1, typename A2 >
struct argument_type<0, R(A1, A2)>
{
	typedef A1 type;
};

// N == 1 �϶��� �κ� ����ȭ
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