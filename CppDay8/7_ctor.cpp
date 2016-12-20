// 7_������ ���
#include <iostream>

class Base
{
public:
	void foo(double d) { std::cout << "double" << std::endl; }
	void foo(int, int) { std::cout << "int, int" << std::endl; }
};

class Derived : public Base
{
public:
	// �θ��� �Լ��� ��ӹ�������..(C++ 98 ����)
	// ARM å (Annoted Reference Manual) �о����.
	//using Base::foo;

	// �ڽĿ� ������ �̸��� �Լ��� ������ �θ��� �Լ��� ��ӵ��� �ʴ´�.
	void foo(int) { std::cout << "int" << std::endl; }
};

int main()
{
	Derived d;
	d.foo(3.4);		// ��� �����غ�����. int
	//d.foo(1, 1);	// error
}