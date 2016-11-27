// 3_����ǥ����7

#include <iostream>

int g = 0;

int main()
{
	int v1 = 10;
	int v2 = 10;

	auto f1 = [](int a) { return a + g; };	// �������� ���. ok

	//auto f2 = [](int a) { return a + v1 + v2; };	// �������� ���. error
	
	// [=] : acapture variable by value
	//auto f2 = [=](int a) { return a + v1 + v2; };	// ok
	//auto f3 = [=](int a) { v1 = 20; };	// error. ����� �ȵ�


	//-----------------------------------------------------
	//auto f4 = [=](int a) { v1 = 20;  return a + v1 + v2; };	// error
	// mutable ���� : () �����ڸ� ���� �Լ��� ����� �޶�� �ǹ�.
	auto f4 = [=](int a) mutable { v1 = 20;  return a + v1 + v2; };	// ok

	f4(0);	// v1 = 20�� ����Ǿ����� ���纻 ����
	std::cout << v1 << std::endl;	// 10

	std::cout << sizeof(f4) << std::endl;	// 8. �Ʒ����� �ɹ����� int�� 2��.

	// �� ������ ��Ȯ�� ����!! 35page
	/*
	class LambdaClass
	{
		int v1;
		int v2; //���������� ���� ĸ��(����)�ϱ� ���� �ɹ� ����

	public:
		LambdaClass(int a, int b) : v1(a), v2(b) {}
		inline int operator()(int a) const	// ��� �Լ��̴�!!!!
		{
			return a + v1 + v2;
		}
	};

	auto f4 = LambdaClass(v1, v2);	//���������� Ŭ������ü(���ٰ� ����� �ӽð�ü)�� ����
	*/
}