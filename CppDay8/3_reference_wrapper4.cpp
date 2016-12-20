#include <iostream>
#include <functional>

using namespace std::placeholders;	// C++ bind() ����ϱ� ����

void foo(int a, int& b)
{
	std::cout << a << " ";
	std::cout << "foo" << std::endl;
	b = 20;
}

int main()
{
	std::function<void(int)> f;

	int n = 0;

	// ����Ŀ��� �޸� ������ �����ϴ� ����� ������ �ۿ� ����.
	//f = std::bind(&foo, _1, &n);		// ������ : �޸� ������ �ּҸ� ����������
										//			���� �Լ��� ���ڴ� �����̴�.
										//			������ ���氡���� �����Ͱ� �ʿ��ϴ�.
	//std::reference_wrapper<int> r(n);
	//f = std::bind(&foo, _1, r);	// �ᱹ n�� �ּ� ����, ������ �������� ������ ��ȯ����

	//f = std::bind(&foo, _1, std::reference_wrapper<int>(n));	// �ӽð�ü�� ����

	f = std::bind(&foo, _1, std::ref(n));	// std::ref() �� �Լ� ���ø��Դϴ�. �Լ� ���ø��� �߷����ְ� Ŭ���� ���ø��� ���Ѵ�.
											// ���������� reference_wrapper<>�� ���� �����մϴ�.

	f(10);		// foo(10, n)

	std::cout << n << std::endl;
}