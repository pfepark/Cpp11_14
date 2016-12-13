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

	// 소유권 이전의 복사 생성자
	Cat(Cat& c)		// 주의 : const가 없다.
	{
		name = c.name;

		c.name = 0;
	}
};

int main()
{
	Cat c1("NABI");
	Cat c2 = c1;	// 깊은 복사.
}