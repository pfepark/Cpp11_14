#include <iostream>
#include <algorithm>

int main()
{
	// ����ǥ���� Ȱ��

	int x[] = { 1,3,2,4,6,5 };
	// 1. �Լ��� ��å���� ����
	std::sort(x, x + _countof(x), [](int a, int b) {return a < b; });

	// 2. auto ������ ��Ƽ� �Լ�ó�� ��밡��
	auto f = [](int a, int b) { return a + b; };		// class LambdaClass {}; LambdaClass() �ӽð�ü���� ����µ�....

	std::cout << f(1, 2) << std::endl;

	// ���� Ŭ���� �̸� Ȯ��
	std::cout << typeid(f).name() << std::endl;
	return 0;
}