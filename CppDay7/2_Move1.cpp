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

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
};

int main()
{
	Cat c1("NABI");
	Cat c2 = c1;	// runtime error : 깊은 복사 구현 필요
}