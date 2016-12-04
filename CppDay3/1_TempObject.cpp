// "3일차"
// 1_임시객체.cpp - 교재 1-6 rvalue.

#include <iostream>

class Point
{
	int x, y;
public:
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
	//Point p(1, 2);	// 이름 있는 객체.. 블럭({})의 끝에서 소멸된다.

	// unnamed object
	//Point(1, 2);	// 클래스 이름() : 임시 객체, 소멸자가 불리는 시점은 세미콜론;을 만났을때. 이름이 없는 객체이므로 바로 파괴

	Point(1, 2), std::cout << "X" << std::endl;		// Point() X ~Point() 의 결과가 출력됨.

	std::cout << "------------" << std::endl;

	return 0;
}
