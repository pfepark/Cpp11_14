#include <iostream>

struct Base
{
	int value = 10;
};

struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl;

	std::cout << ((Base)d).value << std::endl;		// 멤버의 이름이 같을 때 부모 맴버 접근

	//((Base)d).value = 30;	// 값 캐스팅은 임시객체 생성이다. 임시객체는 lvalue가 될 수 없다. error
	((Base&)d).value = 30;	// ok
	(static_cast<Base&>(d)).value = 30; // good code

}