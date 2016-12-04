// "3일차"
// 1_임시객체.cpp - 교재 1-6 rvalue.

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}

	~Point()
	{
		std::cout << "~Point()" << std::endl;
	}

	Point(const Point& p)
	{
		std::cout << "copy ctor" << std::endl;
	}
};

// 임시객체와 함수 리턴

Point p(0, 0);		// 전역 변수

//Point foo()		// 값리턴 : 임시객체가 리턴된다.
Point& foo()		// 참조리턴 : 리턴용 임시객체를 만들지 말라는 의미.
{						// 주의, 지역변수는 참조리턴하면 안된다.
	return p;
}

int main()
{

	foo().x = 10;		// 

	std::cout << p.x << std::endl;
}
