// 3_lambdaexpression3.cpp

#include <iostream>


// ���ٿ� Ÿ�� - 30page
// �ٽ�) ��� ���� ǥ������ �ٸ� Ÿ���̴�.
int main()
{
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };

	f2 = [](int a, int b) { return a + b; };	// �ɱ��? �ȵ�.. ������ ���ٿ� Ÿ���� �ٸ���.
	// ���ٷ� �ʱ�ȭ�� auto ������ ���� �ٸ� ���ٸ� ����ų �� ���� �ȴ�.

	// f1, f2�� ���� Ÿ���ϱ��? �ٸ� Ÿ���ϱ��?

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
}