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

	std::cout << ((Base)d).value << std::endl;		// ����� �̸��� ���� �� �θ� �ɹ� ����

	//((Base)d).value = 30;	// �� ĳ������ �ӽð�ü �����̴�. �ӽð�ü�� lvalue�� �� �� ����. error
	((Base&)d).value = 30;	// ok
	(static_cast<Base&>(d)).value = 30; // good code

}