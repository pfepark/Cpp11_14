#include <iostream>

//void foo(auto a) {}	// error. �Լ� ���ڷ� auto �ȵ�.

int main()
{
	auto f1 = [](int a) { return a * a; };
	auto f2 = []()		{ return 10; };
	auto f3 = []		{ return 10; };	// ���ڰ� ������ () ���� ����. //nullary lambda.

	// ����. C++14 �������ڴ� auto ����
	auto f4 = [](auto a, auto b) { return a + b;  };
	// Ŭ���� ��������. MEC++ lambda�� ����

	std::cout << f4(1, 2.5) << std::endl;

	// �����ð� �׸� 1-6, 1-18 perfect forwarding.
}