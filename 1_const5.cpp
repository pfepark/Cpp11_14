#include "stdafx.h"

#include <iostream>

// 상수 맴버 함수 - C++98 문법이야기

class Point
{
public:
	int x = 0, y = 0; // C++11 부터 이렇게 사용가능

	void set(int a, int b) { x = a; y = b; }
	void print() const	// 상수 맴버 함수.
	{
		// 함수안에 맴버변수는 상수 취급
		//x = 10;	// error
		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
	const Point p;
	p.x = 10;		// error. p는 상수이다.
	p.set(10, 20);	// error.
	p.print();		// 호출될 수 있게 하려면 print()는 상수 함수이어야 한다.
					// "상수객체는 상수 함수만 호출할 수 있다." 컴파일러 입장에선 선언부만 보기에..
}