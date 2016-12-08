#include <iostream>

void goo(int a, double b, const char* s, short n) {}

// ���ڰ� 2���� �Լ��� ������ Ÿ���� �˾Ƴ��� traits

// 1. ����ϴ� �ڵ带 �����ؼ� �⺻ traits�� �����.
template <int N, typename T> struct argument_type
{
	//typedef T type;
};

/*
// N == 0 �϶��� ���� 2��¥�� �Լ��� ó���ϴ� �κ� ����ȭ
template<typename R, typename A1, typename A2 >
struct argument_type<0, R(A1, A2)>
{
typedef A1 type;
};
*/

// N == 0 �϶��� ��� ����� �Լ��� ó���ϴ� �κ� ����ȭ
// �Լ��� ��� ���ڸ� �������ڷ� ǥ���߱� ������ 0��° ���� Ÿ���� ���� �� ����.
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

// N�� 0�� �ƴҶ�
template<int N, typename R, typename T, typename ... Types >
struct argument_type<N, R(T, Types...)>
{
	typedef typename argument_type<N-1, R(Types...)>::type type;
};

// ���ڰ� ���� �Լ� ó���� ��� �ϴ°�?????

template<typename T> void foo(T& a)
{
	typename argument_type<3, T>::type n;

	std::cout << typeid(n).name() << std::endl;
}

int main()
{
	foo(goo);
}