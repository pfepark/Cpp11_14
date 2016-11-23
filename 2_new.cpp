#include "stdafx.h"

#include <iostream>

// 2_new.cpp
// new 정확한 동작 방식
// 1. operator new() 함수를 사용해서 메모리 할당
// 2. 1이 성공하고 사용자 타입이면 생성자 호출
// 3. 메모리 주소를 해당 타입으로 캐스팅해서 리턴
class Point
{
	int x, y;

public:
	Point() { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// 생성자 호출없이 메모리만 할당하는 코드.
	Point* p1 = static_cast<Point*>(operator new(sizeof(Point)));

	operator delete(p1);
	//Point* p1 = new Point();	// new는 keyword로 3가지 일을 한다.
	//delete p1;
}