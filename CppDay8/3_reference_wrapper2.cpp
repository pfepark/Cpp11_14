#include <iostream>

// C++ ���� : ���Կ���� ���� �̵��Ѵ�. �ѹ� �ʱ�ȭ�� ������ ������ �� ����.
// reference_wrapper : ���Կ���� ������ �̵��Ѵ�.�̵� ������ ����

// �ᱹ ��ü�� "������ ��ȯ ������ ������" �Դϴ�. - ���� �߿��� ����.

template<typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& o) : obj(&o) {}

	// ���� ���� ������ ȣȯ(��ȯ)�ǰ� �Ѵ�.
	operator T&() { return *obj; }

};

int main()
{
	int n1 = 10;
	int n2 = 20;

	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;

	r1 = r2;		// ������ �̵�? ���� �̵�
	
	int& r3 = r1;	// xreference_wrapper�� ��¥ ������ ȣȯ�ȴ�.

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r1 << std::endl;
}