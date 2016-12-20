#include <iostream>

// C++ ���� : ���Կ���� ���� �̵��Ѵ�. �ѹ� �ʱ�ȭ�� ������ ������ �� ����.
// reference_wrapper : ���Կ���� ������ �̵��Ѵ�.�̵� ������ ����
int main()
{
	int n1 = 10;
	int n2 = 20;

	//int& r1 = n1;
	//int& r2 = n2;

	std::reference_wrapper<int> r1 = n1;
	std::reference_wrapper<int> r2 = n2;

	r1 = r2;		// ������ �̵�? ���� �̵�

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r1 << std::endl;
}