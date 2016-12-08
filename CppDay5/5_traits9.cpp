#include <iostream>

// 1. �ش� ����
#include <type_traits>

template<typename T> void foo_imp(T a, std::true_type)
{
	
}

template<typename T> void foo_imp(T a, std::false_type)
{

}

template<typename T> void foo(T a)
{
	// 2. T�� ���������� �����Ϸ���
	// A. is_pointer<T>::value ����

	if (std::is_pointer<T>::value)
	{
		// ���� : *a = 10 �� ǥ���� ����� �� �����ϴ�.
	}

	// B. *a = 10�� �ϰ� ������ �Լ������ε� ���
	foo_imp(a, std::is_pointer<T>());
}

// Loki ���̺귯�� ����..

int main()
{
	int n = 0;
	foo(n);
}