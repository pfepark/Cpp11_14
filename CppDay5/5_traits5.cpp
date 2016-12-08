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

//�������� ���� �����Ͱ� �ƴ� ��츦 ó���ϴ� �Լ�
template<typename T>
void printv_pointer(T a)
{
	std::cout << a << " : " << *a << std::endl;
}

template<typename T>
void printv_not_pointer(T a)
{
	std::cout << a << std::endl;
}

template<typename T> void printv(T a)
{
	// �ٽ� : ������ �ʴ� �Լ� ���ø��� ��¥ �Լ��� ���� �����Ƿ� ������ ���� �ʴ´�.. �ڵ带 �ȸ����.

	// ������ if ���� ����ð� �б⹮�̹Ƿ� if () ������ �������� ������� 
	// �Ʒ� 2���� �Լ� ���ø��� ��� ���ȴٰ� �Ǵ��Ѵ�.

	// �ᱹ 2�� �Լ� ��� ���� �Լ��� �����ǹǷ� ���� - ������ ����.
	if (IsPointer<T>::value)
		printv_pointer(a);
	else
		printv_not_pointer(a);
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}