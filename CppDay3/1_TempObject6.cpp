#include <iostream>

struct Base
{
	int value = 10;
};

struct Derived : public Base
{
	int value = 20;			// C++11은 이렇게 사용가능
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl;		// 20

	std::cout << d.Base::value << std::endl;					// 10
	std::cout << (static_cast<Base>(d)).value << std::endl;		// 10		Base의 임시객체를 만들어서 Base의 value만 담을 수 있다. 임시객체 Base의 value값.
	std::cout << (static_cast<Base&>(d)).value << std::endl;	// 10

	//(static_cast<Base>(d)).value = 20;		// error 임시객체는 lvalue가 될 수 없다.
	(static_cast<Base&>(d)).value = 20;

	int n = 3;
	//n++ = 5;	// ? int temp = n; n += 1; return temp; 임시객체가 리턴되므로 error
	++n = 5;	// ? n += 1; return n;	// ok..
	
}