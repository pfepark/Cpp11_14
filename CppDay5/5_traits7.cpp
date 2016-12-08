#include <iostream>

// �߿���. ������ ������.
template<int N> struct int2type
{
	enum { value = N};
};

template<typename T>
struct IsPointer
{
	static constexpr bool value = false;
};

template<typename T>
struct IsPointer<T*>
{
	static constexpr bool value = true;
};
/*
int main()
{
	foo(0);
	foo(1);	// 0, 1�� ���� Ÿ��. �׷��Ƿ� foo(0), foo(1)�� ���� foo �Լ��� ȣ���Ѵ�.

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);	// t0, t1�� �ٸ� Ÿ���̹Ƿ� foo(t0), foo(t1)�� �ٸ� �Լ� ȣ��
}
*/

template<typename T>
void printv_imp(T a, int2type<1>)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_imp(T a, int2type<0>)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// ������ ���ο� ���� �����ε� �Լ� ����
	printv_imp(a, int2type<IsPointer<T>::value>() );		
}

void func1(int2type<1> a)
{
	std::cout << "int2type<1>" << std::endl;
}

int main()
{
	int n = 10;

	printv(n);

	int2type<1> a1;
	int2type<1> a2;

	func1(a1);
	func1(a2);

	
}