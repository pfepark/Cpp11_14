#include <iostream>

// T�� ���������� �����ϴ� ���

// traits : T�� Ÿ���� Ư���� �����ϴ� ���

// 1. primary template : false ����(value = false ��� �ǹ�)
// 2. �κ� ����ȭ		: true ����(value = true ��� �ǹ�)
template<typename T>
struct IsPointer
{
	//enum { value = false };				// ���� ��Ÿ��
	static constexpr bool value = false;	// �ֽ� ��Ÿ��
};

template<typename T>
struct IsPointer<T*>
{
	//enum { value = true };				// ���� ��Ÿ��
	static constexpr bool value = true;		// �ֽ� ��Ÿ��
};

template<typename T> void foo(T a)
{
	if (IsPointer<T>::value)
		std::cout << "Pointer" << std::endl;
	else
		std::cout << "not Pointer" << std::endl;
}

int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}