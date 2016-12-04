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


int main()
{
	Point p(1, 2);

	Point* p1 = &p;				// ok
	//Point* p2 = &Point(1, 2);	// error. 임시 객체는 주소연산자로 주소를 구할 수 없다. 
	// VS에서 확장 문법을 사용중이므로 (프로젝트 - 속성 - C/C++ - 언어 - 언어 확장 사용 안함 예) 처리가 필요.

	p.x = 10;				// ok
	//Point(1, 2).x = 10;	// error 임시 객체는 lvalue가 될 수 없다. ( =의 왼쪽에 올 수 없다.)

	Point& r1 = p;				// ok
	//Point& r2 = Point(1, 2);	// error. 임시객체는 참조할 수 없다.

	const Point& r3 = Point(1, 2);	// ok.. 임시객체라도 상수 참조는 가능하다.
									// 단, 상수성이 추가되게 된다.
									// r3가 파괴될 때까지 임시객체는 살아 있게된다.

	// C++11에서는 상수성이 추가되지 않고 임시객체를 가르키고 싶었다.
	Point&& r4 = Point(1, 2);	// ok!

	return 0;
}
