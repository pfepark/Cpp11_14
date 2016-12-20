// 7_생성자 상속2
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
	using Base::Base;	// 부모의 생성자를 상속되게 해달라. C++11의 생성자 상속
	//Derived(int a) : Base(a) {}
};

int main()
{
	Derived d(10);
}