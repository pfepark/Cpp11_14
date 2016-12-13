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

	// C++ 11 : 복사 생성자와 Move 생성자를 모두 만들어 사용하자.
	Cat(const Cat& c)
	{
		std::cout << "copy ctor" << std::endl;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	//Cat(Cat& c)	// 이렇게 만들면 Cat c2 = c1; 이 복사 생성자가 아닌 Move를 호출하게 된다.
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
	Cat c2 = c1;	// 반드시 복사 생성자를 호출해야 한다.
	//Cat c3 = static_cast<Cat&&>(c1);	// move 생성자 호출, c1은 xvalue가 된다. expired value.

	Cat c3 = std::move(c1);	// 위와 동일한 코드입니다. move가 내부적으로 캐스팅수행.

	Cat c4 = Cat("AAAh");		// 복사되는게 좋을까? Move되는게 좋을까?
								// 임시객체이므로 복사보다 자원 전달이 좋다.
								// 임시객체는 rvalue이므로 move 생성자 호출.
}