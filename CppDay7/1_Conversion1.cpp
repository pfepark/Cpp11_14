// 7일차
// conversion

#include <iostream>

// Point => int : 변환연산자가 필요. operator int()
// int => Point : 변환생성자가 필요. Point(int) 생성자.
class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) : x(a), y(b) {}

	// 변환 생성자 : 인자가 한개인 생성자
	//				다른 타입이 객체로 암시적 변환 되게 한다.
	Point(int a) : x(a), y(0) {}

	// 변환 연산자 함수
	// 특징 : 리턴타입을 표시 하지 않는다.
	operator int() { return x; }
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n1 = 0;

	int n = p2;	// p2.operator int() 함수가 있으면 된다.
	p2 = n1;		// n1.operator Point() 함수가 있으면 되는데...
					// n1은 객체가 아니다.
}