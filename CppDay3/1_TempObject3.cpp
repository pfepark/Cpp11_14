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
};

// 임시객체와 함수 인자
void foo(const Point& p)
{

}

int main()
{
	//Point p(1, 2);
	//foo(p);

	foo(Point(1, 2));	// 임시객체에 의한 함수인자 전달.
						// 단, foo에서는 반드시 cosnt &로 받아야 한다.

	std::cout << "----------" << std::endl;
}
