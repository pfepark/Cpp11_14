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

template<typename T> void printv(T a)
{
	if (IsPointer<T>::value)
		std::cout << a << " : " << *a << std::endl;
	else
		std::cout << a << std::endl;
}

int main()
{
	int n = 10;

	printv(n);		// error�ε�...int ���������� ���������� ��. ������ Ÿ�ӿ� if (false)���� �Ʒ� ������ ���� �� �� ������.. �������� ���� Ȯ���ϰ� ����ȭ�� �����ϹǷ� ������ ����.
	printv(&n);
}