#include "stdafx.h"

#include <iostream>

// malloc	: 메모리 할당
// new		: 객체 생성 (메모리 할당 + 생성자 호출) -> 생성자 호출이 더 큰일...여러가지 일을 생성자에서 할 수 있다.

// new Point : 새로운 메모리에 객체를 생성해 달라
// new(&p) Point : 이미 존재하는 메모리에 (&p) 객체를 생성해 달라.

class Point
{
	int x, y;

public:
	Point() { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 중요!
// Placement new (위치 지정 new) : 생성자를 명시적으로 호출하기 위해 만든 것.
/* 이미 표준에 있으므로 아래 코드로 placement new 를 호출하면 명시적으로 생성자를 호출할 수 있다. (C++ 98)
void* operator new(size_t sz, Point* p)
{
	return p;
}
*/

int main()
{
	Point p;

	// new Point;	// 인자가 1개인 operator new() 호출

	new (&p) Point;	// 위의 operator new() 호출
					// new의 3가지 일중 첫번째 메모리 할당은 성공한 것으로(그 주소 그대로 리턴, 0이 아님)
					// 보고 이어서 생성자를 호출한다. 그 다음은 캐스팅 하겠지...

	//p.Point();	// error 생성자는 명시적 호출안됨.
	p.~Point();		// ok. 소멸자는 명시적 호출가능.
}