#include <iostream>

int x = 10;

int& foo()
{ 
	return x;
}

int main()
{
	//auto p = v.begin();	// �ݺ��� ������ ó�� �Լ����ϰ��� ���� �� auto�� ����ϸ� ���ϴ�....

	auto ret = foo();		// int ret = foo()

	decltype(foo()) ret2 = foo();	// int& ret2 = foo(), decltype(foo())���� foo()��� �Լ� ������ ���� ���� Ÿ���� Ȯ��. ȣ���� �ƴ�.
	ret2 = 20;	// ���� �ٲ�.

	// foo()�� 2������ �ϴ� ���� ������..
	// C++14 style : �캯�� �������� �º��� Ÿ���� �����ض� (auto�� �ǹ�)
	//				�׷���, Ÿ�� �߷� ��Ģ�� decltype() ��Ģ����..
	decltype(auto) ret3 = foo();
	
	std::cout << x << std::endl;

	int n{ 1 };		//C++11 �ʱ�ȭ
	int x[1]{ 13 };	// �迭�� ����

	auto a{ 1 };	//�迭? int?
}