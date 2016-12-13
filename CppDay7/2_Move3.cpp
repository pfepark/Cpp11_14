// 2_move

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Cat
{
	char* name;
public:
	Cat(const char* s)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}

	~Cat()
	{
		delete[] name;
	}

	// C++ 11 : ���� �����ڿ� Move �����ڸ� ��� ����� �������.
	Cat(const Cat& c)
	{
		std::cout << "copy ctor" << std::endl;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	//Cat(Cat& c)	// �̷��� ����� Cat c2 = c1; �� ���� �����ڰ� �ƴ� Move�� ȣ���ϰ� �ȴ�.
	Cat(Cat&& c)
	{
		std::cout << "move ctor" << std::endl;
		name = c.name;

		c.name = 0;
	}
};

int main()
{
	Cat c1("NABI");
	Cat c2 = c1;	// �ݵ�� ���� �����ڸ� ȣ���ؾ� �Ѵ�.
	//Cat c3 = static_cast<Cat&&>(c1);	// move ������ ȣ��, c1�� xvalue�� �ȴ�. expired value.

	Cat c3 = std::move(c1);	// ���� ������ �ڵ��Դϴ�. move�� ���������� ĳ���ü���.

	Cat c4 = Cat("AAAh");		// ����Ǵ°� ������? Move�Ǵ°� ������?
								// �ӽð�ü�̹Ƿ� ���纸�� �ڿ� ������ ����.
								// �ӽð�ü�� rvalue�̹Ƿ� move ������ ȣ��.
}