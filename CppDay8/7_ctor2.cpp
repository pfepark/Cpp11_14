// 7_������ ���2
#include <iostream>

class Base
{
	int data;
public:
	Base(int a) : data(a) {}
};

class Derived : public Base
{
public:
	using Base::Base;	// �θ��� �����ڸ� ��ӵǰ� �ش޶�. C++11�� ������ ���
	//Derived(int a) : Base(a) {}
};

int main()
{
	Derived d(10);
}