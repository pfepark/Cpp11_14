#include <iostream>

struct Base
{
	int value = 10;
};

struct Derived : public Base
{
	int value = 20;			// C++11�� �̷��� ��밡��
};

int main()
{
	Derived d;
	std::cout << d.value << std::endl;		// 20

	std::cout << d.Base::value << std::endl;					// 10
	std::cout << (static_cast<Base>(d)).value << std::endl;		// 10		Base�� �ӽð�ü�� ���� Base�� value�� ���� �� �ִ�. �ӽð�ü Base�� value��.
	std::cout << (static_cast<Base&>(d)).value << std::endl;	// 10

	//(static_cast<Base>(d)).value = 20;		// error �ӽð�ü�� lvalue�� �� �� ����.
	(static_cast<Base&>(d)).value = 20;

	int n = 3;
	//n++ = 5;	// ? int temp = n; n += 1; return temp; �ӽð�ü�� ���ϵǹǷ� error
	++n = 5;	// ? n += 1; return n;	// ok..
	
}