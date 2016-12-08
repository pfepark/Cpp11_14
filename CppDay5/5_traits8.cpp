#include <iostream>

// C++11������ int2type�� ������Ų �Ʒ� ���ø��� �ֽ��ϴ�.
//template<typename T, T N> struct integral_constant
//{
//	static constexpr T value = N;
//};

//integral_constant<int, 0> t0;
//integral_constant<int, 1> t1;
//integral_constant<short, 0> s0;
//integral_constant<short, 0> s1;

// true/false			: �� ������ ��Ÿ���� ��, ���� Ÿ��
// true_type/false_type : �� ������ ��Ÿ���� Ÿ��, �ٸ� Ÿ��
//typedef integral_constant<bool, true> true_type;
//typedef integral_constant<bool, false> false_type;

#include <type_traits>

// ǥ�ؿ� �ִ� is_pointer�� �Ʒ� ó�� �����˴ϴ�. �θ� value�� ������ ����.
//template<typename T>
//struct is_pointer : false_type		// ���
//{
//};
//
//template<typename T>
//struct is_pointer<T*> : true_type {};


template<typename T>
void printv_imp(T a, std::true_type)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_imp(T a, std::false_type)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// ������ ���ο� ���� �����ε� �Լ� ����
	printv_imp(a, std::is_pointer<T>());
}

int main()
{
	int n = 10;

	printv(n);
}