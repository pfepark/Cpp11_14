#include <iostream>

void goo(int a, int b)
{
	int c;
	auto f = [=]() {return a + b + c; };	//ok

	std::cout << sizeof(f) << std::endl;	// 12
}

// 35page
class Test
{
	int data;
public:
	void foo()	// void foo(Test* this)
	{
		// �ɹ� data����
		//auto f = [](int a) { return data; };	// error
		//auto f = [data](int a) { return data; };	// error. data�� �������� �ƴ�

		//auto f = [=](int a) { return this->data; };	// ok ��� �������� �����ε� ���������� this ĸ��.
		//auto f = [this](int a) { return data; };	// ok.. this�� ĸ��

		auto f = [=](int a) { data = 30; };	// �ɱ��?? ��.
		// this ĸ�Ľ� �����Ϸ��� �����ϴ� �ڵ带 �����غ�����

		f(0);	// �ɹ� ���� data ���� ����

		std::cout << data << std::endl;	// 30

		auto f1 = [this](int a) { data = 30; };	// ���� ���� ����
		// C++17 ���ʹ� *this ĸ�� ����
		//auto f2 = [*this](int a) mutable { data = 30; };	// ���纻 ����?
	}
};


int main()
{
	Test t;
	t.foo();	// foo(&t)
}