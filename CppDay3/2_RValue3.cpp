#include <iostream>

// ������ �Լ� �����ε�
void foo(int& a)
{
	std::cout << "int&" << std::endl;			// 1
}

void foo(const int& a)
{
	std::cout << "const int&" << std::endl;			// 2
}

void foo(int&& a)
{
	std::cout << "int&&" << std::endl;			// 3
}

int main()
{
	int n = 10;

	foo(n);		// 1, ������ 2.
	foo(10);	// 3, ������ 2.

	int& r1 = n;
	foo(r1);	// 1, ������ 2

	int&& r2 = 10;	// 10�� rvalue ������ 
					// 10�� ����Ű�� r2�� lvalue �̴�. (�̸��� �ְ�, ���Ͻ��� �Ѿ� ����)
	foo(r2);	// "�̸��� �ִ� rvalue reference�� lvalue �̴�."

	foo(static_cast<int&&>(r2));	// 3�� ȣ��
									// �� ĳ������ _1_ �� ĳ�����ϴ� ���̴�.
									// 1. rvalue
									// 2. rvalue reference
}