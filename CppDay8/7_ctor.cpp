// 7_생성자 상속
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
	// 부모의 함수를 상속받으려면..(C++ 98 문법)
	// ARM 책 (Annoted Reference Manual) 읽어보세요.
	//using Base::foo;

	// 자식에 동일한 이름의 함수가 있으면 부모의 함수는 상속되지 않는다.
	void foo(int) { std::cout << "int" << std::endl; }
};

int main()
{
	Derived d;
	d.foo(3.4);		// 결과 예측해보세요. int
	//d.foo(1, 1);	// error
}