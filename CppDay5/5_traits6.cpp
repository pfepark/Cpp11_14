// traits 1�� ����..

#include <iostream>

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

// �Լ������ε��� �Լ� ������ ������ �ð��� �����ȴ�!!
// ���õ��� ���� �Լ� ���ø��� �ν��Ͻ�ȭ ���� �ʴ´�.

template<typename T>
void printv_imp(T a, YES)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_imp(T a, NO)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// ������ ���ο� ���� �����ε� �Լ� ����
	printv_imp(a, IsPointer<T>::value);		// �����Ͷ�� �� (1)
											//     �ƴϸ� ���� (0)
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}