// "3����"
// 1_�ӽð�ü.cpp - ���� 1-6 rvalue.

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
	//Point* p2 = &Point(1, 2);	// error. �ӽ� ��ü�� �ּҿ����ڷ� �ּҸ� ���� �� ����. 
	// VS���� Ȯ�� ������ ������̹Ƿ� (������Ʈ - �Ӽ� - C/C++ - ��� - ��� Ȯ�� ��� ���� ��) ó���� �ʿ�.

	p.x = 10;				// ok
	//Point(1, 2).x = 10;	// error �ӽ� ��ü�� lvalue�� �� �� ����. ( =�� ���ʿ� �� �� ����.)

	Point& r1 = p;				// ok
	//Point& r2 = Point(1, 2);	// error. �ӽð�ü�� ������ �� ����.

	const Point& r3 = Point(1, 2);	// ok.. �ӽð�ü�� ��� ������ �����ϴ�.
									// ��, ������� �߰��ǰ� �ȴ�.
									// r3�� �ı��� ������ �ӽð�ü�� ��� �ְԵȴ�.

	// C++11������ ������� �߰����� �ʰ� �ӽð�ü�� ����Ű�� �;���.
	Point&& r4 = Point(1, 2);	// ok!

	return 0;
}
